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
   mirror Tmiroir {position,sensM} ;


    SUBCASE("Test of the constructor sens")
    {

        REQUIRE_EQ(Tmiroir.getSens() ,  sens::basGauche_hautDroit );

    }
     SUBCASE("Test of the constructor position ")
     {

        REQUIRE_EQ(Tmiroir.getPosition() ,  position );

    }
    /*

   SUBCASE("Test of the function ChangeDirectionLaser ")
    {

    auto droit = directions::RIGHT;
    auto gauche = directions::RIGHT;
    double step = 1.0;

    auto TLaser = createLaserForTest(position, droit, step);
    auto TLaserFix = createLaserForTest(position, gauche, step);

    Tmiroir.changeDirectionLaser(TLaser) ;

    TLaser.turnLeft() ;
    REQUIRE_EQ(TLaser.getDirection() ,  TLaserFix.getDirection() );

    }
  */





     SUBCASE("Test of the print() function")
    {
        string expectedOutput = "Miroir [position(0,0), sens : basGauche_hautDroit, n'est pas touchee]";

        ostringstream ost;
        Tmiroir.print(ost);

        string read = ost.str();


        CHECK_EQ(read, expectedOutput);
    }

}

#endif // MIRRORTEST_H


