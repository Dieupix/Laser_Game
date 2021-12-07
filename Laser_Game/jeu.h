#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include"object.h"
#include"ground.h"

class JEU
{
public :
    JEU() ;
    ~JEU() = default ;
    void ajoutObjet(const object&) ;
    void supprimeObjet(const point& ) ;
    void deplaceObjet( object& ) ;
    void run() ;
private :
    ground d_terrin ;

};

#endif // JEU_H_INCLUDED
