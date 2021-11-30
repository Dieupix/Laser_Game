#include "viewerOnTerminal.h"

void viewerOnTerminal::printLaser(unique_ptr<laser>& l) const{
    switch(l->getDirection()){
    case laser::directions::RIGHT:
    case laser::directions::LEFT:
        {
            cout << '-';
            break;
        }
    case laser::directions::UP:
    case laser::directions::DOWN:
        {
            cout << '|';
            break;
        }
    default:
        {
            cerr << "ERROR : Direction is not defined" << endl;
            break;
        }
    }
}

void viewerOnTerminal::printTireur(unique_ptr<tireur>& t) const{
    switch(t->getDirection()){
    case tireur::directions::RIGHT:
        {
            cout << '>';
            break;
        }
    case tireur::directions::LEFT:
        {
            cout << '<';
            break;
        }
    case tireur::directions::UP:
        {
            cout << '^';
            break;
        }
    case tireur::directions::DOWN:
        {
            cout << 'v';
            break;
        }
    default:
        {
            cerr << "ERROR : Direction is not defined" << endl;
            break;
        }
    }
}
