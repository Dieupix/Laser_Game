#ifndef CIBLE_H_INCLUDED
#define CIBLE_H_INCLUDED
//Declaring libraries
#include "object.h"

//Declaring namespace elements
using std::cout;
using std::cin;
using std::string;

/**
 * @class monster monster.h
 * @brief A class that represents a monster
 * @details This class represents a monster, with a @a name, an @a affectation, which a @a position
*/
class monster : public object
{
public :
        /**
        * @brief Constructor of monster
        *
        * @param position : the position of the monster
        * @param name : the name of the monster
        *
        * @return Create a monster with a position and a name
        */
        monster(const point& position , std::string name);

        /**
        * @brief Virtual destructor by default of object
        */
        virtual ~monster() = default;

        /**
        * @brief Function that set name of the monster
        *
        * @return void
        */
        void setName(const string& name);

        /**
        * @brief Function that set affectation of the monster
        *
        * @param b : a boolean
        *
        * @return void
        */
        void setAffected(bool b);

        /**
        * @brief Function that get name of the monster
        *
        * @return the current name of the current monster
        */
        std::string getName() const;

        /**
        * @brief Function that get affectation of the monster
        *
        * @return the current affectation of the current monster
        */
        bool isAffected() const;

        /**
        * @brief Virtual function override that allows to clone a smart pointer of monster
        *
        * @return a new smart pointer of object
        */
        virtual unique_ptr<object> clone() const override;

        /**
        * @brief Virtual procedure that allows to test if the current monster has the same position in the ground that a laser
        *
        * @param l : new laser
        *
        * @return void
        */
        virtual void collide(laser& l);

        /**
        * @brief Virtual procedure that allows to print characteristics of monster
        *
        * @return void
        */
        virtual void print(std::ostream& ost) const override;

        /**
        * @brief Virtual function that allows to convert a monster in string
        *
        * @return a string
        */
        virtual string toString() const override;

    private :
        //The name of the monster
        std::string d_name;
        //The affectation of the monster
        bool d_affected;
};

#endif // MONSTER_H_INCLUDED
