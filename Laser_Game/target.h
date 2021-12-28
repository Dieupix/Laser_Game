#ifndef CIBLE_H_INCLUDED
#define CIBLE_H_INCLUDED

#include "object.h"

class laser ;

class target : public object
{
public :
    /** @brief constructor of a target
    *
    * @param[in] have a position
    *
    */
    target(const point& position) ;

    // Destructor
    /**
     * @brief Default-implemented destructor
     * @details Destroys the target.
     */
    virtual ~target() = default;


    /**
       * @brief A function that moves the target
       * @details This function test if the target is hit by the laser
       * @param[in] Laser
       * @return  True if the target is hit by the laser
       * @return False if not
       */

    bool isAffected(laser& ) ;

    /**
       * @brief Print a  target
       * @param[in] ost :
    */
    virtual void print(std::ostream& ost) const override;

    /**
         * @brief Binary operator == : constant
         * @details Tests if all the member variables of the
         * target and an object are equals.
         *
         * @param[in] : The object to test with
         * @return Returns true if both of  are equals, else false
         */
    bool operator==(const object& ) const ; ///@TODO - Meriem : useless because the target and the laser are both objects


    /**
     * @brief Binary operator != : constant
     * @details Tests if all the member variables of the
     * target and an object are equals..
     *
     * @param[in] : The laser to test with
     * @return Returns true if both are different, else false
     */
    bool operator!=(const object& ) const ; ///@TODO - Meriem : useless because the target and the laser are both objects


private :
    /**
    * @brief Boolean that says whether or
    * not the target is hit by a laser
    */
    bool d_affected ;

};


#endif // CIBLE_H_INCLUDED
