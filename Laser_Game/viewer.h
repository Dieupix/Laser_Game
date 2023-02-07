#ifndef VIEWER_H
#define VIEWER_H

//Declaring libraries
#include <iostream>
#include <memory>

//Declaring classes
#include "ground.h"
#include "laser.h"
#include "mirror.h"
#include "shooter.h"
#include "target.h"
#include "wall.h"

//Declaring namespace elements
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_unique;
using std::unique_ptr;

/**
 * @class viewer viewer.h
 * @brief An abstract class that represents all viewers
 * @details This abstract class represents all viewers, it cannot display any informations.
 */
class viewer
{
    public:

        /**
        * @brief Virtual destructor by default of viewer
        */
        virtual ~viewer() = default;

        /**
         * @brief A pure virtual constant function that prints an object on a viewer
         *
         * @param obj : The object to print
         *
         * @return Returns nothing
         */
        virtual void print(const unique_ptr<object>&) const = 0;

        /**
         * @brief A pure virtual constant function that prints a ground on a viewer
         *
         * @param g : The ground to print
         *
         * @return void
         */
        virtual void printGround(const ground& g) const = 0;

         /**
         * @brief A pure virtual constant function that prints a laser on a viewer
         *
         * @param l : The laser to print
         *
         * @return void
         */
        virtual void printLaser(const laser& l) const = 0;

         /**
         * @brief A pure virtual constant function that prints a mirror on a viewer
         *
         * @param l : The mirror to print
         *
         * @return void
         */
        virtual void printMirror(const mirror& m) const = 0;

         /**
         * @brief A pure virtual constant function that prints a shooter on a viewer
         *
         * @param l : The shooter to print
         *
         * @return void
         */
        virtual void printShooter(const shooter& s) const = 0;

         /**
         * @brief A pure virtual constant function that prints a target on a viewer
         *
         * @param l : The target to print
         *
         * @return void
         */
        virtual void printTarget(const target& t) const = 0;

         /**
         * @brief A pure virtual constant function that prints a wall on a viewer
         *
         * @param l : The wall to print
         *
         * @return void
         */
        virtual void printWall(const wall& w) const = 0;

};

#endif // VIEWER_H
