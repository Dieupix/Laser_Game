#ifndef VIEWER_H
#define VIEWER_H

#include <iostream>
#include <memory>

#include "laser.h"
#include "tireur.h"
#include "wall.h"

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

        virtual void print(const unique_ptr<object>& obj) const = 0;

        virtual void printLaser(const unique_ptr<laser>& l) const = 0;
        virtual void printTireur(const unique_ptr<tireur>& t) const = 0;
        virtual void printWall(const unique_ptr<wall>& w) const = 0;
};

#endif // VIEWER_H
