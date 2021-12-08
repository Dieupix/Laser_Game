#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED


#include"miroir.h"
#include"ground.h"

class JEU
{
public :
    JEU() ;
    ~JEU() = default ;
    void ajoutMiroir(const Miroir&) ;
    void supprimeMiroir(const Miroir& ) ;
    void run() ;
    void read() ;
    void savegarder() ;
    void start() ;
private :
    ground d_terrin ;

};

#endif // JEU_H_INCLUDED



#endif // JEU_H_INCLUDED
