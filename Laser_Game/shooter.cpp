//Declaring libraries
#include "shooter.h"
#include "laser.h"

//---------- Constructors------------------------------
shooter::shooter(const point& p, directions dir) : object{p},
                                                   direction{dir}
{}
//---------- End of constructors-----------------------
//---------- Setter------------------------------------
void shooter::setDirection(directions direction)
{
    this->direction = direction;
}
//---------- End of Setter-----------------------------
//---------- Getter------------------------------------
directions shooter::getDirection() const
{
    return this->direction;
}
//---------- End of Getter-----------------------------
//---------- Methods ----------------------------------
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

void shooter::print(std::ostream& ost) const
{
    ost << toString();
}

string shooter::toString() const
{
    string str_shooter = "Tireur[position" + getPosition().toString() + ", direction(";
    //There are 4 directions so 4 possibilities
    switch(direction)
    {
        case directions::RIGHT:
        {
            str_shooter += "RIGHT";
            break;
        }
        case directions::LEFT:
        {
            str_shooter += "LEFT";
            break;
        }
        case directions::UP:
        {
            str_shooter += "UP";
            break;
        }
        case directions::DOWN:
        {
            str_shooter += "DOWN";
            break;
        }
        default:
        {
            str_shooter += "ERROR: Direction not defined";
            break;
        }
    }
    str_shooter += ")]";
    return str_shooter;
}

laser shooter::shoot(double step)
{
    return {this->getPosition(), direction, step};
}







