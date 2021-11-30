#include <iostream>

using namespace std;

#include <memory>
#include "viewerOnTerminal.h";
#include "tireur.h"
#include "laser.h"

int main()
{
    auto t = make_unique<tireur>(point{0, 0}, tireur::directions::RIGHT);
    auto l = make_unique<laser>(t->tire());

    cout << *t << endl << *l << endl;

    viewerOnTerminal v;

    v.printTireur(t);
    v.printLaser(l);
}
