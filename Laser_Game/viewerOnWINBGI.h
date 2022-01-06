#ifndef VIEWERONWINBGI_H
#define VIEWERONWINBGI_H

//Declaring libraries
#include "../winGraphics/graphics.h"
#include "viewer.h"

/**
 * @class viewerOnWINBGI viewerOnWINBGI.h
 * @brief An abstract class that represents all viewer on WINBGI
 * @details This abstract class represents all viewer on WINBGI, it cannot display any informations.
 */
class viewerOnWINBGI : public viewer
{
    public:

        /**
        * @brief Constructor by default of viewerOnWINBGI
        *
        * @return Create a viewer on Winbgi by default, with a width and a height equals 500 and a scale equals 20
        */
        viewerOnWINBGI();

        /**
        * @brief Constructor of viewerOnWINBGI
        *
        * @param new_width  : the width of the window (unsigned)
        * @param new_height : the height of the window(unsigned)
        * @param new_scale  : the scale (float)
        *
        * @return Create a viewer on Winbgi
        */
        viewerOnWINBGI(unsigned new_width,unsigned new_height, float new_scale);

        /**
        * @brief Virtual destructor of viewer on WINBGI
        */
        virtual ~viewerOnWINBGI();

        /**
        * @brief Procedure that set width of the window of the viewer
        *
        * @param new_width : the new width (unsigned)
        *
        * @return void
        */
        void setWidth(unsigned new_width);

        /**
        * @brief Procedure that set height of the window of the viewer
        *
        * @param new_height : the new height (unsigned)
        *
        * @return void
        */
        void setHeight(unsigned new_height);

        /**
        * @brief Procedure that set scale of the viewer
        *
        * @param new_scale : the new scale (float)
        *
        * @return void
        */
        void setScale(float new_scale);

        /**
        * @brief Function that get width of the viewer
        *
        * @return the current width of the current viewer (unsigned)
        */
        unsigned getWidth() const;

        /**
        * @brief Function that get height of the viewer
        *
        * @return the current height of the current viewer (unsigned)
        */
        unsigned getHeight() const;

        /**
        * @brief Function that get scale of the viewer
        *
        * @return the current scale of the current viewer (float)
        */
        float getScale() const;

        /**
         * @brief A virtual constant function override that prints an object on a viewer
         *
         * @param obj : The object to print
         *
         * @return void
         */
        virtual void print(const unique_ptr<object>& obj) const override;

        /**
         * @brief A virtual constant function override that prints a ground on a viewer on WINBGI
         *
         * @param g : The ground to print
         *
         * @return void
         */
        virtual void printGround(const ground& g) const override;

        /**
         * @brief A virtual constant function that prints a laser on a viewer on WINBGI
         *
         * @param l : The laser to print
         *
         * @return void
         */
        virtual void printLaser(const laser& l) const override;

         /**
         * @brief A virtual constant function that prints a mirror on a viewer on WINBGI
         *
         * @param l : The mirror to print
         *
         * @return void
         */
        virtual void printMirror(const mirror& m) const override;

         /**
         * @brief A virtual constant function that prints a shooter on a viewer on WINBGI
         *
         * @param l : The shooter to print
         *
         * @return void
         */
        virtual void printShooter(const shooter& s) const override;

         /**
         * @brief A virtual constant function that prints a target on a viewer on WINBGI
         *
         * @param l : The target to print
         *
         * @return void
         */
        virtual void printTarget(const target& t) const override;

         /**
         * @brief A virtual constant function that prints a wall on a viewer on WINBGI
         *
         * @param l : The wall to print
         *
         * @return void
         */
        virtual void printWall(const wall& w) const override;

     private:
        //The width and the height of the window of the viewer on WinbGi
        unsigned width, height;
        //The scale of the viewer
        float scale;

        /**
         * @brief Procedure that allows to initialize the windows
         *
         * @return void
         */
        void initialize();
};

#endif // VIEWERONWINBGI_H
