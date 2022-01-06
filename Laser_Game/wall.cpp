//Declaring libraries
#include "wall.h"
#include "object.h"
#include "point.h"
#include "laser.h"

//---------- Constructors------------------------------
wall::wall(const point& p) : object{p}
{}
//---------- End of constructors-----------------------
//---------- Methods ----------------------------------
void wall::collide(laser& l)
{
    if(getPosition() == l.getPosition())
    {
        l.setIsAlive(false);
    }
}

unique_ptr<object> wall::clone() const
{
    return make_unique<wall>(*this);
}

void wall::print(ostream& ost) const
{
    ost << toString();
}

string wall::toString() const
{
    return "Wall[position" + getPosition().toString() + ")]";
}
//---------- End of methods ----------------------------
