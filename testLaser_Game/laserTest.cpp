#include "doctest.h"
#include "../Laser_Game/laser.h"

TEST_CASE("Test of the class laser"){
    point position{0, 0};
    short short int direction = laser::directions::RIGHT;
    double step = 1.0;

    laser l {position, direction, step};

    SUBCASE("Test of the constructor"){
        /// @TODO - add the REQUIRE for the position
        REQUIRE_EQ(l.getDirection(), direction);
        REQUIRE_EQ(l.getStep(), step);
    }
}
