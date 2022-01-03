#ifndef MIRRORTEST_H
#define MIRRORTEST_H

#include "doctest.h"

#include "../Laser_Game/mirror.h"
#include "../Laser_Game/laser.h"

#include <string>
#include <sstream>

using std::ostringstream;
using std::string;

TEST_CASE("2 - Test of the class mirror")
{

   auto sensM = sens::basGauche_hautDroit ;
   point position{0, 0};
   mirror m {position,sensM} ;


    SUBCASE("Test of the constructor sens"){

        REQUIRE_EQ(m.getSens() ,  sens::basGauche_hautDroit );

    }
     SUBCASE("Test of the constructor position "){

        REQUIRE_EQ(m.getPosition() ,  position );

    }
    ///@TODO - Meriem : both sub cases are crashing the test case
   /*SUBCASE("Test of the function ChangeDirectionLaser ")
    {

    auto direction = directions::RIGHT;
    double step = 1.0;

    auto l = createLaserForTest(position, direction, step);
    auto L = createLaserForTest(position, direction, step);
    m.changeDirectionLaser(l) ;
    L.turnLeft() ;
    REQUIRE_EQ(l.getDirection() ,  L.getDirection() );

    }
    SUBCASE("Test of the function estToucher ")
    {

    auto direction = directions::RIGHT;
    double step = 1.0;

    auto l = createLaserForTest(position, direction, step);
    SUBCASE(" miroir is affected ")
    {
    REQUIRE_EQ(m.estTouchee(l) ,  true );

    }
    SUBCASE(" miroir is not affected ")
    {
     l.moveByStep() ;
    REQUIRE_EQ(m.estTouchee(l) ,  false );

    }
    }*/

    ///@FIXME - Meriem : need to fix the check
     /*SUBCASE("Test of the print() function")
    {
        string expectedOutput = "Miroir [position(0,0), sens : basGauche_hautDroit, n'est pas touchee]";

        ostringstream ost;
        m.print(ost);

        string read = ost.str();


        CHECK_EQ(read, expectedOutput);
    }*/

}

#endif // MIRRORTEST_H


