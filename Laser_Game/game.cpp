#include "game.h"

game::game() : d_terrain{}, d_nb_mirror_max{0}, d_nb_mirror_installed{0}
{}

game::game(const ground& terrain, int nb_mirror_max, int d_nb_mirror_installed) :
    d_terrain{terrain}, d_nb_mirror_max{nb_mirror_max}, d_nb_mirror_installed{d_nb_mirror_installed}
{}

void game::addMirror(const point& p, const sens& s)
{
    if(p.x() >= 0 && p.y() >= 0 && p.x() < d_terrain.getNbCellsHeight() && p.y() < d_terrain.getNbCellsWidth() )
    {
        auto obj = d_terrain.getObjects()[p.x()][p.y()].get();
        if(obj)
        {
            if(dynamic_cast<mirror*>(obj))
            {
                d_terrain.addObjectAt(std::make_unique<mirror>(p,s), p.x(),p.y());
                ++d_nb_mirror_installed;
            }
        }
    }
}

void game::removeMirror(const point& p)
{
    if(p.x() >= 0 && p.y() >= 0 && p.x() < d_terrain.getNbCellsHeight() && p.y() < d_terrain.getNbCellsWidth() )
    {
        auto obj = d_terrain.getObjects()[p.x()][p.y()].get();
        if(obj)
        {
            if(dynamic_cast<mirror*>(obj))
            {
                d_terrain.removeObjectAt(p.x(),p.y());
                --d_nb_mirror_installed;
            }
        }
    }
}

point game::askPosition()
{
    point p;
    cout<<"Saisir la position : "<<endl;
    cin>>p;
    return p;
}

sens game::askSens()
{
    int inclination_mirror;
    cout<<"Saisir l'inclinaison du miroir ( 1 pour / ou 2 pour \\ ) : ";
    cin>>inclination_mirror;
    sens s;
    switch(inclination_mirror)
    {
        case(1) :
        { s = basGauche_hautDroit;break;}
        case(2) :
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
    d_terrain.addObjectAt(make_unique<object>(l), l.getPosition().x(), l.getPosition().y());

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
                d_terrain.getObjects()[i][j].get()->collide(l);
                ++j;
            }
            ++i;
        }

        if(l.getIsAlive()) d_terrain.addObjectAt(make_unique<object>(l), l.getPosition().x(), l.getPosition().y());

        v.printGround(d_terrain);

    }
}

void game::loadGround(const ground& terrain)
{
    d_terrain = terrain;
    d_nb_mirror_installed = terrain.getNbOfMirrors();
}
