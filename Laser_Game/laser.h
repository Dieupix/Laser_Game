#ifndef LASER_H
#define LASER_H

//Declaring libraries
#include "object.h"
#include "shooter.h"

//Declaring namespace
using namespace enumTypes;

/**
 * @class laser laser.h
 * @brief A class that represents a laser
 * @details This class represents a laser, which is an @a object with a @a direction and a @a step.
 */
class laser : public object
{
    //Friend of class
    friend laser shooter::shoot(double);
    friend laser createLaserForTest(const point&, const directions&, double);

    public:

        /**
        * @brief Virtual destructor by default of laser
        */
        virtual ~laser() = default;

        /**
        * @brief Function that get direction of the laser
        *
        * @return the direction of the current laser
        */
        directions getDirection() const;

        /**
        * @brief Function that allows to know when the laser is alive
        *
        * @return a boolean
        */
        bool getIsAlive() const;

        /**
        * @brief Function that get step of the laser
        *
        * @return the step of the laser
        */
        double getStep() const;

        /**
        * @brief Function that set direction of the laser
        *
        * @param dir : the new direction (enumeration directions)
        *
        * @return void
        */
        void setDirection(directions dir);

        /**
        * @brief Function that allows to change propriety isAlive
        *
        * @param b : a boolean
        *
        * @return void
        */
        void setIsAlive(bool alive);

        /**
        * @brief Function that get step of the laser
        *
        * @param new_step : the new step (double)
        *
        * @return the step of the laser
        */
        void setStep(double new_step);

        /**
        * @brief Virtual function that allows to clone a smart pointer of laser
        *
        * @return a new smart pointer of laser
        */
        virtual unique_ptr<object> clone() const override;

        /**
        * @brief Procedure that allows to move the laser by step
        *
        * @return void
        */
        void moveByStep();

        /**
        * @brief Virtual procedure that allows to print characteristics of laser
        *
        * @param ost : the flow (ostream)
        *
        * @return void
        */
        virtual void print(std::ostream& ost) const override;

        /**
        * @brief Virtual function that allows to convert a laser in string
        *
        * @return a string
        */
        virtual string toString() const override;

        /**
        * @brief Procedure that allows to turn the laser on left
        *
        * @return void
        */
        void turnLeft();

        /**
        * @brief Procedure that allows to turn the laser on right
        *
        * @return void
        */
        void turnRight();

        /** @brief Allows to test equality between 2 lasers
         *
         * @param l : a laser (const laser)
         *
         * @return a boolean
         */
        bool operator==(const laser& l) const;

        /** @brief Allows to test inequality between 2 lasers
         *
         * @param l : a laser (const laser)
         *
         * @return a boolean
         */
        bool operator!=(const laser& l) const;

    private:
        //The direction of laser
        directions direction;
        //A boolean that allows to know when the laser is alive or not
        bool isAlive;
        //The step of the laser
        double step;

        /**
        * @brief Constructor of laser (private)
        *
        * @param p : point (const point)
        * @param direction : the direction of the laser (enumeration directions)
        * @param step_laser : the step (double, 1.0 by default)
        *
        * @return Create a laser with a position, a direction and a step
        */
        laser(const point& p , directions direction, double sstep_laser = 1.0);
};

        /** @brief Allows to create a laser for test
         *
         * @param p : point (const point)
         * @param direction : the direction of the laser (enumeration directions)
         * @param step_laser : the step (double, 1.0 by default)
         *
         * @return a new laser
         */
        laser createLaserForTest(const point& p, const directions& direction, double step_laser = 1.0);

#endif // LASER_H
