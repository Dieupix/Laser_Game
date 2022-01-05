#ifndef MIROIR_H_INCLUDED
#define MIROIR_H_INCLUDED

//Declaring libraries
#include "enumTypes.h"
#include "object.h"

//Declaring namespace
using namespace enumTypes;

class mirror : public object
{
    public:
        /**
        * @brief Constructor of mirror
        *
        * @param position : position of mirror (const point)
        * @param Smirror : sense of mirror (enumeration sens)
        *
        * @return Create a mirror with position and sense
        */
        mirror(const point& position, sens Smirror);

        /**
        * @brief Virtual destructor of mirror
        *
        */
        virtual ~mirror() = default;

        /**
        * @brief Function that returns the sense of current mirror
        *
        * @return the sense
        */
        sens getSens() const;

        /**
        * @brief  Function that change the direction of the laser when the mirror is touched by laser
        *
        * @param l : the laser
        *
        * @return void
        */
        void changeDirectionLaser(laser& l);

        /**
        * @brief Virtual function that allows to clone a smart pointer of mirror
        *
        * @return a new smart pointer of mirror
        */
        virtual unique_ptr<object> clone() const override;

        /**
        * @brief Virtual procedure that allows to test if the current mirror has the same position in the ground that a laser
        *
        * @param l : new laser
        *
        * @return void
        */
        virtual void collide(laser& l) override;

        /**
        * @brief Virtual procedure that allows to print characteristics of mirror
        *
        * @return void
        */
        virtual void print(ostream& ost) const override;

        /**
        * @brief Virtual function that allows to convert a mirrror in string
        *
        * @return a string
        */
        virtual string toString() const override;

    private:

        //The sense of the mirror. It can be "hautGauche_basDroit" ou "basGauche_hautDroit"
        sens d_sens;
        //A boolean that allows to know when the current mirror is touched by a laser
        bool  d_mirrortouched;
};

#endif // MIROIR_H_INCLUDED
