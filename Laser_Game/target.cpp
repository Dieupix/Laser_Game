#include"target.h"
#include"laser.h"
#include "object.h"

// ---------- Constructors ----------

    target::target(const point& position) : object{position}, d_affected{false}
    {

    }

// ---------- End of constructors ----------

// ---------- Setters ----------

// ---------- End of setters ----------

// ----------  Getters ----------

// ---------- End of Getters -----------------------------

// ---------- Functions isAffected ------------------------

    bool target::isAffected(laser& L )
    {

        if(getPosition() == L.getPosition())
        {
            L.setIsAlive(false);
            d_affected = true;
            return true;
        }
        else
        {
            return false;
        }
    }

// ---------- End of isAffected  -----------------------------



void target::print(std::ostream& ost) const
{
    ost << "Cible[position" << getPosition() <<", ";
    if( d_affected )
        ost<<"est touchée par un laser" ;
    else
         ost<<"n'est pas touchée par un laser" ;


 ost<<"]";
}

bool target::operator==(const object& a ) const
{
     return getPosition() == a.getPosition() ;

}
bool target::operator!=(const object& a ) const
{
    return getPosition() == a.getPosition() ;

}

