#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED


#include"miroir.h"
#include"ground.h"

class Game
{
public :
    Game(const ground& terrain);
    ~Game() = default ;
    void addMirror(const miroir& m) ;
    void removeMirror(const miroir& m) ;
    void run() ;
    void read() ;
    void save() ;
    void start() ;
private :
    ground d_terrain ;

};

#endif // JEU_H_INCLUDED


