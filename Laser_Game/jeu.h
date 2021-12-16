#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED


#include"miroir.h"
#include"ground.h"

class Game
{
public :
    Game(const ground& terrain);
    ~Game() = default ;
    void addMirror(const mirror& m) ;
    void removeMirror(const mirror& m) ;
    void run() ;
    void read() ;
    void save(std::string nameFile) const ;
    void start() ;
private :
    ground d_terrain ;

};

#endif // JEU_H_INCLUDED


