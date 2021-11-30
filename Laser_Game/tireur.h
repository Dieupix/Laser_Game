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
        tireur::directions getDirection() const;
        void setDirection(directions direction);
        laser tire(double step = 1.0);
        virtual void print(std::ostream& ost) const override;
    private:
        directions direction;

};

#endif // TIREUR_H
