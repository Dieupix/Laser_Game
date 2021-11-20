#include "laser.h"

// ---------- Constructors ----------

laser::laser(const point& p, directions direction, double step) : objet{p}, direction{direction}, step{step} {}

// ---------- End of constructors ----------

// ---------- Destructor ----------

// ---------- End of destructor ----------

// ---------- Overloads ----------

bool laser::operator==(const laser& l) const{
    return  getPosition() == l.getPosition() and
            getDirection() == l.getDirection() and
            getStep() == l.getStep();
}

bool laser::operator!=(const laser& l) const{
    return not operator==(l);
}

// ---------- End of overloads ----------

// ---------- Getters ----------

short unsigned int laser::getDirection() const {return this->direction;}

double laser::getStep() const {return this->step;}

// ---------- End of getters ----------

// ---------- Setters ----------

void laser::setDirection(directions direction){
    this->direction = direction;
}

void laser::setStep(double step){
    this->step = step;
}

// ---------- End of setters ----------

// ---------- Functions ----------

void laser::moveByStep(){
    switch(this->direction){
        case directions::RIGHT: {
            shift(this->step, 0);
            break;
        }
        case directions::LEFT: {
            shift(-this->step, 0);
            break;
        }
        case directions::UP: {
            shift(0, this->step);
            break;
        }
        case directions::DOWN: {
            shift(0, -this->step);
            break;
        }
        default: {
            std::cerr << "Error:  laser::moveByStep(): the direction \"" << this->direction << "\" is not defined" << std::endl;
            break;
        }
    }
}

void laser::print(std::ostream& ost) const {
    ost << "Laser[position" << getPosition() << ", direction(";
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
    ost << "), step(" << step << ")]";
}

void laser::turnLeft(){
    this->direction = static_cast<directions>(this->direction + 1) % 4;
}

void laser::turnRight(){
    this->direction = static_cast<directions>(this->direction - 1) % 4;
}

// ---------- End of functions ----------

// ---------- Global functions ----------

// ---------- End of global functions ----------

