#include"cible.h"
#include"laser.h"
#include "objet.h"

// ---------- Constructors ----------
  /**
         * @brief Constructor with a position
         * @param[in] position : The initial position of the cible
         * @return Creates a cible with its parameters
         */
    cible::cible(const point& position) : objet{position}
    {

    }

// ---------- End of constructors ----------

// ---------- Setters ----------
 /**
         * @brief Setter function for the cible
         *
         * @param[in] cible : The new cible
         * @return Returns nothing
         */
    void cible::setCible(const cible& C)
    {
        setPoint( C.getPoint() ) ;
    }
// ---------- End of setters ----------


// ----------  Getters ----------
/**
         * @brief Constant getter function for the cible
         *
         * @return Returns the cible
         */
    cible cible::getCible() const
    {
        return *this ;
    }
// ---------- End of Getters -----------------------------

// ---------- Functions moveCible ------------------------
        /**
         * @brief A function that moves the cible
         * @details This function moves the  position of the cible
         * to another point
         * @param[in] point : the new position
         * @return Returns nothing
         */
     void cible::moveCible(point& p)
     {
         objet::shift(p) ;
     }
// ---------- End of moveCible  -----------------------------
// ---------- Functions moveCible ------------------------
      /**
         * @brief A function that moves the cible
         * @details This function moves the position of the target
         * to another coordinate
         * @param[in] x : the new X
         * @param[in] y : the new Y
         * @return Returns nothing
         */
    void cible::moveCible(double& x , double& y )
        {
         objet::shift(x, y) ;
        }
// ---------- End of moveCible  -----------------------------
// ---------- Functions isAffected ------------------------
      /**
         * @brief A function that moves the cible
         * @details This function test if the target is hit by the laser
         * @param[in] laser
         * @return  true if the cible is hit by the laser
         * @return false if not
         */
    bool cible::isAffected(laser& L ) const
    {
        return(L.getPoint() == getPoint() ) ;
    }

// ---------- End of isAffected  -----------------------------


/**
   * @brief Print cible
   * @param[in] ost :
*/
void cible::print(std::ostream& ost) const
{
   getPoint().print(ost);
}
