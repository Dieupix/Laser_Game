#ifndef GROUND_H
#define GROUND_H

#include <memory>
#include <vector>

#include "object.h"
#include "grid.h"
#include "mirror.h"
#include "shooter.h"
#include "target.h"
#include "wall.h"

using std::cerr;
using std::cout;
using std::endl;
using std::istream;
using std::make_unique;
using std::move;
using std::ostream;
using std::unique_ptr;
using std::vector;

/**
 * @class ground ground.h
 * @brief A class that represents a ground
 * @details This class represents a ground, which is a @a grid
 * at a @a position, with a @a number of cells in width and height and a list of @a objects.
 */
class ground : public grid
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
        unsigned nbOfObjects;
        /**
         * @brief The total number of mirrors
         */
        unsigned nbOfMirrors;
        /**
         * @brief The list of objects
         * @details Contains all the objects that are on the ground.
         */
        vector<vector<unique_ptr<object>>> objects;

    public:

        // Constructors
        /**
         * @brief
         *
         * @return
         */
        ground();
        /**
         * @brief Constructor with all member variables
         *
         * @param[in] position : The position of the ground on the grid
         * @param[in] cellsWidth : The size of each cells in width
         * @param[in] cellsHeight : The size of each cells in height
         * @param[in] nbCellsWidth : The number of cells in width
         * @param[in] nbCellsHeight : The number of cells in height
         * @return Creates a ground that is a grid, with its position, list of objects and number of cells
         */
        ground(const point&, double, double, unsigned, unsigned);
        /**
         * @brief Copy constructor
         *
         * @param g : The ground to copy
         * @return Creates a ground by copying all the member variables
         */
        ground(const ground&);

        // Destructor
        /**
         * @brief Default-implemented destructor
         * @details Destroys the ground.
         */
        virtual ~ground() = default;

        // Overloads
        void operator=(const ground&);

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
        unsigned getNbOfObjects() const;
        /**
         * @brief Getter function for the total number of mirrors
         *
         * @return Returns the number of mirrors on the ground
         */
        unsigned getNbOfMirrors() const;
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
         * @details This function adds an object to the ground if there is a place
         * at the position (i, j), otherwise the object is not added.
         * @exception out_of_range : Throws this exception if an index is out of range
         *
         * @param[in] obj : The object to add to the ground
         * @param i : The i index where to add the object
         * @param j : The j index where to add the object
         * @return Returns nothing
         */
        void addObjectAt(unique_ptr<object>, unsigned, unsigned);
        /**
         * @brief
         *
         * @return Returns the shooter on the ground
         */
        const shooter& getShooter() const;
        /**
         * @brief A function that loads a ground from an input stream
         *
         * @param[in] ist : The input stream to load the ground from
         * @return Returns nothing
         */
        void loadFrom(istream&);
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
        virtual void print(ostream&) const;
        /**
         * @brief A function that removes the object at an index
         * @details The index has to be in the range of 0 and the size of the list of objects.
         * @exception out_of_range : Throws this exception if an index is out of range
         *
         * @param i : The i index where to remove the object
         * @param j : The j index where to remove the object
         * @return Returns nothing
         */
        void removeObjectAt(unsigned, unsigned);
        /**
         * @brief A constant function that saves the ground in an output stream
         *
         * @param[out] ost : The output stream to save the ground in
         * @return Returns nothing
         */
        void saveIn(ostream&) const;
        virtual string toString() const override;

}; // End of ground

// Global functions

#endif // GROUND_H
