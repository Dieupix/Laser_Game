#ifndef VIEWER_H
#define VIEWER_H

#include <iostream>
#include <memory>

#include "cible.h"
#include "ground.h"
#include "laser.h"
#include "miroir.h"
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

        virtual void print(const unique_ptr<object>&) const = 0;

        virtual void printCible(const cible&) const = 0;
        virtual void printGround(const ground&) const = 0;
        virtual void printLaser(const laser&) const = 0;
        virtual void printMirror(const miroir&) const = 0;
        virtual void printShooter(const tireur&) const = 0;
        virtual void printWall(const wall&) const = 0;
};

#endif // VIEWER_H
