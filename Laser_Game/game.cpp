#include "game.h"

game::game() : d_terrain{}, d_nb_mirror_max{0}, d_nb_mirror_installed{0}
{}

game::game(const ground& terrain, int nb_mirror_max, int d_nb_mirror_installed) :
    d_terrain{terrain}, d_nb_mirror_max{nb_mirror_max}, d_nb_mirror_installed{d_nb_mirror_installed}
{}


int game::getNbMirrorMax() const
{
    return d_nb_mirror_max;
}

void game::setNbMirrorMax(int nbMirrorMax)
{
    d_nb_mirror_max = nbMirrorMax;
}

void game::addMirror(const point& p, const sens& s)
{
    if(p.y() >= 0 && p.x() >= 0 && p.y() < d_terrain.getNbCellsHeight() && p.x() < d_terrain.getNbCellsWidth() )
    {
        auto obj = d_terrain.getObjects()[p.y()][p.x()].get();
        if(obj)
        {
            if(dynamic_cast<mirror*>(obj))
            {
                d_terrain.removeObjectAt(p.y(), p.x());
                d_terrain.addObjectAt(std::make_unique<mirror>(p,s), p.y(),p.x());
            }
        }
        else
        {
            d_terrain.addObjectAt(std::make_unique<mirror>(p,s), p.y(),p.x());
            ++d_nb_mirror_installed;
        }
    }
    else
    {
        cerr << "ERROR: the mirror is not on the ground" << endl;
    }
}

void game::removeMirror(const point& p)
{
    if(p.y() >= 0 && p.x() >= 0 && p.y() < d_terrain.getNbCellsHeight() && p.x() < d_terrain.getNbCellsWidth() )
    {
        auto obj = d_terrain.getObjects()[p.y()][p.x()].get();
        if(obj)
        {
            if(dynamic_cast<mirror*>(obj))
            {
                d_terrain.removeObjectAt(p.y(),p.x());
                --d_nb_mirror_installed;
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
    return reverse(p);
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
                    if(d_nb_mirror_installed < d_nb_mirror_max)
                    {
                        sens s = askSens();
                        p = askPosition();
                        addMirror(p,s);
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
                    viewerOnTerminal v;
                    v.printGround(d_terrain);
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
    cout << shooter << endl;
    cout << l << endl;
    d_terrain.addObjectAt(make_unique<object>(l), l.getPosition().y(), l.getPosition().x());

    viewerOnTerminal v;
    v.printGround(d_terrain);

    while(l.getIsAlive())
    {
        l.moveByStep();

        unsigned i = 0, j = 0;
        while(i < d_terrain.getNbCellsHeight() and l.getIsAlive())
        {
            while(j < d_terrain.getNbCellsWidth() and l.getIsAlive())
            {
                auto obj = d_terrain.getObjects()[i][j].get();
                if(obj)
                {
                    obj->collide(l);
                }
                ++j;
            }
            ++i;
            j = 0;
        }

        if(l.getIsAlive()) d_terrain.addObjectAt(make_unique<laser>(l), l.getPosition().y(), l.getPosition().x());

        v.printGround(d_terrain);

    }

    cout << "LE";
    for(unsigned i = 0; i < 99; ++i)
    {
        cout << "EEEEE";
    }
    cout << "TS GOOOOOOO" << endl;
}

void game::loadGround(const ground& terrain)
{
    d_terrain = terrain;
    d_nb_mirror_installed = terrain.getNbOfMirrors();
}
