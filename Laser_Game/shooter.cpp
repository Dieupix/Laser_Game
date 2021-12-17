#include "shooter.h"
#include "laser.h"

tireur::tireur(const point &p, directions direction) : object{p}, direction{direction}
{}

laser tireur::tire(double step)
{
    return {this->getPosition(), direction, step};
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
    ost << ")]";
}


directions tireur::getDirection() const{
    return direction;
}
void tireur::setDirection(directions direction){
}
