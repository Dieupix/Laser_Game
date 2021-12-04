#include "doctest.h"

#include "../Laser_Game/object.h"

object createObjectForTest(const point& p){
    return {p};
}

TEST_CASE("Test of the class object"){
    point position{1, 1};
    point position_deplace {2,5};
    object obj = createObjectForTest(position);

    SUBCASE("Test of the constructor"){
        REQUIRE_EQ(obj.getPosition(), position);
    }

    SUBCASE("Test of moveObject"){
        obj.move(position_deplace);
        REQUIRE_EQ(obj.getPosition(), point{2,5} );
    }

    SUBCASE("Test of shiftObject"){
        obj.shift(position_deplace);
        REQUIRE_EQ(obj.getPosition(), point{3,6} );
    }
}

