#include "tireur.h"

tireur::tireur(const point &p, directions direction) : object{p}, direction{direction}
{}

laser tireur::tire(double step)
{
    laser l{this->getPosition(), static_cast<laser::directions>(direction), step};
    return l;
}

void tireur::print(std::ostream& ost) const {
    ost << "Tireur[position" << getPosition() << ", direction(";
    switch(direction){
        case directions::RIGHT: {
            ost << "RIGHT";
            break;
        }case directions::LEFT: {
            ost << "LEFT";
            break;
        }case directions::UP: {
            ost << "UP";
            break;
        }case directions::DOWN: {
            ost << "DOWN";
            break;
        }
        default:{
            ost << "ERROR: Direction not defined";
            break;
        }
    }
}


tireur::directions tireur::getDirection() const{
}
void tireur::setDirection(directions direction){
}
