#include "shooter.h"
#include "laser.h"

shooter::shooter(const point &p, directions direction) : object{p}, direction{direction}
{}

laser shooter::tire(double step)
{
    return {this->getPosition(), direction, step};
}

unique_ptr<object> shooter::clone() const
{
    return make_unique<shooter>(*this);
}

void shooter::collide(laser& l)
{
    if(*this == l)
    {
        l.setIsAlive(false);
    }
}

void shooter::print(std::ostream& ost) const {
    ost << toString();
}

string shooter::toString() const
{
    string t = "Tireur[position" + getPosition().toString() + ", direction(";
    switch(direction){
        case directions::RIGHT: {
            t += "RIGHT";
            break;
        }case directions::LEFT: {
            t += "LEFT";
            break;
        }case directions::UP: {
            t += "UP";
            break;
        }case directions::DOWN: {
            t += "DOWN";
            break;
        }
        default:{
            t += "ERROR: Direction not defined";
            break;
        }
    }
    t += ")]";

    return t;
}

directions shooter::getDirection() const{return this->direction;}

void shooter::setDirection(directions direction)
{
    this->direction = direction;
}
