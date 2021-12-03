#ifndef MIROIR_H_INCLUDED
#define MIROIR_H_INCLUDED

#include "enumTypes.h"
#include "object.h"

using namespace enumTypes;

class laser ;
class miroir : public object
{

    public:

    miroir( const point& position, sens Smirroir ) ;
    ~miroir()  = default ;
     sens  getSens() const ;
       void changeDirectionLaser(laser& ) const ;
       bool estTouchee(laser& ) const;
     private:

       sens d_sens;

        bool  d_miroirtouchee;

};



#endif // MIROIR_H_INCLUDED
