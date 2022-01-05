//Declaring libraries
#include "grid.h"

//---------- Constructors------------------------------
grid::grid(double width, double height) : d_widthCells{width},
                                          d_heightCells{height}
{}
//---------- End of constructors-----------------------
//---------- Setter------------------------------------
void grid::setCellsWidth(double new_width)
{
    this->d_widthCells = new_width;
}

void grid::setCellsHeight(double new_height)
{
    this->d_heightCells = new_height;
}
//---------- End of Setter-----------------------------
//---------- Getter------------------------------------
double grid::getCellsWidth() const
{
    return this->d_widthCells;
}

double grid::getCellsHeight() const
{
    return this->d_heightCells;
}
//---------- End of Getter-----------------------------
//---------- Methods ----------------------------------
void grid::print(ostream &ost) const
{
    ost<<toString();
}

string grid::toString() const
{
    return "Grid[cellsWidth(" + to_string(d_widthCells) + "), cellsHeight(" + to_string(d_heightCells) + ")]";
}

void grid::read(istream &ist)
{
    double width, height;
    char characters;
    //Reading : (WIDTH , HEIGHT)
    ist>>characters>>width>>characters>>height>>characters;
    if(ist.good())
    {
        d_widthCells  = width;
        d_heightCells = height;
    }
}
//---------- End of methods ----------------------------
//---------- Operators outside class  -----------------
ostream& operator<<(ostream& ost, const grid& g)
{
    g.print(ost);
    return ost;
}

istream& operator>>(istream& ist, grid& g)
{
    g.read(ist);
    return ist;
}
//---------- End of Operators outside class  ----------




