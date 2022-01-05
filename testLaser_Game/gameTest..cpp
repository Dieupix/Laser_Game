#include "../Laser_Game/game.h"
#include "../Laser_Game/ground.h"
#include "../Laser_Game/viewer.h"
#include "../Laser_Game/mirror.h"
#include "doctest.h"
#include <fstream>
#include <string>
#include<memory>


TEST_CASE("3 - Test of the class game" )
{
   point position(0, 0);
   ground terrain(position, 1.0, 1.0, 5, 5, 0);

   //game TGame(terrain ,std::make_unique<viewer>()  ) ;

    SUBCASE( " Test of the constructor " )
    {


    }
    SUBCASE( " Test of the constructor with ground " )
    {


    }
    SUBCASE(" Test add mirror ")
    {
    auto sensM = sens::basGauche_hautDroit ;
    point position{0, 0};
    point position2{3, 0};
/*
    TGame.addMirror(position,sensM) ;
    TGame.addMirror2(position,sensM) ;
    */


    }

}
