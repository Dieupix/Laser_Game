#include "doctest.h"
#include "../Laser_Game/miroir.h"
#include "../Laser_Game/laser.h"





TEST_CASE("Test of the class cible"){

   auto sensM = miroir::sens::basGauche_hautDroit ;
   point position{0, 0};
   miroir m {position,sensM} ;
    SUBCASE("Test of the constructor sens"){
        /// @TODO - add the REQUIRE for the sens
        REQUIRE_EQ(m.getSens() ,  miroir::sens::basGauche_hautDroit );

    }
     SUBCASE("Test of the constructor position "){
        /// @TODO - add the REQUIRE for the position
        REQUIRE_EQ(m.getPosition() ,  position );

    }


}
