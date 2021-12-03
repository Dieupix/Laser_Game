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
using std::move;
using std::unique_ptr;
using std::vector;

/**
 * @class ground ground.h
 * @brief A class that represents a ground
 * @details This class represents a ground, which is a @a grid
 * at a @a position, with a @a number of cells in width and height and a list of @a objects.
 */
class ground : public grille
{
    private:
        /**
         * @brief The position of the ground
         * @details Represents the position of the ground based on the grid.
         */
        point position;
        /**
         * @brief The number of cells in width
         */
        int nbCellsWidth;
        /**
         * @brief The number of cells in height
         */
        int nbCellsHeight;
        /**
         * @brief The list of objects
         * @details Contains all the objects that are on the ground.
         */
        vector<unique_ptr<object>> objects;

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

        // Destructor
        /**
         * @brief Default-implemented destructor
         * @details Destroys the ground.
         */
        virtual ~ground() = default;

        // Overloads

        // Getters
        /**
         * @brief Getter function for the position
         *
         * @return Returns the position of the ground
         */
        point getPosition() const;
        /**
         * @brief Getter function for the number of cells in width
         *
         * @return Returns the number of cells in width
         */
        int getNbCellsWidth() const;
        /**
         * @brief Getter function for the number of cells in height
         *
         * @return Returns the number of cells in height
         */
        int getNbCellsHeight() const;
        /**
         * @brief Getter function for the list of objects
         *
         * @return Returns the list of objects
         */
        vector<unique_ptr<object>>& getObjects();

        // Setters
        /**
         * @brief Setter function for the position
         *
         * @param[in] point : The new position
         * @return Returns nothing
         */
        void setPosition(const point&);
        /**
         * @brief Setter function for the number of cells in width
         *
         * @param[in] nbCellsWidth : The new number of cells
         * @return Returns nothing
         */
        void setNbCellsWidth(int);
        /**
         * @brief Setter function for the number of cells in height
         *
         * @param[in] nbCellsHeight : The new number of cells
         * @return Returns nothing
         */
        void setNbCellsHeight(int);

        // Functions
        /**
         * @brief A function that adds an object to the ground
         *
         * @param obj : The object to add to the ground
         * @return Returns nothing
         */
        void addObject(unique_ptr<object>);
        /**
         * @brief A constant function that prints a ground on an output stream
         * @details A ground is printed as : \n
         * Ground[Grid[cellsWidth(x), cellsHeight(x)], position(x,y), nbCellsWidth(x) nbCellsHeight(x)] \n
         * Objects (x) : \n
         * 1 : Object(...)
         *
         * @param ost : The output stream to print on
         * @return Returns nothing
         */
        virtual void print(std::ostream& ost) const;

}; // End of ground

// Global functions

#endif // GROUND_H
