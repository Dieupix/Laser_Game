#ifndef VIEWER_H
#define VIEWER_H

#include <iostream>
#include <memory>

#include "cible.h"
#include "ground.h"
#include "laser.h"
#include "miroir.h"
#include "tireur.h"
#include "wall.h"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_unique;
using std::unique_ptr;

/**
 * @class viewer viewer.h
 * @brief An abstract class that represents all viewers
 * @details This abstract class represents all viewers,
 * it cannot display any informations.
 */
class viewer
{
    public:
        // Destructor
        /**
         * @brief Default-implemented destructor
         * @details Destroys the viewer
         */
        virtual ~viewer() = default;

        // Functions
        /**
         * @brief A pure virtual constant function that prints an object on a viewer
         *
         * @param obj : The object to print
         * @return Returns nothing
         */
        virtual void print(const unique_ptr<object>&) const = 0;

        virtual void printCible(const target&) const = 0;
        virtual void printGround(const ground&) const = 0;
        virtual void printLaser(const laser&) const = 0;
        virtual void printMirror(const mirror&) const = 0;
        virtual void printShooter(const tireur&) const = 0;
        virtual void printWall(const wall&) const = 0;

}; // End of viewer

// Global functions

#endif // VIEWER_H
