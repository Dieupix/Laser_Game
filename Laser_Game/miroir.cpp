#include"miroir.h"
#include "laser.h"
#include "object.h"


// ---------- Constructeur-------------------------------
/**
       * @brief Constructeur avec un sens
       * @param[in] sens : Le sens initial du miroir
       * @return Crée un miroir avec un sens donnée en paramètre
       */

miroir::miroir(const point& position ,sens Smirroir ) : object{position} , d_sens{basGauche_hautDroit},
                                  d_miroirtouchee {false}
{

}
// ---------- Fin Constructeur-------------------------------


// ----------------------Print -------------------------------
/**
       * @brief Afficher la position d'un mirroir
       * @param[in] ost : un flux de sortie
       * @return Affiche la position du miroir
       */
/*
void miroir::print(std::ostream& ost) const
{
    getPosition().print(ost);
    // est ce qu il faut afficher dans quel sens ?
}
*/
// ---------------- Fin Print -------------------------------

// ----------------------getSens -------------------------------
/**
       * @brief getter du sens du miroir
       * @return le sens du miroir courant
       */
miroir::sens  miroir::getSens() const
{
    return d_sens ;
}

// ----------------------Fin getSens -------------------------------

// ---------------------- changeDirectionLaser -------------------------------
/**
       * @brief Méthode qui permet de changer la direction d'un laser
       * si il a touché le miroir
       * @param[in] laser : un laser
       * @return change la direction du laser
       */
void miroir::changeDirectionLaser(laser& l ) const
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

}
// ---------------------- Fin changeDirectionLaser -------------------------------

// ---------------------- estTouchee -------------------------------
/**
       * @brief Méthode qui permet de verifier si le laser a touché le miroir
       * @param[in] laser : un laser
       * @return  True : si il est touché
       * @return False : si il est pas touché
       */
bool miroir::estTouchee(laser& L ) const
{
    bool touchee = (L.getPosition() == getPosition() ) ;
    if (touchee)
    {
        changeDirectionLaser(L) ;

    }

    return(touchee ) ;
}
// ---------------------- Fin estTouchee ------------------------------
