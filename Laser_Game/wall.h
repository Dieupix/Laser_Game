#ifndef WALL_H
#define WALL_H

//Declaring libraries
#include "object.h"

//Declaring namespace elements
using std::unique_ptr;
using std::make_unique;
using std::ostream;
using std::string;


/**
 * @class wall wall.h
 * @brief A class that represents a wall
 * @details This class represents a wall, which a @a position
*/
class wall : public object
{
public:
        /**
        * @brief Constructor of wall
        *
        * @param p : point (const point)
        *
        * @return Create a wall with a point
        */
        wall(const point& p);

        /**
        * @brief Virtual destructor by default of wall
        */
        virtual ~wall() = default;

        /**
        * @brief Virtual procedure that allows to test if the current wall has the same position in the ground that a laser
        *
        * @param l : new laser
        *
        * @return void
        */
        virtual void collide(laser& l) override;

        /**
        * @brief Virtual function that allows to clone a smart pointer of wall
        *
        * @return a new smart pointer of object
        */
        virtual unique_ptr<object> clone() const override;

        /**
        * @brief Virtual procedure that allows to print characteristics of wall
        *
        * @return void
        */
        virtual void print(ostream&) const override;

        /**
        * @brief Virtual function that allows to convert a wall in string
        *
        * @return a string
        */
        virtual string toString() const override;
};
#endif // WALL_H
