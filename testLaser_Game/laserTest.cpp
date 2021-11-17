#include "doctest.h"
#include "../Laser_Game/laser.h"

TEST_CASE("Test of the class laser"){
    point position{0, 0};
    auto direction = laser::directions::RIGHT;
    double step = 1.0;

    laser l {position, direction, step};

    SUBCASE("Test of the constructor"){
        //REQUIRE_EQ(l.getPosition(), point{-1, -1}); // SHOULD FAIL
        REQUIRE_EQ(l.getPosition(), position);
        REQUIRE_EQ(l.getDirection(), direction);
        REQUIRE_EQ(l.getStep(), step);
    }

    SUBCASE("Test of the setters"){
        SUBCASE("Test of the direction setter"){
            auto newDirection = laser::directions::LEFT;
            l.setDirection(newDirection);

            //REQUIRE_EQ(l.getDirection(), laser::directions::UP); // SHOULD FAIL
            REQUIRE_EQ(l.getDirection(), newDirection);
        }

        SUBCASE("Test of the step setter"){
            double newStep = 2.5;
            l.setStep(newStep);

            //REQUIRE_EQ(l.getStep(), 1.6); // SHOULD FAIL
            REQUIRE_EQ(l.getStep(), newStep);
        }
    }

    SUBCASE("Test of the moveByStep() function"){
        point expectedPosition {1.0, 0};
        l.moveByStep();

        //REQUIRE_EQ(l.getPosition(), point{-1.5, 0}); // SHOULD FAIL
        REQUIRE_EQ(l.getPosition(), expectedPosition);
    }

    SUBCASE("Test of the turning functions"){
        SUBCASE("Test of the turnLeft() function"){
            auto expectedDirection = laser::directions::UP;
            l.turnLeft();

            //REQUIRE_EQ(l.getDirection(), laser::directions::DOWN); // SHOULD FAIL
            REQUIRE_EQ(l.getDirection(), expectedDirection);
        }

        SUBCASE("Test of the turnRight() function"){
            auto expectedDirection = laser::directions::DOWN;
            l.turnRight();

            //REQUIRE_EQ(l.getDirection(), laser::directions::UP); // SHOULD FAIL
            REQUIRE_EQ(l.getDirection(), expectedDirection);
        }
    }
}
