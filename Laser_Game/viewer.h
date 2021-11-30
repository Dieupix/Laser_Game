#ifndef VIEWER_H
#define VIEWER_H

#include <iostream>
#include <memory>

#include "laser.h"
#include "tireur.h"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_unique;
using std::unique_ptr;

class viewer
{
public:
    virtual ~viewer() = default;
    virtual void printLaser(unique_ptr<laser>& l) const = 0;
    virtual void printTireur(unique_ptr<tireur>& l) const = 0;
};
#endif // VIEWER_H
