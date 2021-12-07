#ifndef GROUND_H
#define GROUND_H

#include <fstream>
#include <memory>
#include <string>
#include <sstream>
#include <vector>

#include "object.h"
#include "grille.h"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::make_unique;
using std::move;
using std::ofstream;
using std::string;
using std::stringstream;
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
        unsigned nbCellsWidth;
        /**
         * @brief The number of cells in height
         */
        unsigned nbCellsHeight;
        /**
         * @brief The total number of objects
         */
        int nbOfObjects;
        /**
         * @brief The list of objects
         * @details Contains all the objects that are on the ground.
         */
        vector<vector<unique_ptr<object>>> objects;

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
        ground(const point& position, double cellsWidth, double cellsHeight, unsigned nbCellsWidth, unsigned nbCellsHeight);

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
        unsigned getNbCellsWidth() const;
        /**
         * @brief Getter function for the number of cells in height
         *
         * @return Returns the number of cells in height
         */
        unsigned getNbCellsHeight() const;
        /**
         * @brief Getter function for the total number of objects
         *
         * @return Returns the number of objects on the ground
         */
        int getNbOfObjects() const;
        /**
         * @brief Getter function for the list of objects
         *
         * @return Returns the list of objects
         */
        const vector<vector<unique_ptr<object>>>& getObjects() const;

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
        void setNbCellsWidth(unsigned);
        /**
         * @brief Setter function for the number of cells in height
         *
         * @param[in] nbCellsHeight : The new number of cells
         * @return Returns nothing
         */
        void setNbCellsHeight(unsigned);

        // Functions
        /**
         * @brief A function that adds an object on the ground
         *
         * @param obj : The object to add to the ground
         * @param i : The i index where to add the object
         * @param j : The j index where to add the object
         * @return Returns nothing
         */
        void addObjectAt(unique_ptr<object>, unsigned, unsigned);
        /**
         * @brief A function that loads a ground from a file
         *
         * @param fileName : The file name to load the ground from
         * @return Returns true if the ground has been successfully loaded, false otherwise
         */
        bool loadGround(const string& fileName);
        /**
         * @brief A constant function that prints a ground on an output stream
         * @details A ground is printed as : \n
         * Ground[Grid[cellsWidth(x), cellsHeight(x)], position(x,y), nbCellsWidth(x) nbCellsHeight(x)] \n
         * Objects (x) : \n
         * 1 : Object(...) \n
         * 2 : Object(...)
         *
         * @param[out] ost : The output stream to print on
         * @return Returns nothing
         */
        virtual void print(std::ostream& ost) const;
        /**
         * @brief A function that removes the object at an index
         * @details The index has to be in the range of 0 and the size of the list of objects.
         * @exception out_of_range : Throws this exception if the index is out of range
         *
         * @param i : The i index where to remove the object
         * @param j : The j index where to remove the object
         * @return Returns nothing
         */
        void removeObjectAt(unsigned, unsigned);
        /**
         * @brief A constant function that saves the ground in a file
         *
         * @param fileName : The file name to save the ground in
         * @return Returns true if the ground has been successfully saved, false otherwise
         */
        bool saveGround(const string& fileName) const;

}; // End of ground

// Global functions

#endif // GROUND_H
