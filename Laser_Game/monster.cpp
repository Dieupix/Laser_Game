//Declaring libraries
#include"monster.h"
#include"laser.h"
#include "object.h"

//---------- Constructors------------------------------
monster::monster(const point& position, std::string name) :     object{position},
                                                                d_name{name} ,
                                                                d_affected{false}
{}
//---------- End of constructors-----------------------
//---------- Setter------------------------------------
void monster::setName(const string& name)
{
    d_name = name;
}

void monster::setAffected(bool b)
{
    d_affected = b;
}
//---------- End of Setter-----------------------------
//---------- Getter------------------------------------
std::string monster::getName() const
{
    return this->d_name;
}

bool monster::isAffected() const
{
    return this->d_affected;
}
//---------- End of Getter-----------------------------
//---------- Methods ----------------------------------
unique_ptr<object> monster::clone() const
{
    return make_unique<monster>(*this);
}

void monster::collide(laser& l)
{
    if(*this == l)
    {
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
//---------- End of methods ----------------------------
