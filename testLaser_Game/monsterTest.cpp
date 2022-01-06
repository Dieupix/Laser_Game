#ifndef monsterTEST_H_INCLUDED
#define monsterTEST_H_INCLUDED

#include "doctest.h"
#include "../Laser_Game/monster.h"
#include "../Laser_Game/laser.h"
#include <string>
#include <sstream>

using std::ostringstream;
using std::string;

TEST_CASE("7 - Test of the class monster" * doctest::skip(true))
{
    point P{0, 0};
    std::string name = "monster";
    monster M (P,name);
    auto direction = directions::RIGHT;
    double step = 1.0;
    auto l = createLaserForTest(P, direction, step);

    SUBCASE("Test of the constructor monster")
    {
        REQUIRE_EQ(M.getPosition(), P);
        REQUIRE_EQ(M.getName(), name);
    }
    SUBCASE("Test of is affected ")
    {
        REQUIRE(M.isAffected() == false ) ;
    }
    SUBCASE("Test of set affected ")
    {
        M.setAffected(true) ;
        REQUIRE(M.isAffected() == true);
    }
    SUBCASE("Test of Clone ")
    {
        SUBCASE("Test clone when monster  is affected  ")
        {
            M.collide(l) ;
            REQUIRE(M.isAffected() == true);
        }
        SUBCASE("Test clone when monster is not affected  ")
        {
            M.collide(l) ;
            REQUIRE(M.isAffected() == false);
        }
    }
    SUBCASE("Test of the print() function")
    {
        string expectedOutput = "monster[position(0,0), est touchée par un laser]";
        ostringstream ost;
        M.collide(l) ;
        M.print(ost);
        string read = ost.str();
        CHECK_EQ(read, expectedOutput);
        SUBCASE("Test if the print if monster is not affected")
        {
            point A{12, 0} ;
            monster M_2(A, name) ;
            string expectedOutput = "monster[position(0,0), n'est pas touchée par un laser]";
            ostringstream ost;
            M_2.collide( l) ;
            M_2.print(ost);
            string read = ost.str();
            CHECK_EQ(read, expectedOutput);
        }
    }
}

#endif //monsterTEST_H_INCLUDED
