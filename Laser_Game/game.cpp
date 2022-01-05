#include "game.h"

game::game(unique_ptr<viewer> viewer) : d_terrain{}, d_viewer{move(viewer)}
{}

game::game(const ground& terrain, unique_ptr<viewer> viewer) : d_terrain{terrain}, d_viewer{move(viewer)}
{}

void game::addMirror(const point& p, const sens& s)
{
    auto i = p.x(), j = p.y();
    if(i >= 0 && j >= 0 && i < d_terrain.getNbCellsHeight() && j < d_terrain.getNbCellsWidth() )
    {
        auto obj = d_terrain.getObjects()[i][j].get();
        point pMirror = reverse(p) + d_terrain.getPosition();
        if(obj)
        {
            if(dynamic_cast<mirror*>(obj))
            {
                d_terrain.removeObjectAt(i, j);
            }
        }

        d_terrain.addObjectAt(make_unique<mirror>(pMirror, s), i, j);
    }
    else
    {
        cerr << "ERROR: the position is not on the ground" << endl;
    }
}

void game::removeMirror(const point& p)
{
    auto i = p.x(), j = p.y();
    if(i >= 0 && j >= 0 && i < d_terrain.getNbCellsHeight() && j < d_terrain.getNbCellsWidth())
    {
        auto obj = d_terrain.getObjects()[i][j].get();
        if(obj)
        {
            if(dynamic_cast<mirror*>(obj))
            {
                d_terrain.removeObjectAt(i, j);
            }
        }
    }
}

point game::reverse(const point& p)
{
    return {p.y(), p.x()};
}

point game::askPosition()
{
    point p;
    cout<<"Saisir la position : ";
    cin>>p;
    return p;
}

sens game::askSens()
{
    char inclination_mirror;
    cout<<"Saisir l'inclinaison du miroir ( / ou \\ ) : ";
    cin>>inclination_mirror;
    sens s;
    switch(inclination_mirror)
    {
        case('/') :
        { s = basGauche_hautDroit;break;}
        case('\\') :
        { s = hautGauche_basDroit;break;}
    }
    return s;
}

void game::invertDirection(laser& l) const
{
    switch(l.getDirection())
    {
    case UP:
        {
            l.setDirection(DOWN);
            break;
        }
    case DOWN:
        {
            l.setDirection(UP);
            break;
        }
    default:
        {
            break;
        }
    }
}

void game::run()
{
    int choix, max = 3;
    point p;
    do
    {
        cout<<"0 - Tirer le laser"<<endl;
        cout<<"1 - Ajouter un miroir"<<endl;
        cout<<"2 - Enlever un miroir"<<endl;
        cout<<"3 - Afficher le terrain"<<endl;

        cout << endl;

        cout << "> ";

        cin>>choix;

        switch(choix)
        {
            case 0 :
                {
                    start();
                    break;
                }
            case 1 :
                {
                    if(d_terrain.getNbOfMirrors() < d_terrain.getNbMirrorMax())
                    {
                        sens s = askSens();
                        p = askPosition();
                        addMirror(p, s);
                    }
                    else cout<<"Le nombre maximum de miroirs a ete atteint"<<endl;
                    break;
                }
            case 2 :
                {
                    p = askPosition();
                    removeMirror(p);
                    break;
                }
            case 3 :
                {
                    d_viewer->printGround(d_terrain);
                    break;
                }
            default:
                {
                    cerr << "Erreur, entrez un nombre entre 0 et " << max << endl;
                    break;
                }
        }
        cout << endl;
    }
    while(choix != 0);
}
void game::read(const string& nameFile)
{
    if ( nameFile == "")
        throw invalid_argument("Chemin vide !");

    ifstream file_in;
    file_in.open(nameFile);

    if(!file_in.is_open())
    {
        cout << "failed to open " << nameFile << '\n';
    }
    else
    {
        d_terrain.loadFrom(file_in);
    }
}
void game::save(const string& nameFile) const
{

        if ( nameFile == "")
            throw invalid_argument("Chemin vide !");


      ofstream file_out;

    file_out.open(nameFile);


    if (!file_out.is_open()) {
        cout << "failed to open " << nameFile << '\n';
    } else {

       d_terrain.saveIn(file_out) ;
    }
}

void game::start()
{
    auto shooter = d_terrain.getShooter();
    auto l = shooter.tire();
    invertDirection(l);

    point pos = reverse(l.getPosition() - d_terrain.getPosition());
    unsigned x = pos.x(), y = pos.y();

    d_terrain.addObjectAt(make_unique<object>(l), x, y);

    while(l.getIsAlive())
    {
        l.moveByStep();
        pos = reverse(l.getPosition() - d_terrain.getPosition());
        x = pos.x();
        y = pos.y();

        unsigned i = 0, j = 0;
        while(i < d_terrain.getNbCellsHeight() and l.getIsAlive())
        {
            while(j < d_terrain.getNbCellsWidth() and l.getIsAlive())
            {
                auto obj = d_terrain.getObjects()[i][j].get();
                if(obj)
                {
                    invertDirection(l);
                    obj->collide(l);
                    invertDirection(l);
                }
                ++j;
            }
            ++i;
            j = 0;
        }

        if(l.getIsAlive())
        {
            d_terrain.addObjectAt(make_unique<laser>(l), x, y);
        }
    }
}

void game::loadGround(const ground& terrain)
{
    d_terrain = terrain;
}
