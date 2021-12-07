#include "viewerOnTerminal.h"

void viewerOnTerminal::print(const unique_ptr<object>& obj) const{
    if(dynamic_cast<laser*>(obj.get())){

        auto tmp = dynamic_cast<laser*>(obj.get());
        printLaser(make_unique<laser>(*tmp));

    }else if(dynamic_cast<wall*>(obj.get())){

        /*auto tmp = dynamic_cast<wall*>(obj.get());
        printWall(make_unique<wall>(*tmp));*/

    }else if(dynamic_cast<tireur*>(obj.get())){

        auto tmp = dynamic_cast<tireur*>(obj.get());
        printTireur(make_unique<tireur>(*tmp));

    }else
        cerr << "Unknown type" << endl;
}

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
void viewerOnTerminal::printWall(const unique_ptr<wall>&) const{
    cout << '#';
}
