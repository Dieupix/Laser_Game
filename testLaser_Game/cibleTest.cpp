#ifndef CIBLETEST_H_INCLUDED
#define CIBLETEST_H_INCLUDED
#include "doctest.h"
#include "../Laser_Game/cible.h"
#include "../Laser_Game/laser.h"


#include <string>
#include <sstream>

using std::ostringstream;
using std::string;



TEST_CASE("2 - Test of the class cible")
{



    SUBCASE("Test of the constructor")
    {
        point P{0, 0} ;
        cible c (P) ;
        REQUIRE_EQ(c.getPosition(), P);

    }

    SUBCASE("Test of the  position")
    {
        point P{1, 10} ;
        cible c (P) ;
        REQUIRE_EQ(c.getPosition(), P);

    }



    //-------------- isAffected ------------------------------------------


/*
    SUBCASE("Test of is affected ")
    {

        point position{0, 0};
        auto direction = directions::RIGHT;
        double step = 1.0;

        auto l = createLaserForTest(position, direction, step);
        SUBCASE("Test  is affected ")
        {
            point P{0, 0} ;
            cible c (P) ;
            REQUIRE(c.isAffected(l) == true ) ;
        }
        SUBCASE("Test  is NOT affected ")
        {
            point P{0, 0} ;
            cible c (P) ;
            REQUIRE(c.isAffected(l) == false ) ;
        }


    }

    //-----------------print------------------------------------------
    point p{0, 0} ;
    cible c (p) ;
    auto direction = directions::RIGHT;
    double step = 1.0;
    auto l = Create_laser(p, direction, step);
    SUBCASE("Test of the print() function")
    {
        string expectedOutput = "Cible[position(0,0), est touch�e par un laser]";
        ostringstream ost;
        c.isAffected(l) ;
        c.print(ost);
        string read = ost.str();
        CHECK_EQ(read, expectedOutput);
        SUBCASE("Test if the print if cible is not affected")
        {
            point A{10, 0} ;
            cible c (A) ;
            string expectedOutput = "Cible[position(0,0), n'est pas touch�e par un laser]";
            ostringstream ost;
            c.isAffected(l) ;
            c.print(ost);
            string read = ost.str();
            CHECK_EQ(read, expectedOutput);

        }

    }
    //------------operator-----------------------------------
    SUBCASE("Test operator ")
    {

        SUBCASE("Test operator == object ")
        {
            point p{0, 0} ;
            cible c (p) ;
            auto direction = directions::RIGHT;
            double step = 1.0;
            auto l = createLaserForTest(p, direction, step);
            bool resultat  = ( c==l) ;
            CHECK_EQ(resultat, true);
        }

        SUBCASE("Test operator != object ")
        {


            point p{0, 0} ;
            cible c (p) ;
            point p2{10, 0} ;
            auto direction = directions::RIGHT;
            double step = 1.0;
            auto l = createLaserForTest(p2, direction, step);
            bool resultat  = ( c!=l) ;
            CHECK_EQ(resultat, false);
        }
    }
*/

}
#endif //CIBLETEST_H_INCLUDED
