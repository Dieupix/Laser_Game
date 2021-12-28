#include "game.h"
#include "ground.h"
#include <fstream>

using std::cout;
using std::endl;
using std::invalid_argument;
using std::ofstream;
using std::string;
using std::fstream;


//TODO - We should use the copy constructor instead
game::game(const ground& terrain) : d_terrain{terrain.getPosition(), 0 , 0 ,
                                                terrain.getNbCellsWidth(), terrain.getNbCellsHeight()}
{}

void game::addMirror(const mirror& m)
{
    d_terrain.addObjectAt(std::make_unique<mirror>(m), m.getPosition().x(),m.getPosition().y());
}
void game::removeMirror(const mirror& m)
{

}
void game::run()
{

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
