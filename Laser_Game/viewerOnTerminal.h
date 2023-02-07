#ifndef VIEWERONTERMINAL_H
#define VIEWERONTERMINAL_H

//Declaring classes
#include "viewer.h"

/**
 * @class viewerOnTerminal viewerOnTerminal.h
 * @brief A class that represents a viewer on terminal
 * @details This class represents a viewer on terminal, with a @a blank and a @a spacing
*/
class viewerOnTerminal : public viewer
{
    public:
        /**
        * @brief Constructor of viewerOnTerminal
        *
        * @param car_blank : the character for blank (char)
        * @param space : the spacing (unsigned)
        *
        * @return Create a viewer on terminal
        */
        viewerOnTerminal(char car_blank = '.', unsigned space = 2);

        /**
        * @brief Virtual destructor by default of viewerOnTerminal
        */
        virtual ~viewerOnTerminal() = default;

        /**
        * @brief Procedure that set blank of the viewer
        *
        * @param new_blank : the new blank (char)
        *
        * @return void
        */
        void setBlank(char new_blank);

        /**
        * @brief Procedure that set spacing of the viewer
        *
        * @param new_space : the new spacing (unsigned)
        *
        * @return void
        */
        void setSpacing(unsigned new_space);

        /**
        * @brief Function that get blank of the viewer
        *
        * @return the current blank of the current viewer (char)
        */
        char getBlank() const;

        /**
        * @brief Function that get spacing of the viewer
        *
        * @return the current spacing of the current viewer (unsigned)
        */
        unsigned getSpacing() const;

        /**
         * @brief A virtual constant function override that prints an object on a viewer on terminal
         *
         * @param obj : The object to print
         *
         * @return void
         */
        virtual void print(const unique_ptr<object>& obj) const override;

        /**
         * @brief A virtual constant function override that prints a ground on a viewer on terminal
         *
         * @param g : The ground to print
         *
         * @return void
         */
        virtual void printGround(const ground& g) const override;

        /**
         * @brief A virtual constant function that prints a laser on a viewer on terminal
         *
         * @param l : The laser to print
         *
         * @return void
         */
        virtual void printLaser(const laser& l) const override;

         /**
         * @brief A virtual constant function that prints a mirror on a viewer on terminal
         *
         * @param l : The mirror to print
         *
         * @return void
         */
        virtual void printMirror(const mirror& m) const override;

         /**
         * @brief A virtual constant function that prints a shooter on a viewer on terminal
         *
         * @param l : The shooter to print
         *
         * @return void
         */
        virtual void printShooter(const shooter& s) const override;

         /**
         * @brief A virtual constant function that prints a target on a viewer on terminal
         *
         * @param l : The target to print
         *
         * @return void
         */
        virtual void printTarget(const target& t) const override;

         /**
         * @brief A virtual constant function that prints a wall on a viewer on terminal
         *
         * @param l : The wall to print
         *
         * @return void
         */
        virtual void printWall(const wall& w) const override;

     private:
        //The blank of the viewer
        char blank;
        //The spacing of the viewer
        unsigned spacing;
};

#endif // VIEWERONTERMINAL_H
