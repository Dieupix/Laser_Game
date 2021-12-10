#include "jeu.h"
#include "ground.h"

Game::Game(const ground& terrain) : d_terrain{terrain.getPosition(), 0 , 0 ,
                                                terrain.getNbCellsWidth(), terrain.getNbCellsHeight()}
{}

void Game::addMirror(const miroir& m)
{
    d_terrain.addObjectAt(std::make_unique<miroir>(m), m.getPosition().x(),m.getPosition().y());
}
void Game::removeMirror(const miroir& m)
{

}
void Game::run()
{

}
void Game::read()
{

}
void Game::save()
{

}
void Game::start()
{

}
