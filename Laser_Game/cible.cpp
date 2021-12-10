#include"cible.h"
#include"laser.h"
#include "object.h"

// ---------- Constructors ----------
  /**
         * @brief Constructeur avec position
         * @param[in] position : La position initial de la cible
         * @return Crée une cible avec une position
         */
    cible::cible(const point& position) : object{position}, d_affected{false}
    {

    }

// ---------- End of constructors ----------

// ---------- Setters ----------

// ---------- End of setters ----------

// ----------  Getters ----------

// ---------- End of Getters -----------------------------

// ---------- Functions isAffected ------------------------
      /**
         * @brief A function that moves the cible
         * @details This function test if the target is hit by the laser
         * @param[in] laser
         * @return  true if the cible is hit by the laser
         * @return false if not
         */
    bool cible::isAffected(laser& L )
    {

         d_affected = (*this == L );

        return(d_affected ) ;
    }

// ---------- End of isAffected  -----------------------------


/**
   * @brief Print cible
   * @param[in] ost :
*/

void cible::print(std::ostream& ost) const
{
    ost << "Cible[position" << getPosition() <<", ";
    if( d_affected )
        ost<<"est touchée par un laser" ;
    else
         ost<<"n'est pas touchée par un laser" ;


 ost<<"]";
}

bool cible::operator==(const object& a ) const
{
     return getPosition() == a.getPosition() ;

}
bool cible::operator!=(const object& a ) const
{
    return getPosition() == a.getPosition() ;

}

