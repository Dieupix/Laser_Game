#ifndef monsterTEST_H_INCLUDED
#define monsterTEST_H_INCLUDED

#include "doctest.h"

#include "../Laser_Game/monster.h"
#include "../Laser_Game/laser.h"

#include <string>
#include <sstream>

using std::ostringstream;
using std::string;



TEST_CASE("7 - Test of the class monster"
          * doctest::skip(true))

{



    SUBCASE("Test of the constructor monster")
    {
        point P{0, 0} ;
        std::string name = "popo" ;
        monster M (P, name) ;

        REQUIRE_EQ(M.getPosition(), P);
        REQUIRE_EQ(M.getName(), name);

    }





    //-------------- isAffected ------------------------------------------


    SUBCASE("Test of is affected ")
    {
        point P{0, 0} ;
        std::string name = "popo" ;
        monster M (P, name) ;


        REQUIRE(M.isAffected() == false ) ;


    }
    SUBCASE("Test of set affected ")
    {
        point P{0, 0} ;
        std::string name = "popo" ;
        monster M (P, name) ;
        M.setAffected(true) ;
        REQUIRE(M.isAffected() == true ) ;


    }

    SUBCASE("Test of Clone ")
    {

        point position{0, 0};
        auto direction = directions::RIGHT;
        double step = 1.0;

        auto l = createLaserForTest(position, direction, step);
        SUBCASE("Test clone when monster  is affected  ")
        {
            point P{0, 0} ;
            std::string name = "popo" ;
            monster M (P, name) ;
            M.collide( l) ;
            REQUIRE(M.isAffected() == true ) ;
        }
        SUBCASE("Test clone when monster is not affected  ")
        {
            point P{0, 0} ;
            std::string name = "popo" ;
            monster M (P, name) ;
            M.collide( l) ;
            REQUIRE(M.isAffected() == false ) ;
        }


    }

    //-----------------print------------------------------------------
    point P{0, 0} ;
    std::string name = "popo" ;
    monster M (P, name) ;
    auto direction = directions::RIGHT;
    double step = 1.0;
    auto l = createLaserForTest(P, direction, step);
    SUBCASE("Test of the print() function")
    {
        string expectedOutput = "monster[position(0,0), est touchée par un laser]";
        ostringstream ost;
        M.collide( l) ;

        M.print(ost);
        string read = ost.str();
        CHECK_EQ(read, expectedOutput);
        SUBCASE("Test if the print if monster is not affected")
        {
            point A{12, 0} ;
            std::string name = "popo" ;
            monster M (A, name) ;
            string expectedOutput = "monster[position(0,0), n'est pas touchée par un laser]";
            ostringstream ost;
            M.collide( l) ;
            M.print(ost);
            string read = ost.str();
            CHECK_EQ(read, expectedOutput);

        }

    }

}

#endif //monsterTEST_H_INCLUDED
