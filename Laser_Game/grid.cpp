#include "grid.h"

grid::grid(double largeur, double hauteur) : d_largeurCells{largeur}, d_hauteurCells{hauteur}
{}

std::ostream& operator<<(std::ostream& ost, const grid& g){
    g.print(ost);
    return ost;
}

std::istream& operator>>(std::istream& ist, grid& g){
    g.read(ist);
    return ist;
}

double grid::getCellsHeight() const {return this->d_hauteurCells;}

double grid::getCellsWidth() const {return this->d_largeurCells;}

void grid::setCellsHeight(double hauteurCells)
{
    this->d_hauteurCells = hauteurCells;
}

void grid::setCellsWidth(double largeurCells)
{
    this->d_largeurCells = largeurCells;
}

void grid::print(std::ostream &ost) const
{
    ost<<toString();
}

void grid::read(std::istream &ist)
{
    int a, b;
    char c;
    ist>>c>>a>>c>>b>>c;
    if(ist.good())
    {
        d_largeurCells = a;
        d_hauteurCells = b;
    }
}

std::string grid::toString() const
{
    return "Grid[cellsWidth(" + std::to_string(d_largeurCells) + "), cellsHeight(" + std::to_string(d_hauteurCells) + ")]";
}
