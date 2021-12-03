#ifndef GROUND_H
#define GROUND_H

#include <memory>
#include <vector>

#include "object.h"
#include "grille.h"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_unique;
using std::unique_ptr;
using std::vector;

/**
 * @class ground ground.h
 * @brief A class that represents a ground
 * @details This class represents a ground, which is a @a grid
 * at a @a position, with a number of cells in width and height and a list of @a objects.
 */
class ground : public grille
{
    private:
        /**
         * @brief The position of the ground
         / @details Represents the position of the ground based on the grid
         */
        point position;
        int nbCellsWidth, nbCellsHeight;
        /**
         * @brief The list of objects
         * @details Contains all the objects that are on the ground
         */
        vector<unique_ptr<object>> objects;
        /** @var ground::nbCellsWidth
         * @brief The number of cells in width
         */
         /** @var ground::nbCellsHeight
         * @brief The number of cells in height
         */


    public:

        // Constructors
        /**
         * @brief Constructor with all member variables
         *
         * @param position : The position of the ground on the grid
         * @param cellsWidth : The size of each cells in width
         * @param cellsHeight : The size of each cells in height
         * @param nbCellsWidth : The number of cells in width
         * @param nbCellsHeight : The number of cells in height
         * @return Creates a ground that is a grid, with its position, list of objects and number of cells
         */
        ground(const point& position, int cellsWidth, int cellsHeight, int nbCellsWidth, int nbCellsHeight);

        // Destructors
        /**
         * @brief Default-implemented destructor
         * @details Destroys the ground
         */
        virtual ~ground() = default;

        // Overloads

        // Getters
        /** @brief
         *
         * @return point
         *
         */
        point getPosition() const;
        /** @brief
         *
         * @return int
         *
         */
        int getNbCellsWidth() const;
        /** @brief
         *
         * @return int
         *
         */
        int getNbCellsHeight() const;
        /**
         * @brief Getter function for the list of objects
         *
         * @return vector<unique_ptr<object>>&
         */
        vector<unique_ptr<object>>& getObjects();

        // Setters
        /** @brief
         *
         * @param point& const
         * @return void
         *
         */
        void setPosition(const point&);
        /** @brief
         *
         * @param int
         * @return void
         *
         */
        void setNbCellsWidth(int);
        /** @brief
         *
         * @param int
         * @return void
         *
         */
        void setNbCellsHeight(int);

        // Functions
        /**
         * @brief A constant function that prints a ground on an output stream
         * @details A ground is printed as :
         * Ground[Grid[cellsWidth(x), cellsHeight(x)], position(x,y), nbCellsWidth(x) nbCellsHeight(x)]
         * Objects (x) :
         * 1 : Object(...)
         *
         * @param ost : The output stream to print on
         * @return Returns nothing
         */
        virtual void print(std::ostream& ost) const;

}; // End of ground

// Global functions

#endif // GROUND_H
