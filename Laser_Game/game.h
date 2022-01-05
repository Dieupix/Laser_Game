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
    game(const ground& terrain);
    ~game() = default ;

    void addMirror(const point& p, const sens& s) ;
    int score() const;
    void loadGround(const ground& terrain);
    void read(const string& nameFile) ;
    void removeMirror(const point& p) ;
    void run();
    void win() const;
    void save(const string& nameFile) const ;
private :
    ground d_terrain ;

    point reverse(const point& p);
    sens askSens();
    point askPosition();
    void invertDirection(laser& l) const;

    void start() ;
};

#endif // GAME_H_INCLUDED


