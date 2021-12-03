#include "viewerOnTerminal.h"

void viewerOnTerminal::printLaser(const unique_ptr<laser>& l) const{
    switch(l->getDirection()){
    case directions::RIGHT:
    case directions::LEFT:
        {
            cout << '-';
            break;
        }
    case directions::UP:
    case directions::DOWN:
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

void viewerOnTerminal::printTireur(const unique_ptr<tireur>& t) const{
    switch(t->getDirection()){
    case directions::RIGHT:
        {
            cout << '>';
            break;
        }
    case directions::LEFT:
        {
            cout << '<';
            break;
        }
    case directions::UP:
        {
            cout << '^';
            break;
        }
    case directions::DOWN:
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
