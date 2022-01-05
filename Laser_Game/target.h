#ifndef CIBLE_H_INCLUDED
#define CIBLE_H_INCLUDED

//Declaring libraries
#include "object.h"

class target : public object
{
    public :

        /**
        * @brief Constructor of target
        *
        * @param p : point (const point)
        *
        * @return Create a target with a point
        */
        target(const point& position);

        /**
        * @brief Virtual destructor by default of object
        */
        virtual ~target() = default;

        /**
        * @brief Function that allows to know if current target is affected
        *
        * @return a boolean
        */
        bool isAffected() const;

        /**
        * @brief Function that set affectation of the target
        *
        * @param b : a boolean
        *
        * @return void
        */
        void setAffected(bool b);

        /**
        * @brief Virtual function that allows to clone a smart pointer of target
        *
        * @return a new smart pointer of target
        */
        virtual unique_ptr<object> clone() const override;

        /**
        * @brief Virtual procedure that allows to test if the current target has the same position in the ground that a laser
        *
        * @param l : new laser
        *
        * @return void
        */
        virtual void collide(laser& l);

        /**
        * @brief Virtual procedure that allows to print characteristics of target
        *
        * @return void
        */
        virtual void print(ostream& ost) const override;

        /**
        * @brief Virtual function that allows to convert a target in string
        *
        * @return a string
        */
        virtual string toString() const override;

    private :
        //A boolean that allows to know when the target is affected
        bool d_affected ;
};

#endif // CIBLE_H_INCLUDED
