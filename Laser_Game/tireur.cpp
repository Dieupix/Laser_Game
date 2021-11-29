#include "tireur.h"

tireur::tireur(const point &p, directions direction) : object{p}, direction{direction}
{}

laser tireur::tire(int step)
{
    laser l{this->getPosition(), direction, step};
    return l;
}
