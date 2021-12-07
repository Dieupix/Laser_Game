#include "doctest.h"
#include "../Laser_Game/miroir.h"

TEST_CASE("Test of the class cible"){

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


}
