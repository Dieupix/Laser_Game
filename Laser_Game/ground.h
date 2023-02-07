#ifndef GROUND_H
#define GROUND_H

//Declaring libraries
#include <memory>
#include <vector>

//Declaring classes
#include "object.h"
#include "grid.h"
#include "mirror.h"
#include "laser.h"
#include "shooter.h"
#include "target.h"
#include "wall.h"

//Declaring namespace elements
using std::cerr;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::unique_ptr;
using std::make_unique;
using std::move;
using std::vector;

/**
 * @class ground ground.h
 * @brief A class that represents a ground
 * @details This class represents a ground, which is a @a grid, with a @a position, a @a number @a of @a cells (width and height),
 * a @a number @a of @ objects in the ground, a @a number @a of @a mirrors @a installed,
 * a @a limit @a number @a of @a installed @a mirrors and a @a vector of smart pointer of objects (matrix)
*/
class ground : public grid
{
    public:
        /**
        * @brief Constructor by default of ground
        *
        * @return Create a ground with a point (0,0)
        */
        ground();

        /**
        * @brief Constructor of ground
        *
        * @param p : point (const point)
        * @param cellsWidth :  width cells  (double)
        * @param cellsHeight:  height cells (double)
        * @param nbCellsWidth  : number of width cells (unsigned)
        * @param nbCellsHeight : number of height cells (unsigned)
        * @param nbMirrorMax   : limit number of installed mirrors (unsigned)
        * @return Create an object with a point
        */
        ground(const point&, double cellsWidth, double cellsHeight, unsigned nbCellsWidth, unsigned nbCellsHeight, unsigned nbMirrorMax);

        /**
        * @brief Constructor recopy of ground
        *
        * @param g : a ground (const)
        *
        * @return Create a new ground with a ground
        */
        ground(const ground& g);

        /**
        * @brief Virtual destructor by default of ground
        */
        virtual ~ground() = default;

        /**
        * @brief Function that set position of the ground
        *
        * @param p : point (const point)
        *
        * @return void
        */
        void setPosition(const point&);

        /**
        * @brief Function that set number of cells width of the ground
        *
        * @param nbCells : the new number of cells width (unsigned)
        *
        * @return void
        */
        void setNbCellsWidth(unsigned nbCells);

        /**
        * @brief Function that set number of cells height of the ground
        *
        * @param nbCells : the new number of cells height (unsigned)
        *
        * @return void
        */
        void setNbCellsHeight(unsigned nbCells);

        /**
        * @brief Function that set limited number of installed mirrors of the ground
        *
        * @param MirrorMax : the new limited number of installed mirrors of the ground (unsigned)
        *
        * @return void
        */
        void setNbMirrorMax(unsigned MirrorMax);

        /**
        * @brief Function that get position of the ground
        *
        * @return the current point of the current ground
        */
        point getPosition() const;

        /**
        * @brief Function that get number of cells width of the ground
        *
        * @return the current number of the current ground
        */
        unsigned getNbCellsWidth() const;

        /**
        * @brief Function that get number of cells height of the ground
        *
        * @return the current number of the current ground
        */
        unsigned getNbCellsHeight() const;

        /**
        * @brief Function that get number of objects of the ground
        *
        * @return the current number of the current ground
        */
        unsigned getNbOfObjects() const;

        /**
        * @brief Function that get number of installed mirrors of the ground
        *
        * @return the current number of the current ground
        */
        unsigned getNbOfMirrors() const;

        /**
        * @brief Function that get limited number of installed mirrors of the ground
        *
        * @return the current number of the current ground
        */
        unsigned getNbMirrorMax() const;

        /**
        * @brief Function that get vector of smart pointer of objects of the ground
        *
        * @return the current matrix of the current ground
        */
        const vector<vector<unique_ptr<object>>>& getObjects() const;

        /**
         * @brief Function that adds an object on the ground
         * @details This function adds an object to the ground if there is a place
         * at the position (i, j), otherwise the object is not added.
         * @exception out_of_range : Throws this exception if an index is out of range
         *
         * @param[in] obj : The object to add to the ground
         * @param i : The i index where to add the object
         * @param j : The j index where to add the object
         * @return Returns nothing
         */
        void addObjectAt(unique_ptr<object> obj, unsigned i, unsigned j);

        /**
         * @brief Constant function that gives the shooter on the ground
         * @details There must be a shooter on the ground !
         *
         * @return Returns the shooter on the ground
         */
        const shooter& getShooter() const;

        /**
         * @brief
         *
         * @return const target&
         */
        const target& getTarget() const;
        /**
         * @brief Function that loads a ground from an input stream
         *
         * @param[in] ist : The input stream to load the ground from
         * @return Returns nothing
         */
        void loadFrom(istream& ist);

        /**
         * @brief Virtual constant function that prints a ground on an output stream
         *
         * @param[out] ost : The output stream to print on
         * @return Returns nothing
         */
        virtual void print(ostream& ost) const;

        /**
         * @brief Function that removes the object at an index
         * @details The index has to be in the range of 0 and the size of the list of objects.
         * @exception out_of_range : Throws this exception if an index is out of range
         *
         * @param i : The i index where to remove the object
         * @param j : The j index where to remove the object
         * @return Returns nothing
         */
        void removeObjectAt(unsigned i, unsigned j);

        /**
         * @brief Constant function that saves the ground in an output stream
         *
         * @param[out] ost : The output stream to save the ground in
         * @return Returns nothing
         */
        void saveIn(ostream& ost) const;

        /**
         * @brief Virtual constant function that turns a ground into a string
         * @details A ground is printed as : \n
         * Ground[Grid[cellsWidth(x), cellsHeight(x)], position(x,y), nbCellsWidth(x), nbCellsHeight(x)] \n
         * Objects (#) : \n
         * 1 : Object(...) \n
         * 2 : Object(...)
         *
         * @return Returns the ground converted into a string
         */
        virtual string toString() const override;

        /** @brief Allows to have a new ground with a ground
         *
         * @param g : a ground (const ground)
         *
         * @return a new ground
         */
        ground operator=(const ground& g) const;

        /** @brief Allows to have a ground with an other ground
         *
         * @param g : a ground (const ground)
         *
         * @return the current ground
         */
        ground& operator=(const ground& g);

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
         * @brief The maximum number of mirrors
         */
        unsigned nbMirrorMax;
        /**
         * @brief The list of objects
         * @details Contains all the objects that are on the ground.
         */
        vector<vector<unique_ptr<object>>> objects;

};

#endif // GROUND_H
