#ifndef WALL_H
#define WALL_H

#include "object.h"

class wall : public object
{
public:
    wall(const point& p);
    virtual ~wall() = default;

    virtual void collide(laser& l) override;
    virtual void print(std::ostream&) const override;
    virtual string toString() const override;

};
#endif // WALL_H
