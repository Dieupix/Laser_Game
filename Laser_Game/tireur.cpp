#include "tireur.h"

tireur::tireur(const point &p, directions direction) : object{p}, direction{direction}
{}

laser tireur::tire(double step)
{
    laser l{this->getPosition(), static_cast<laser::directions>(direction), step};
    return l;
}
