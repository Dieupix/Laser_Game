#ifndef TIREUR_H
#define TIREUR_H
#include "object.h"
#include "laser.h"

class tireur : public object
{
    public:
         enum directions : short unsigned int{
            RIGHT,
            UP,
            LEFT,
            DOWN
        };
        tireur(const point &p, directions);
        virtual ~tireur() = default;
        laser tire(int step);
    private:
        directions direction;

};

#endif // TIREUR_H
