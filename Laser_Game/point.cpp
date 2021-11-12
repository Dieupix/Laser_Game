#include "point.h"

point::point() : d_x{0.0}, d_y{0.0}
{}

point::point(double x, double y) : d_x{x}, d_y{y}
{}

double point::x() const
{
    return d_x;
}

double point::y() const
{
    return d_y;
}

void point::move(double x, double y)
{
    d_x = x;
    d_y = y;
}

void point::shift(double x, double y)
{
    d_x += x;
    d_y += y;
}

void point::read(std::istream& ist)
{
    double a, b;
    ist>>a>>b;
    if(ist.good())
    {
        d_x = a;
        d_y = b;
    }
}

void point::print(std::ostream& ost) const
{
    ost<<'('<<d_x<<','<<d_y<<')';
}
