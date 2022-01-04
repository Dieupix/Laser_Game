#ifndef CIBLE_H_INCLUDED
#define CIBLE_H_INCLUDED

#include "object.h"

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

    bool isAffected() const;
    void setAffected(bool b);

    virtual unique_ptr<object> clone() const override;
    virtual void collide(laser& l);

    /**
       * @brief Print a  target
       * @param[in] ost :
    */
    virtual void print(std::ostream& ost) const override;
    virtual string toString() const override;


private :
    /**
    * @brief Boolean that says whether or
    * not the target is hit by a laser
    */
    bool d_affected ;

};


#endif // CIBLE_H_INCLUDED
