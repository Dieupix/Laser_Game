#ifndef MIROIR_H_INCLUDED
#define MIROIR_H_INCLUDED

#include "enumTypes.h"
#include "object.h"

using namespace enumTypes;

class mirror : public object
{

    public:
   /** @brief constructor of a mirror
    *
    * @param[in] have a position
    * @param[in] have a sens
    *
    */
    mirror( const point& position, sens Smirror ) ;

    // Destructor
    /**
     * @brief Default-implemented destructor
     * @details Destroys the mirror.
     */

    ~mirror()  = default ;

    /**
    * @brief  Get Sens of the mirror
    * @return Sens
    */
     sens  getSens() const ;
     /**
    * @brief  change the direction of the laser
    *   when the laser touch the mirror
    *
    */
       void changeDirectionLaser(laser& ) const ;
       virtual unique_ptr<object> clone() const override;

       /**
    * @brief Check if the laser touched the mirror
    * @return True : if he touched
    * @return False : if he didn't
    *
    */
       bool estTouchee(laser& ) const;

    virtual void collide(laser& l) override;

          /**
    * @brief Print the  Characteristics of the mirror
    * @param[in] ost
    *
    */
       virtual void print(std::ostream& ost) const override;
       virtual string toString() const override;
     private:
        /**
        *  @brief The mirror has Boolean that says whether or
        * not the mirror is hit by a laser
        * he has sens  basGauche_hautDroit and  hautGauche_basDroit
        */
       sens d_sens;

        bool  d_mirrortouched;

};



#endif // MIROIR_H_INCLUDED
