#ifndef OBJECT_H
#define OBJECT_H

//Declaring libraries
#include "enumTypes.h"
#include "point.h"
#include <memory>

//Declaring namespace elements
using std::make_unique;
using std::unique_ptr;

//Declaring class
class laser;

/**
 * @class object object.h
 * @brief A class that represents an object
 * @details This class represents an object, with a @a position
*/
class object
{
    //Friend of class
    friend object createObjectForTest(const point&);

   protected:

        /**
        * @brief Constructor of object
        *
        * @param p : point (const point)
        *
        * @return Create an object with a point
        */
       object(point p);

        /**
        * @brief Constructor by default of object
        *
        * @return Create an object with a point (0,0)
        */
       object();

   public :
        /**
        * @brief Virtual destructor by default of object
        */
       virtual ~object() = default;

        /**
        * @brief Function that set position of the object
        *
        * @param p : point (const point)
        *
        * @return void
        */
       void setPosition(const point& p);

        /**
        * @brief Function that get position of the object
        *
        * @return the current point of the current object
        */
       point getPosition() const;

        /**
        * @brief Procedure that translate an object thanks coordinates (x,y) in parameters
        *
        * @param x : new coordinate x of point of object (double)
        * @param y : new coordinate y of point of object (double)
        *
        * @return void
        */
       void shift(double x, double y);

        /**
        * @brief Procedure that translate an object thanks point in parameters
        *
        * @param p : new point of object (const point)
        *
        * @return void
        */
       void shift(const point& p);

        /**
        * @brief Procedure that moves coordinates of point of object
        *
        * @param p : new point of object (const point)
        *
        * @return void
        */
       void move(const point& p);

        /**
        * @brief Procedure that moves coordinates of point of object on a new x and new y
        *
        * @param x : new coordinate x of point of object (double)
        * @param y : new coordinate y of point of object (double)
        *
        * @return void
        */
       void move(double x, double y);

        /**
        * @brief Virtual procedure that allows to test if the current object has the same position in the ground that a laser
        *
        * @param l : new laser
        *
        * @return void
        */
       virtual void collide(laser& l);

        /**
        * @brief Virtual function that allows to clone a smart pointer of object
        *
        * @return a new smart pointer of object
        */
       virtual unique_ptr<object> clone() const;

        /**
        * @brief Virtual procedure that allows to print characteristics of object
        *
        * @return void
        */
       virtual void print(std::ostream& ost) const;

        /**
        * @brief Virtual function that allows to convert a point in string
        *
        * @return a string
        */
       virtual string toString() const;

        /** @brief Allows to test equality between 2 objects
         *
         * @param o : an object (const object)
         *
         * @return a boolean
         */
       bool operator==(const object& o) const;

        /** @brief Allows to test inequality between 2 objects
         *
         * @param o : an object (const object)
         *
         * @return a boolean
         */
       bool operator!=(const object& o) const;

    private :
        //The position of object
       point d_p;
};

        /** @brief Allows to print a point
         *
         * @param ost : the flow (ostream)
         * @param o : an object to print (const object)
         *
         * @return the flow
         */
       std::ostream& operator<<(std::ostream& ost, const object& o);

        /** @brief Allows to create an object for test
         *
         * @param p : a point (const point)
         *
         * @return an object
         */
       object createObjectForTest(const point& p);

#endif // OBJET_H
