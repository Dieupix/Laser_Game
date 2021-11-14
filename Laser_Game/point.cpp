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
<<<<<<< HEAD

std::ostream& operator<<(std::ostream& ost, const point& p){
    p.print(ost);
    return ost;
}

std::istream& operator>>(std::istream& ist, point& p){
    p.read(ist);
    return ist;
}

point operator*(double d, const point& p){
    return p*d;
}

 bool point::operator==(const point& p) const{
        return (d_x == p.x()) and (d_y == p.y());
    }

    bool point::operator!=(const point& p) const{
        return (x() != p.x()) or (y() != p.y());
    }

    point point::operator=(const point& p) const{
        return {p.x(), p.y()};
    }

    point& point::operator=(const point& p){
        if(this != &p){
            d_x = p.x();
            d_y = p.y();
        }
        return *this;
    }

    point point::operator-() const{
        double x = d_x == 0 ? 0 : -d_x;
        double y = d_y == 0 ? 0 : -d_y;
        return {x, y};
    }

    point point::operator+(const point& p) const{
        point tmp{*this};
        tmp += p;
        return tmp;
    }

    point& point::operator+=(const point& p) {
        d_x += p.x();
        d_y += p.y();
        return *this;
    }

    point point::operator-(const point& p) const{
        point tmp{*this};
        tmp -= p;
        return tmp;
    }

    point& point::operator-=(const point& p){
        d_x -= p.x();
        d_y -= p.y();
        return *this;
    }

    point point::operator*(double d) const{
        point tmp{*this};
        tmp *= d;
        return tmp;
    }

    point& point::operator*=(double d){
        if(d != 1){
            d_x *= d;
            d_y *= d;
        }
        return *this;
    }

    point point::operator/(double d) const{
        point tmp{*this};
        tmp /= d;
        return tmp;
    }

    point& point::operator/=(double d){
        if(d != 1){
            d_x = d_x / d;
            d_y = d_y / d;
        }
        return *this;
    }
=======
bool point::operator==(const point& b) const
{
    return (( d_x ==b.x())&& ( d_y ==b.y()) ) ;
}
>>>>>>> 3d12b6ff4c7376e5ff4ea871ba02ad4793bd6617
