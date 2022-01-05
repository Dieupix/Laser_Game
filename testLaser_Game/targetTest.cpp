#ifndef TARGETTEST_H_INCLUDED
#define TARGETTEST_H_INCLUDED

#include "doctest.h"

#include "../Laser_Game/target.h"
#include "../Laser_Game/laser.h"

#include <string>
#include <sstream>

using std::ostringstream;
using std::string;



TEST_CASE("2 - Test of the class target"
          * doctest::skip(true))
{



    SUBCASE("Test of the constructor")
    {
        point P{0, 0} ;
        target c (P) ;
        REQUIRE_EQ(c.getPosition(), P);

    }

    SUBCASE("Test of the  position")
    {
        point P{1, 10} ;
        target c (P) ;
        REQUIRE_EQ(c.getPosition(), P);

    }



    //-------------- isAffected ------------------------------------------

   SUBCASE("Test of is affected ")
    {
            point P{0, 0} ;
            target c (P) ;

                 REQUIRE(c.isAffected() == false ) ;


    }
     SUBCASE("Test of set affected ")
    {
            point P{0, 0} ;
            target c (P) ;
            c.setAffected(true) ;
            REQUIRE(c.isAffected() == true ) ;


    }

    SUBCASE("Test of Clone ")
    {

        point position{0, 0};
        auto direction = directions::RIGHT;
        double step = 1.0;

        auto l = createLaserForTest(position, direction, step);
        SUBCASE("Test clone when target  is affected  ")
        {
            point P{0, 0} ;
            target c (P) ;
            c.collide( l) ;
            REQUIRE(c.isAffected() == true ) ;
        }
        SUBCASE("Test clone when target is not affected  ")
        {
            point P{1, 0} ;
            target c (P) ;
            c.collide( l) ;
            REQUIRE(c.isAffected() == false ) ;
        }


    }

    //-----------------print------------------------------------------
    point p{0, 0} ;
    target c (p) ;
    auto direction = directions::RIGHT;
    double step = 1.0;
    auto l = createLaserForTest(p, direction, step);
    SUBCASE("Test of the print() function")
    {
        string expectedOutput = "target[position(0,0), est touchée par un laser]";
        ostringstream ost;
        c.collide( l) ;

        c.print(ost);
        string read = ost.str();
        CHECK_EQ(read, expectedOutput);
        SUBCASE("Test if the print if target is not affected")
        {
            point A{10, 0} ;
            target c (A) ;
            string expectedOutput = "target[position(0,0), n'est pas touchée par un laser]";
            ostringstream ost;
            c.collide( l) ;
            c.print(ost);
            string read = ost.str();
            CHECK_EQ(read, expectedOutput);

        }

    }

}

#endif //TARGETTEST_H_INCLUDED
