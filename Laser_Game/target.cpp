#include"target.h"
#include"laser.h"
#include "object.h"

// ---------- Constructors ----------

    target::target(const point& position) : object{position}, d_affected{false}
    {

    }

// ---------- End of constructors ----------

// ---------- Setters ----------

void target::setAffected(bool b)
{
    d_affected = b;
}

// ---------- End of setters ----------

// ----------  Getters ----------

// ---------- End of Getters -----------------------------

// ---------- Functions isAffected ------------------------

bool target::isAffected() const
{
    return this->d_affected;
}

// ---------- End of isAffected  -----------------------------

unique_ptr<object> target::clone() const
{
    return make_unique<target>(*this);
}

void target::collide(laser& l)
{
    if(*this == l)
    {
        l.setIsAlive(false);
        d_affected = true;
    }
}


void target::print(std::ostream& ost) const
{
    ost << toString();
}

string target::toString() const
{
    return "Cible[position" + getPosition().toString() + ", affected(" + string(d_affected ? "true" : "false") + ")]";
}
