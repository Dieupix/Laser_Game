#include "jeu.h"
#include "ground.h"
#include <fstream>

using std::cout; using std::ofstream;
using std::endl; using std::string;
using std::fstream;


Game::Game(const ground& terrain) : d_terrain{terrain.getPosition(), 0 , 0 ,
                                                terrain.getNbCellsWidth(), terrain.getNbCellsHeight()}
{}

void Game::addMirror(const mirror& m)
{
    d_terrain.addObjectAt(std::make_unique<mirror>(m), m.getPosition().x(),m.getPosition().y());
}
void Game::removeMirror(const mirror& m)
{

}
void Game::run()
{

}
void Game::read()
{

}
void Game::save(std::string nameFile) const
{

        if ( nameFile == "")
            throw "Chemin vide !";

        fstream file_out;

    file_out.open(nameFile);

    if (!file_out.is_open()) {
        cout << "failed to open " << nameFile << '\n';
    } else {
       d_terrain.print(file_out) ;
    }

}
void Game::start()
{

}
