#include"miroir.h"
#include "laser.h"
#include "object.h"


// ---------- Constructeur-------------------------------


mirror::mirror(const point& position ,sens Smirror) : object{position} , d_sens{basGauche_hautDroit},
                                  d_mirrortouched {false}
{

}
// ---------- Fin Constructeur-------------------------------





// ----------------------getSens -------------------------------

sens  mirror::getSens() const
{
    return d_sens ;
}

// ----------------------Fin getSens -------------------------------

// ---------------------- changeDirectionLaser -------------------------------

void mirror::changeDirectionLaser(laser& l ) const
{
    /*  RIGHT,
      UP,
      LEFT,
      DOWN*/
if ( estTouchee(l) )
   {

   switch ( d_sens )
    {
    case basGauche_hautDroit :
        if( (l.getDirection() == directions::UP ) || (l.getDirection() == directions::DOWN)  )
            l.turnRight() ;
        else l.turnLeft() ;
        break;
    case  hautGauche_basDroit :
        if( (l.getDirection() == directions::LEFT ) || (l.getDirection() == directions::RIGHT)  )
            l.turnLeft() ;
        else l.turnRight() ;
        break;



    }
     }

}
// ---------------------- Fin changeDirectionLaser -------------------------------

// ---------------------- estTouchee -------------------------------

bool mirror::estTouchee(laser& L ) const
{
    bool touchee = (L.getPosition() == getPosition() ) ;
    if (touchee)
    {
        changeDirectionLaser(L) ;

    }

    return(touchee ) ;
}
// ---------------------- Fin estTouchee ------------------------------

void mirror::print(std::ostream& ost) const
{

    ost << "Miroir [position" << getPosition()<<", sens : " ;
    switch(getSens() )
    {
        case sens::basGauche_hautDroit :{
            ost<<"basGauche_hautDroit,";
            break;
        }
        case sens::hautGauche_basDroit :{
            ost<<"hautGauche_basDroit,";
            break ;
        }
    }
    if(d_mirrortouched)
    ost <<" est touchee]" ;
    else
     ost <<" n'est pas touchee]" ;

}


