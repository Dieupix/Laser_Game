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
 /**
         * @brief Setter function for the cible
         *
         * @param[in] cible : The new cible
         * @return Returns nothing
         */
    void cible::setCible(const cible& C)
    {
        setPosition( C.getPosition() ) ;
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
         object::shift(p) ;
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
         object::shift(x, y) ;
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
    bool cible::isAffected(laser& L )
    {
        bool affected = L.getPosition() == getPosition() ;
         d_affected = affected ;

        return(affected ) ;
    }

// ---------- End of isAffected  -----------------------------


/**
   * @brief Print cible
   * @param[in] ost :
*/
/*
void cible::print(std::ostream& ost) const
{
   getPosition().print(ost);
}
*/
