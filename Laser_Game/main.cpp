#include <iostream>

using namespace std;

#include "game.h"

int main()
{
    game g(make_unique<viewerOnTerminal>());
    g.read("../grounds/ground3.txt");

    g.run();
}
