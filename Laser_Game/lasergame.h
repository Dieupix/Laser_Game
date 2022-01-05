#ifndef LASERGAME_H
#define LASERGAME_H

//Declaring libraries
#include "game.h"

//Declaring namespace elements
using std::cout;
using std::endl;

/**
 * @class lasergame lasergame.h
 * @brief A class that represents a laser game
 * @details This class represents a laser game, with a @a viewer
*/
class lasergame
{
    public:
        /**
        * @brief Constructor by default of lasergame (by default viewerOnTerminal)
        *
        * @return Create a lasergame with a viewer (by default viewerOnTerminal)
        */
        lasergame();

        /**
        * @brief Virtual destructor by default of lasergame
        */
        virtual ~lasergame() = default;

        /**
        * @brief Procedure that allows to print a menu
        *
        * @return void
        */
        void menu();

        /**
        * @brief Procedure that allows to make a choice between different types of viewers
        *
        * @return void
        */
        void GraphicType();

        /**
        * @brief Procedure that allows to print grounds of a game (in a file or repertory)
        *
        * @param path : the name of the file (const string)
        *
        * @return void
        */
        void printGround(const string& path);

        /**
        * @brief Function that allows to make a choice between different grounds
        *
        * @return the path of the ground
        */
        string Ground_choice();

    private:
        unique_ptr<viewer> d_viewer;
};

#endif // LASERGAME_H
