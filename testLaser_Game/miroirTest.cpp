#include "doctest.h"
#include "../Laser_Game/miroir.h"

#include <string>
#include <sstream>

using std::ostringstream;
using std::string;

TEST_CASE("2 - Test of the class mirror"){

   auto sensM = sens::basGauche_hautDroit ;
   point position{0, 0};
   miroir m {position,sensM} ;


    SUBCASE("Test of the constructor sens"){
        /// @TODO - add the REQUIRE for the sens
        REQUIRE_EQ(m.getSens() ,  sens::basGauche_hautDroit );

    }
     SUBCASE("Test of the constructor position "){
        /// @TODO - add the REQUIRE for the position
        REQUIRE_EQ(m.getPosition() ,  position );

    }
   /* SUBCASE("Test of the function ChangeDirectionLaser ")
    {

    auto direction = directions::RIGHT;
    double step = 1.0;

    auto l = createLaserForTest(position, direction, step);
    auto L = createLaserForTest(position, direction, step);
    m.changeDirectionLaser(l) ;
    L.turnLeft() ;
    REQUIRE_EQ(l.getDirection() ,  L.getDirection() );

    }*/
    /* SUBCASE("Test of the function estToucher ")
    {

    auto direction = directions::RIGHT;
    double step = 1.0;

    auto l = createLaserForTest(position, direction, step);
    Subcase(" miroir is affected ")
    {
    REQUIRE_EQ(m.estTouchee(l) ,  true );

    }
    Subcase(" miroir is not affected ")
    {
     l.moveByStep() ;
    REQUIRE_EQ(m.estTouchee(l) ,  false );

    }
    }*/

     SUBCASE("Test of the print() function")
    {
        string expectedOutput = "Miroir [position(0,0), sens : basGauche_hautDroit, n'est pas touchee]";

        ostringstream ost;
        m.print(ost);

        string read = ost.str();

        //CHECK_EQ(read, "I want you to fail"); // SHOULD FAIL
        CHECK_EQ(read, expectedOutput);
    }








}
