#ifndef TIREUR_H
#define TIREUR_H

//Declaring libraries
#include "object.h"

//Declaring namespace
using namespace enumTypes;

//Declaring class
class laser;

/**
 * @class shooter shooter.h
 * @brief A class that represents a shooter
 * @details This class represents a shooter, with a @a position and a @a direction
*/
class shooter : public object
{
    public:

        /**
        * @brief Constructor of shooter
        *
        * @param p : point (const point)
        * @param direction : the direction of shooter (enumeration directions)
        *
        * @return Create a shooter with a point and a direction
        */
        shooter(const point& p, directions dir);

        /**
        * @brief Virtual destructor by default of shooter
        */
        virtual ~shooter() = default;

        /**
        * @brief Function that set directions of the shooter
        *
        * @param direction : the new direction of the shooter
        *
        * @return void
        */
        void setDirection(directions direction);

        /**
        * @brief Function that get direction of the shooter
        *
        * @return the current direction of the current shooter
        */
        directions getDirection() const;

        /**
        * @brief Virtual function that allows to clone a smart pointer of shooter
        *
        * @return a new smart pointer of shooter
        */
        virtual unique_ptr<object> clone() const override;

        /**
        * @brief Virtual procedure that allows to test if the current shooter has the same position in the ground that a laser
        *
        * @param l : new laser
        *
        * @return void
        */
        virtual void collide(laser& l);

        /**
        * @brief Virtual procedure that allows to print characteristics of shooter
        *
        * @param ost : the flow (ostream)
        *
        * @return void
        */
        virtual void print(std::ostream& ost) const override;

        /**
        * @brief Virtual function that allows to convert a shooter in string
        *
        * @return a string
        */
        virtual string toString() const override;

        /**
        * @brief Function that allows to shoot a laser
        *
        * @param step : the step (double, 1.0 by default)
        *
        * @return a new laser
        */
        laser shoot(double step = 1.0);
    private:
        //The direction of the shooter
        directions direction;
};

#endif // TIREUR_H
