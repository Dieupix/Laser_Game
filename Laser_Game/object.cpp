#include "object.h"
#include "point.h"
#include <iostream>

/** Constructeur d'objet
@param p : un point x,y
@return un objet o{p}
*/
object::object(point p) : d_p{p}
{}

/** Constructeur par defaut d'objet
@return un objet o{0,0}
*/
 object::object() : d_p{0,0}
{}

/** Setter de point d'un objet
@param p : le nouveau point de l'objet
*/
void object::setPosition(const point& p)
{
    d_p = p;
}

/**Getter de point d'un objet
@return le point de l'objet courant
*/
point object::getPosition() const
{
    return d_p;
}

/**Deplace l'objet de x, y
@param x : le deplacement en abscisse (reel)
@param y : le deplacement en ordonnee (reel)
*/
void object::shift(double x, double y)
{
    d_p.shift(x,y);
}

/**Deplace l'objet par translation de p(x,y)
@param x : le deplacement en abscisse (reel)
@param y : le deplacement en ordonnee (reel)
*/
void object::shift(const point& p)
{
    d_p.shift(p.x(),p.y());
}

/**Deplace l'objet par de p(x,y)
@param x : le deplacement en abscisse (reel)
@param y : le deplacement en ordonnee (reel)
*/
void object::move(const point& p)
{
    d_p.move(p.x(),p.y());
}
/**Deplace l'objet par translation de p(x,y)
@param x : le deplacement en abscisse (reel)
@param y : le deplacement en ordonnee (reel)
*/
void object::move(double x, double y)
{
    d_p.move(x,y);
}

void object::collide(laser&) {}

unique_ptr<object> object::clone() const
{
    return make_unique<object>(*this);
}

void object::print(std::ostream& ost) const{
    ost << toString();
}

string object::toString() const{
    return d_p.toString();
}

/**Operateur d'egalite : test si la position d'un objet est la meme que celle passee en parametre
@param o : un objet
@return true ou false
*/
bool object::operator==(const object& o) const
{
    return d_p == o.getPosition();
}

/**Operateur d'inegalite : test si la position d'un objet est differente que celle passee en parametre
@param o : un objet
@return true ou false
*/
bool object::operator!=(const object& o) const
{
    return !(*this == o);
}

/**Surcharge de l'operateur << pour permettre d'afficher un objet (cout<<o)
@param ost : le flot de sortie
@param o : l'objet
*/
std::ostream& operator<<(std::ostream& ost, const object& o)
{
    //Afficheur d'objet
    o.print(ost);
    return ost;
}

object createObjectForTest(const point& p){
    return {p};
}
