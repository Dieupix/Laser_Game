#include "grid.h"

grille::grille(int longueur, int larger) : d_longueurCells{longueur}, d_largeurCells{larger}
{}

std::ostream& operator<<(std::ostream& ost, const grille& g){
    g.print(ost);
    return ost;
}

std::istream& operator>>(std::istream& ist, grille& g){
    g.read(ist);
    return ist;
}


void grille::print(std::ostream &ost) const
{
    ost<<'('<<d_longueurCells<<','<<d_largeurCells<<')';
}

void grille::read(std::istream &ist)
{
    int a, b;
    ist>>a>>b;
    if(ist.good())
    {
        d_longueurCells = a;
        d_largeurCells = b;
    }
}
