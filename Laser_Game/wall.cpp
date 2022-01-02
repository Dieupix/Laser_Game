#include "wall.h"

#include "object.h"
#include "point.h"
#include "laser.h"

/**Constructeur de la classe mur initialise a faux pour sa donnee estTouche
@param p : un point (x,y)
@return un mur m{false} avec une position*/
wall::wall(const point& p) : object{p}, d_affected{false}
{}

/**Dis si le mur a ete touche par un laser
@param l : le laser
@return VRAI si il a ete touche, FAUX sinon*/
bool wall::isAffected(laser& l) const
{
    if(getPosition() == l.getPosition())
    {
        l.setIsAlive(false);
        return true;
    }
    else
    {
        return false;
    }

}

/**Change la donnee du mur estTouche
*/
void wall::changeAffected()
{
    d_affected = !d_affected;
}

/**Imprime le mur
@param ost : le flot de sortie
*/
/*
void wall::print(std::ostream& ost) const
{
    getPosition().print(ost);
}
*/
