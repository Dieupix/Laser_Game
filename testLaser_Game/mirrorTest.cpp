#ifndef MIRRORTEST_H
#define MIRRORTEST_H

#include "doctest.h"

#include "../Laser_Game/mirror.h"
#include "../Laser_Game/laser.h"

#include <string>
#include <sstream>

using std::ostringstream;
using std::string;

TEST_CASE("2 - Test of the class mirror")
{

    auto sensM = sens::basGauche_hautDroit ;
    point position{0, 0};
    mirror Tmiroir {position,sensM} ;


    SUBCASE("Test of the constructor sens")
    {

        REQUIRE_EQ(Tmiroir.getSens(),  sens::basGauche_hautDroit );

    }
    SUBCASE("Test of the constructor position ")
    {

        REQUIRE_EQ(Tmiroir.getPosition(),  position );

    }


    SUBCASE("Test of the function ChangeDirectionLaser ")
    {

        auto haut = directions::UP;
        auto bas = directions::DOWN ;
        auto droit = directions::RIGHT;
        auto gauche = directions::LEFT ;

        double step = 1.0;



        auto TLaserHAUT_FIX= createLaserForTest(position, haut, step);
        auto TLaserDroit_FIX = createLaserForTest(position, droit, step);
        auto TLaserGauche_FIX = createLaserForTest(position, gauche, step);
        auto TLaserBas_FIX = createLaserForTest(position, bas, step);



        SUBCASE( " test miroir basGauche_hautDROIT")
        {
            SUBCASE(" test laser up or donw")
            {
                auto TLaserBas = createLaserForTest(position, bas, step);
                Tmiroir.changeDirectionLaser(TLaserBas) ;
                REQUIRE_EQ(TLaserBas.getDirection(),  TLaserGauche_FIX.getDirection() );

            }
            SUBCASE(" test laser left or  right")
            {

                auto TLaserDroit = createLaserForTest(position, droit, step);
                Tmiroir.changeDirectionLaser(TLaserDroit) ;
                REQUIRE_EQ(TLaserDroit.getDirection(),  TLaserHAUT_FIX.getDirection() );

            }
        }
        SUBCASE( " test miroir hautGauche_basDroit")
        {
            auto sensHAUT_GAUCHE = sens::hautGauche_basDroit ;// ( \ )
            mirror Tmiroir2 {position,sensHAUT_GAUCHE} ;

            SUBCASE(" test laser left or  right")
            {
                // ---- \
               //       |

                auto TLaserGacuhe = createLaserForTest(position, droit, step);
                Tmiroir2.changeDirectionLaser(TLaserGacuhe) ;

                REQUIRE_EQ(TLaserGacuhe.getDirection(),  TLaserBas_FIX.getDirection() );

            }
            SUBCASE(" test laser up or donw")
            {       // |
                   /*  \  -- */
                auto TLaserHAUT= createLaserForTest(position, haut, step);
                Tmiroir2.changeDirectionLaser(TLaserHAUT) ;
                REQUIRE_EQ(TLaserHAUT.getDirection(),  TLaserGauche_FIX.getDirection() );

            }

        }




    }






    SUBCASE("Test of the print() function")
    {
        string expectedOutput = "Miroir[position(0.000000,0.000000), sens( basGauche_hautDroit ), affected(false)]";
        ostringstream ost;
        Tmiroir.print(ost);

        string read = ost.str();


        CHECK_EQ(read, expectedOutput);
    }

}

#endif // MIRRORTEST_H


