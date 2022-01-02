#ifndef WALL_H
#define WALL_H

#include "object.h"
class laser;

class wall : public object
{
public:
    wall(const point& p);
    virtual ~wall() = default;
    bool isAffected(laser& l) const;
    void changeAffected() ;

    virtual void print(std::ostream&) const override;
    virtual string toString() const override;

private:
    bool d_affected;
};
#endif // WALL_H
