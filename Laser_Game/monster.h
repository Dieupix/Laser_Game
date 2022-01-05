#ifndef CIBLE_H_INCLUDED
#define CIBLE_H_INCLUDED
#include "object.h"


class monster : public object
{
public :
    /** @brief constructor of a monster
    *
    * @param[in] have a position
    *
    */
    monster(const point& position , std::string name) ;

    // Destructor
    /**
     * @brief Default-implemented destructor
     * @details Destroys the monster.
     */
    virtual ~monster() = default;
    std::string getName() const ;
    void setName() ;

    /**
       * @brief A function that moves the monster
       * @details This function test if the monster is hit by the laser
       * @param[in] Laser
       * @return  True if the monster is hit by the laser
       * @return False if not
       */

    bool isAffected() const;
    void setAffected(bool b);

    virtual unique_ptr<object> clone() const override;
    virtual void collide(laser& l);

    /**
       * @brief Print a  monster
       * @param[in] ost :
    */
    virtual void print(std::ostream& ost) const override;
    virtual string toString() const override;


private :
    std::string d_name ;
    /**
    * @brief Boolean that says whether or
    * not the monster is hit by a laser
    */
    bool d_affected ;

};


#endif // MONSTER_H_INCLUDED
