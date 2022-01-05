//Declaring libraries
#include "laser.h"


//---------- Constructors------------------------------
laser::laser(const point& p, directions direction, double step_laser) : object{p},
                                                                        direction{direction},
                                                                        isAlive{true},
                                                                        step{step_laser}
{}
//---------- End of constructors-----------------------
//---------- Setter------------------------------------
void laser::setDirection(directions dir)
{
    this->direction = dir;
}

void laser::setIsAlive(bool isAlive)
{
    this->isAlive = isAlive;
}

void laser::setStep(double new_step)
{
    this->step = new_step;
}
//---------- End of Setter-----------------------------
//---------- Getter------------------------------------
directions laser::getDirection() const
{
    return this->direction;
}

bool laser::getIsAlive() const
{
    return this->isAlive;
}

double laser::getStep() const
{
    return this->step;
}
//---------- End of Getter-----------------------------
//---------- Methods ----------------------------------
unique_ptr<object> laser::clone() const
{
    return make_unique<laser>(*this);
}

void laser::moveByStep()
{
    switch(this->direction)
    {
        case directions::RIGHT:
        {
            shift(step, 0);
            break;
        }
        case directions::LEFT:
        {
            shift(-step, 0);
            break;
        }
        case directions::UP:
        {
            shift(0, step);
            break;
        }
        case directions::DOWN:
        {
            shift(0, -step);
            break;
        }
        default:
        {
            std::cerr << "Error: laser::moveByStep(): the direction \"" << this->direction << "\" is not defined" << std::endl;
            break;
        }
    }
}

void laser::print(std::ostream& ost) const
{
    ost << toString();
}

string laser::toString() const
{
    string toString = "Laser[position" + getPosition().toString() + ", direction(";
    switch(direction){
        case directions::RIGHT:
        {
            toString += "RIGHT";
            break;
        }
        case directions::LEFT:
        {
            toString += "LEFT";
            break;
        }
        case directions::UP:
        {
            toString += "UP";
            break;
        }
        case directions::DOWN:
        {
            toString += "DOWN";
            break;
        }
        default:
        {
            toString += "ERROR: Direction is not defined";
            break;
        }
    }
    toString += "), step(" + std::to_string(step) + ")]";
    return toString;
}

void laser::turnLeft()
{
    //Turn left equals : RIGHT --> UP , UP --> LEFT, LEFT --> DOWN, DOWN --> RIGHT
    this->direction = static_cast<directions>(static_cast<directions>(this->direction + 1) % 4);
}

void laser::turnRight()
{
    //Turn right equals : RIGHT --> DOWN , UP --> RIGHT, LEFT --> UP, DOWN --> LEFT
    this->direction = static_cast<directions>(static_cast<directions>(this->direction - 1) % 4);
}
//---------- End of methods ----------------------------
//---------- Operators in class  -----------------------
bool laser::operator==(const laser& l) const
{
    bool same_position = getPosition() == l.getPosition();
    bool same_direction = getDirection() == l.getDirection();
    bool same_step = getStep() == l.getStep();
    return  same_position && same_direction && same_step;
}

bool laser::operator!=(const laser& l) const
{
    return not operator==(l);
}
//---------- End of Operators in class  ---------------
//---------- Globals Functions ------------------------
laser createLaserForTest(const point& p, const directions& direction, double step)
{
    return {p, direction, step};
}
//---------- End of Globals Functions -----------------

