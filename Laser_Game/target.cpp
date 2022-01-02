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
    ost << toString();
}

string target::toString() const
{
    return "Cible[position" + getPosition().toString() + ", affected(" + string(d_affected ? "true" : "false") + ")]";
}
