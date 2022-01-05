#include"monster.h"
#include"laser.h"
#include "object.h"

// ---------- Constructors ----------

    monster::monster(const point& position, std::string name) : object{position}, d_name{name} ,  d_affected{false}
    {

    }

// ---------- End of constructors ----------

// ---------- Setters ----------

void monster::setAffected(bool b)
{
    d_affected = b;
}

// ---------- End of setters ----------

    void monster::setName()
    {
        std::cout<<" Saisir le nom "<<std::endl ;
        std::string name ;
        std::cin>>name ;
        d_name = name ;
    }
// ----------  Getters ----------

// ---------- End of Getters -----------------------------
    std::string monster::getName() const
    {
        return d_name ;     }
// ---------- Functions isAffected ------------------------

bool monster::isAffected() const
{
    return this->d_affected;
}

// ---------- End of isAffected  -----------------------------

unique_ptr<object> monster::clone() const
{
    return make_unique<monster>(*this);
}

void monster::collide(laser& l)
{
    if(*this == l)
    {
        l.setIsAlive(false);
        d_affected = true;
    }
}


void monster::print(std::ostream& ost) const
{
    ost << toString();
}

string monster::toString() const
{
    return "monster[Name"+ getName() ," position" + getPosition().toString() + ", affected(" + string(d_affected ? "true" : "false") + ")]";
}
