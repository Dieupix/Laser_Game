#ifndef WALL_H
#define WALL_H

#include "object.h"
class laser;

class wall : public object
{
public:
    wall(const point& p);
    virtual ~wall() = default;
    bool isAffected(const laser& l) const;
    void changeAffected() ;

private:
    bool d_affected;
};
#endif // WALL_H
