#ifndef MIROIR_H_INCLUDED
#define MIROIR_H_INCLUDED

#include "objet.h"

class laser ;
class miroir : public objet
{

    public:


        enum sens : bool  {
            basGauche_hautDroit,
            hautGauche_basDroit
        };

    miroir( const point& position, sens Smirroir ) ;
    ~miroir()  = default ;
     virtual void print(std::ostream& ost) const override;
     sens  getSens() const ;
       void changeDirectionLaser(laser& ) const ;
       bool estTouchee(laser& ) const;
     private:

       sens d_sens;

        bool  d_miroirtouchee;

};



#endif // MIROIR_H_INCLUDED
