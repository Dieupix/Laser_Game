#include "laser.h"

// ---------- Constructors ----------

laser::laser(const point& p, short int direction, double step) : objet{p}, direction{direction}, step{step} {}

// ---------- End of constructors ----------

// ---------- Destructor ----------

// ---------- End of destructor ----------

// ---------- Overloads ----------

// ---------- End of overloads ----------

// ---------- Getters ----------

short int laser::getDirection() const {return this->direction;}

double laser::getStep() const {return this->step;}

// ---------- End of getters ----------

// ---------- Setters ----------

void laser::setDirection(short int direction){
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
    ost << "Laser[position" << d_p << ", direction(";
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

// ---------- End of functions ----------

// ---------- Global functions ----------

// ---------- End of global functions ----------

