#include "game.h"
#include "ground.h"
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::invalid_argument;
using std::ofstream;
using std::string;
using std::fstream;


//TODO - We should use the copy constructor instead
game::game(const ground& terrain, int nb_mirror_max) : d_terrain{terrain.getPosition(), 0 , 0 ,
                                                terrain.getNbCellsWidth(), terrain.getNbCellsHeight()},
                                                d_nb_mirror_max{nb_mirror_max}
{}

void game::addMirror(const mirror& m)
{
    d_terrain.addObjectAt(std::make_unique<mirror>(m), m.getPosition().x(),m.getPosition().y());
}
void game::removeMirror(const mirror& m)
{
    d_terrain.removeObjectAt(m.getPosition().x(),m.getPosition().y());
}
void game::run()
{
    /*
    d_terrain.print(cout);
    bool stop = false;
    int nb_mirror_installed = 0;
    while(!stop && nb_mirror_installed <= d_nb_mirror_max)
    {
        point p;
        int inclination_mirror;
        cout<<"Saisir la position du miroir et son inclinaison ( 1 pour / ou 2 pour \ ) . Sinon taper '0'"<<endl;
        cin>>p>>inclination_mirror;
        sens s;
        switch(inclination_mirror)
        {
            case(1) :
            { s = basGauche_hautDroit;break;}
            case(2) :
            { s = hautGauche_basDroit;break;}
            case(0) :
            { stop = true;break;}
        }
        if(!stop)
        {
           mirror m{p,s};
           bool is_already_present = false;
           for(int i{0} ; i< d_terrain.getObjects().size() ; ++i)
            {
                if(p == d_terrain.getObjects()[i]->getPosition())
                {
                    is_already_present = true;
                    removeMirror(d_terrain.getObjects()[i]);
                    nb_mirror_installed--;
                }
            }
           if(!is_already_present)
           {
               addMirror(m);
               nb_mirror_installed++;
           }
        }
    }
    */
}
void game::read()
{

}
void game::save(const string& nameFile) const
{

        if ( nameFile == "")
            throw invalid_argument("Chemin vide !");

        //TODO - An ofstream could be better?
        fstream file_out;

    file_out.open(nameFile);

    //TODO - Use the saveIn() function of the ground
    if (!file_out.is_open()) {
        cout << "failed to open " << nameFile << '\n';
    } else {
       d_terrain.print(file_out) ;
    }

}
void game::start()
{

}
