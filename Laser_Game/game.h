#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

//Declaring libraries
#include "ground.h"
#include "viewerOnTerminal.h"
#include "viewerOnWINBGI.h"
#include <fstream>
#include <string>

//Declaring namespace elements
using std::invalid_argument;
using std::ifstream;
using std::ofstream;
using std::string;

/**
 * @class game game.h
 * @brief A class that represents a game
 * @details This class represents a game, with a @a ground and a @a viewer
*/
class game
{
    public:
        /**
        * @brief Constructor of game (with a default ground)
        *
        * @param view : the viewer of the game (unique_ptr<>, by default viewerOnTerminal)
        *
        * @return Create a game with a viewer and a ground by default
        */
        game(unique_ptr<viewer> view = make_unique<viewerOnTerminal>());

        /**
        * @brief Constructor of game
        *
        * @param g    : the ground (const ground)
        * @param view : the viewer of the game (unique_ptr<>, by default viewerOnTerminal)
        *
        * @return Create a game with a viewer and a ground by default
        */
        game(const ground& g , unique_ptr<viewer> view = make_unique<viewerOnTerminal>());

        /**
        * @brief Virtual destructor by default of game
        */
        ~game() = default ;

        /**
        * @brief Procedure that allows to add a mirror in the game
        *
        * @param position_mirror : the position of the mirror (const point)
        * @param sense_mirror    : the sense of the mirror (enumeration sens)
        *
        * @return void
        */
        void addMirror(const point& position_mirror, const sens& sense_mirror);

        /**
        * @brief Procedure that allows to remove a mirror in the game
        *
        * @param p : the position of the mirror (const point)
        *
        * @return void
        */
        void removeMirror(const point& p);

        /**
        * @brief Function that allows to calculate the current score
        *
        * @return the current the score (integer)
        */
        int score() const;

        /**
        * @brief Procedure that allows to load the ground of the the game
        *
        * @param ground_loaded : the loaded ground (const)
        *
        * @return void
        */
        void loadGround(const ground& ground_loaded);

        /**
        * @brief Procedure that allows to read a file
        *
        * @param nameFile : the name of the file (const string)
        *
        * @return void
        */
        void read(const string& nameFile);

        /**
        * @brief Procedure that allows to print the menu
        *
        * @return void
        */
        void menu();

        /**
        * @brief Procedure that allows to execute the game
        *
        * @return void
        */
        void run();

        /**
        * @brief Procedure that allows to know when we win the game
        *
        * @return void
        */
        void win() const;

        /**
        * @brief Procedure that allows to save the game in a file
        *
        * @param nameFile : the name of the file (const string)
        *
        * @return void
        */
        void save(const string& nameFile) const ;

    private:
        //The ground of the game
        ground d_ground;
        //The viewer of the game
        unique_ptr<viewer> d_viewer;

        /**
        * @brief Function that allows to reverse a position (private)
        *
        * @param p : a position with the coordinate x and y (const point)
        *
        * @return a new point(y,x)
        */
        point reversePosition(const point& p);

        /**
        * @brief Function that allows to ask the sense of a mirror (private)
        *
        * @return a sense (enumeration sens)
        */
        sens askSens();

        /**
        * @brief Function that allows to ask the position of a object (private)
        *
        * @return a position (point)
        */
        point askPosition();

        /**
        * @brief Procedure that allows to reverse the direction of a direction (private)
        *
        * @param l : the laser (with the direction changed)
        *
        * @return a position (point)
        */
        void reverseDirection(laser& l) const;

        /**
        * @brief Procedure that allows to start the game (shoot the laser)
        *
        * @return void
        */
        void start();
};

#endif // GAME_H_INCLUDED


