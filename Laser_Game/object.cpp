//Declaring libraries
#include "object.h"
#include "point.h"

//---------- Constructors------------------------------
object::object(point p) : d_p{p}
{}

 object::object() : d_p{0,0}
{}
//---------- End of constructors-----------------------
//---------- Setter------------------------------------
void object::setPosition(const point& p)
{
    d_p = p;
}
//---------- End of Setter-----------------------------
//---------- Getter------------------------------------
point object::getPosition() const
{
    return d_p;
}
//---------- End of Getter-----------------------------
//---------- Methods ----------------------------------
void object::shift(double x, double y)
{
    d_p.shift(x,y);
}

void object::shift(const point& p)
{
    d_p.shift(p.x(),p.y());
}

void object::move(const point& p)
{
    d_p.move(p.x(),p.y());
}

void object::move(double x, double y)
{
    d_p.move(x,y);
}

void object::collide(laser& l)
{}

unique_ptr<object> object::clone() const
{
    return make_unique<object>(*this);
}

void object::print(std::ostream& ost) const
{
    ost << toString();
}

string object::toString() const
{
    return d_p.toString();
}
//---------- End of methods ----------------------------
//---------- Operators in class  -----------------------
bool object::operator==(const object& o) const
{
    return d_p == o.getPosition();
}

bool object::operator!=(const object& o) const
{
    return !(*this == o);
}
//---------- End of Operators in class  ---------------
//---------- Operators outside class  -----------------
std::ostream& operator<<(std::ostream& ost, const object& o)
{
    o.print(ost);
    return ost;
}
//---------- End of Operators outside class  ----------
//---------- Globals Methods --------------------------
object createObjectForTest(const point& p)
{
    return {p};
}
//---------- End of Globals Methods -------------------
