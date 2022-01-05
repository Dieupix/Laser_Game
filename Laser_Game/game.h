#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "ground.h"
#include "viewerOnTerminal.h"
#include "viewerOnWINBGI.h"

#include <fstream>
#include <string>

using std::invalid_argument;
using std::ifstream;
using std::ofstream;
using std::string;

class game
{
public :
    game(unique_ptr<viewer> = make_unique<viewerOnTerminal>());
    game(const ground&, unique_ptr<viewer> = make_unique<viewerOnTerminal>());

    ~game() = default ;

    void addMirror(const point& p, const sens& s) ;
    void loadGround(const ground& terrain);
    void read(const string& nameFile) ;
    void removeMirror(const point& p) ;
    void run() ;
    void save(const string& nameFile) const ;
private :
    ground d_terrain;
    unique_ptr<viewer> d_viewer;

    point reverse(const point& p);
    sens askSens();
    point askPosition();
    void invertDirection(laser& l) const;

    void start() ;
};

#endif // GAME_H_INCLUDED


