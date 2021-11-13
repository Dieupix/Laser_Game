#include "doctest.h"
#include "../Laser_Game/cible.h"
#include "../Laser_Game/laser.h"

TEST_CASE("Test of the class cible"){

    point position{0, 0} ;
   cible c (position) ;

    SUBCASE("Test of the constructor"){
        /// @TODO - add the REQUIRE for the position
        REQUIRE_EQ(c.getCible(), position);

    }

    //-----------------moveCible--------------------------------
    point A{2, 3};
     c.moveCible(A) ;

       SUBCASE("Test of moveCible "){
        /// @TODO - add the REQUIRE for the position
        REQUIRE_EQ(c.getCible(), A);

    }
    //-------------- isAffected ------------------------------------------

         point position{0, 0};
    short short int direction = laser::directions::RIGHT;
    double step = 1.0;

    laser l {position, direction, step};

      point B{0, 0 };
     c.moveCible(b) ;

       SUBCASE("Test of is affected "){
        /// @TODO - add the REQUIRE for the position
        REQUIRE(c.isAffected() == true ) ;

    }

}
