#ifndef GRID_H
#define GRID_H

//Declaring libraries
#include <iostream>
#include <string>

//Declaring namespace elements
using std::ostream;
using std::istream;
using std::string;
using std::to_string;


/**
 * @class grid grid.h
 * @brief A class that represents a grid
 * @details This class represents a grid, with a @a width @a of @a cells and a @a height @a of @a cells
*/
class grid
{
    public:
        /**
        * @brief Constructor of grid
        *
        * @param width  : the width of cells (double)
        * @param height : the height of cells (double)
        *
        * @return Create a grid with a width and a height of cells
        */
        grid(double width, double height);

        /**
        * @brief Virtual destructor by default of grid
        */
        virtual ~grid() = default;

        /**
        * @brief Function that set the width of the cells of the grid
        *
        * @param new_width : the new width of the cells
        *
        * @return void
        */
        void setCellsHeight(double new_width);

        /**
        * @brief Function that set the height of the cells of the grid
        *
        * @param new_height : the new width of the cells
        *
        * @return void
        */
        void setCellsWidth(double new_height);

        /**
        * @brief Function that get the width of the cells of the grid
        *
        * @return the current width of the cells of the grid
        */
        double getCellsWidth() const;

        /**
        * @brief Function that get the height of the cells of the grid
        *
        * @return the current height of the cells of the grid
        */
        double getCellsHeight() const;

        /**
        * @brief Virtual procedure that allows to print characteristics of grid
        *
        * @return void
        */
        virtual void print(ostream& ost) const;

        /**
        * @brief Virtual function that allows to convert a grid in string
        *
        * @return a string
        */
        virtual string toString() const;

        /**
        * @brief Procedure that allows to read a grid
        *
        * @param ist : the flow (istream)
        *
        * @return void
        */
        void read(istream& ist);

    private:
        //The width and the height of cells of the grid
        double d_widthCells, d_heightCells;
};

        /** @brief Allows to print a grid
         *
         * @param ost : the flow (ostream)
         * @param g : a grid to print (const grid)
         *
         * @return the flow
         */
        ostream& operator<<(ostream& ost, const grid & g);

        /** @brief Allows to read a grid
         *
         * @param ist : the flow (istream)
         * @param g : a grid to read
         *
         * @return the flow
         */
        istream& operator>>(istream& ist, grid& g);

#endif // GRID_H
