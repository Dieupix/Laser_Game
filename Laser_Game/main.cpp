#include <iostream>

using namespace std;

#include "game.h"
#include "viewerOnWINBGI.h"

int main()
{
    ifstream ifs("../grounds/ground1.txt");
    ground g;
    g.loadFrom(ifs);

    point p = point{7, 10} + g.getPosition();
    g.addObjectAt(make_unique<mirror>(p, basGauche_hautDroit), 10, 7);

    p.shift(0, -4);
    g.addObjectAt(make_unique<mirror>(p, hautGauche_basDroit), 6, 7);

    viewerOnWINBGI v;
    v.printGround(g);

    getch();

    /*game g;
    g.read("../grounds/ground1.txt");

    g.run();*/
}
