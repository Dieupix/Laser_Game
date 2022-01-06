#ifndef TARGETTEST_H_INCLUDED
#define TARGETTEST_H_INCLUDED

#include "doctest.h"
#include "../Laser_Game/target.h"
#include "../Laser_Game/laser.h"
#include <string>
#include <sstream>

using std::ostringstream;
using std::string;

TEST_CASE("2 - Test of the class target")
{
    point P{0,0};
    target tar{P};
    auto direction = directions::RIGHT;
    double step = 1.0;
    auto l = createLaserForTest(P, direction, step);
    SUBCASE("Test of the constructor")
    {
        REQUIRE_EQ(tar.getPosition(), P);
    }
    SUBCASE("Test of the position")
    {
        REQUIRE_EQ(tar.getPosition(), P);
    }
    SUBCASE("Test of is affected ")
    {
        REQUIRE(tar.isAffected() == false);
    }
    SUBCASE("Test of set affected ")
    {
        tar.setAffected(true);
        REQUIRE(tar.isAffected() == true);
    }
    SUBCASE("Test of Clone ")
    {
        SUBCASE("Test clone when target  is affected  ")
        {
            tar.collide(l);
            REQUIRE(tar.isAffected() == true);
        }
        SUBCASE("Test clone when target is not affected  ")
        {
            tar.collide(l);
            REQUIRE(tar.isAffected() == false ) ;
        }
    }
    SUBCASE("Test of the print() function")
    {
        string expectedOutput = "Cible[position(0.000000,0.000000), affected(true)]";
        ostringstream ost;
        tar.collide(l);
        tar.print(ost);
        string read = ost.str();
        CHECK_EQ(read, expectedOutput);
        SUBCASE("Test if the print if target is not affected")
        {
            point A{10, 0} ;
            target new_tar(A) ;
            string expectedOutput = "Cible[position(10.000000,0.000000), affected(false)]";
            ostringstream ost;
            new_tar.collide(l) ;
            new_tar.print(ost);
            string read = ost.str();
            CHECK_EQ(read, expectedOutput);

        }
    }
}

#endif //TARGETTEST_H_INCLUDED
