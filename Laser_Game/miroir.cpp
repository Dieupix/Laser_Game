#include"miroir.h"
#include "laser.h"
#include "objet.h"

// ici je sais pas trop !!  par defaut je le mets BG_HD
 miroir::miroir(sens Smirroir ) : d_sens{basGauche_hautDroit} ,
 d_miroirtouchee {false}
 {
 }

  void miroir::print(std::ostream& ost) const
  {
      getPosition().print(ost);
  }

void miroir::changeDirectionLaser(laser& l ) const
{
          /*  RIGHT,
            UP,
            LEFT,
            DOWN*/

      switch ( d_sens )
      {
         case basGauche_hautDroit :
            if( (l.getDirection() == laser::directions::UP ) || (l.getDirection() == laser::directions::DOWN)  )
                l.turnRight() ;
            else l.turnLeft() ;
            break;
         case  hautGauche_basDroit :
             if( (l.getDirection() == laser::directions::LEFT ) || (l.getDirection() == laser::directions::RIGHT)  )
                l.turnLeft() ;
            else l.turnRight() ;
            break;



      }

}
bool miroir::estTouchee(laser& L ) const
{
    bool touchee = (L.getPosition() == getPosition() ) ;
        if (touchee)
        {
            changeDirectionLaser(L) ;

        }

        return(touchee ) ;
}
