//Declaring libraries
#include "point.h"

//---------- Constructors------------------------------
point::point() : d_x{0.0}, d_y{0.0}
{}

point::point(double x, double y) : d_x{x}, d_y{y}
{}
//---------- End of constructors-----------------------
//---------- Getters-----------------------------------
double point::x() const
{
    return d_x;
}

double point::y() const
{
    return d_y;
}
//---------- End of getters ----------------------------
//---------- Methods -----------------------------------
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

void point::print(std::ostream& ost) const
{
    ost<<toString();
}

string point::toString() const
{
    return "(" + std::to_string(d_x) + "," + std::to_string(d_y) + ")";
}

void point::read(istream& ist)
{
    double a, b;
    char c;
    ist>>c>>a>>c>>b>>c;
    if(ist.good())
    {
        d_x = a;
        d_y = b;
    }
}
//---------- End of methods ----------------------------
//---------- Operators in class  -----------------------
bool point::operator==(const point& p) const
{
    return (d_x == p.x()) and (d_y == p.y());
}

bool point::operator!=(const point& p) const
{
    return (x() != p.x()) or (y() != p.y());
}

point point::operator=(const point& p) const
{
    return {p.x(), p.y()};
}

point& point::operator=(const point& p)
{
    if(this != &p)
    {
        d_x = p.x();
        d_y = p.y();
    }
    return *this;
}

point point::operator-() const
{
    double x = d_x == 0 ? 0 : -d_x;
    double y = d_y == 0 ? 0 : -d_y;
    return {x,y};
}

point point::operator+(const point& p) const
{
    point new_point{*this};
    new_point += p;
    return new_point;
}

point& point::operator+=(const point& p)
{
    d_x += p.x();
    d_y += p.y();
    return *this;
}

point point::operator-(const point& p) const
{
    point new_point{*this};
    new_point -= p;
    return new_point;
}

point& point::operator-=(const point& p)
{
    d_x -= p.x();
    d_y -= p.y();
    return *this;
}

point point::operator*(double coef) const
{
    point new_point{*this};
    new_point *= coef;
    return new_point;
}

point& point::operator*=(double coef)
{
    if(coef != 1){
        d_x *= coef;
        d_y *= coef;
    }
    return *this;
}

point point::operator/(double coef) const
{
    point new_point{*this};
    new_point /= coef;
    return new_point;
}

point& point::operator/=(double coef)
{
    if(coef != 1){
        d_x = d_x / coef;
        d_y = d_y / coef;
    }
    return *this;
}
//---------- End of Operators in class  ---------------
//---------- Operators outside class  -----------------
std::ostream& operator<<(std::ostream& ost, const point& p)
{
    p.print(ost);
    return ost;
}

std::istream& operator>>(std::istream& ist, point& p)
{
    p.read(ist);
    return ist;
}

point operator*(double coef, const point& p)
{
    return p*coef;
}
//---------- End of Operators outside class  ----------
