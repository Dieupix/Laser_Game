#include "doctest.h"
#include "../Laser_Game/objet.h"
#include "../Laser_Game/point.h"

TEST_CASE("Test of the class object"){
    point position{1, 1};
    point position_deplace {2,5};
    objet o {position};

    SUBCASE("Test of the constructor"){
        /// @TODO - add the REQUIRE for the position
        REQUIRE_EQ(o.getPosition(), position);
    }

    SUBCASE("Test of moveObject"){
        o.move(position_deplace);
        REQUIRE_EQ(o.getPosition(), {3,6} );
    }

    SUBCASE("Test of shiftObject"){
        o.shift(position_deplace);
        REQUIRE_EQ(o.getPosition(), {2,5} );
    }
}
