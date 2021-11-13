#ifndef CIBLE_H_INCLUDED
#define CIBLE_H_INCLUDED

#include "objet.h"

class laser ;

class cible : public objet
{
public :

    cible(const point& position) ;
    virtual ~cible() = default;
    void setCible(const cible& C);
    cible getCible() const;
    void moveCible(point&) ;
    void moveCible(double& , double& ) ;
    bool isAffected(laser& ) const;
    virtual void print(std::ostream& ost) const override;


};


#endif // CIBLE_H_INCLUDED
