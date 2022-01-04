#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "mirror.h"
#include "ground.h"
#include "viewerOnTerminal.h"

#include <fstream>
#include <string>

using std::invalid_argument;
using std::ifstream;
using std::ofstream;
using std::string;

class game
{
public :
    game();
    //TODO - Should we not use a default constructor and create a function to load a ground in the game?
    //TODO - Because read() allows the game to load a ground only from a file
    game(const ground& terrain, int nb_mirror_max, int nb_mirror_installed = 0);
    ~game() = default ;
    void addMirror(const point& p, const sens& s) ;
    void loadGround(const ground& terrain);
    void read(const string& nameFile) ;
    void removeMirror(const point& p) ;
    void run() ;
    void save(const string& nameFile) const ;
private :
    ground d_terrain ;
    int d_nb_mirror_max;
    int d_nb_mirror_installed;

    sens askSens();
    point askPosition();

    void start() ;
};

#endif // GAME_H_INCLUDED


