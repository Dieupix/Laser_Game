#ifndef LASER_H
#define LASER_H

#include "object.h"

/**
 * @class laser laser.h
 * @brief A class that represents a laser
 * @details This class represents a laser, which is an @a object
 * with a @a direction and a @a step.
 */
class laser : public object
{
    public:
        friend class tireur;

        // Enumeration
        /**
         * @brief Enumeration of the directions
         * @details This enumeration defines the different directions
         * the laser can have.
         */
        enum directions : short unsigned int{
            RIGHT,
            UP,
            LEFT,
            DOWN
        };
        /** @var laser::directions laser::RIGHT
         * @brief Right direction
         * @details The direction when the laser goes to the right.
         */
        /** @var laser::directions laser::LEFT
         * @brief Left direction
         * @details The direction when the laser goes to the left.
         */
        /** @var laser::directions laser::UP
         * @brief Up direction
         * @details The direction when the laser goes to the top.
         */
        /** @var laser::directions laser::DOWN
         * @brief Down direction
         * @details The direction when the laser goes to the bottom.
         */

        // Destructor
        /**
         * @brief Default-implemented destructor
         * @details Destroys the laser.
         */
        virtual ~laser() = default;

        // Overloads

        /**
         * @brief Binary operator == : constant
         * @details Tests if all the member variables of two
         * lasers are equals.
         *
         * @param l : The laser to test with
         * @return Returns true if both of the lasers are equals, else false
         */
        bool operator==(const laser&) const;
        /**
         * @brief Binary operator != : constant
         * @details Tests if at least one of the member variables of two
         * lasers are different.
         *
         * @param l : The laser to test with
         * @return Returns true if both of the lasers are different, else false
         */
        bool operator!=(const laser&) const;

        // Getters
        /**
         * @brief Constant getter function for the direction of the laser
         *
         * @return Returns the direction of the laser
         */
        laser::directions getDirection() const;
        /**
         * @brief Constant getter function for the step of the laser
         *
         * @return Returns the step of the laser
         */
        double getStep() const;

        // Setters
        /**
         * @brief Setter function for the direction of the laser
         *
         * @param[in] direction : The new direction of the laser
         * @return Returns nothing
         */
        void setDirection(laser::directions);
        /**
         * @brief Setter function for the step of the laser
         *
         * @param[in] step : The new step of the laser
         * @return Returns nothing
         */
        void setStep(double);

        // Functions
        /**
         * @brief A function that moves the laser
         * @details This function moves the laser from its position
         * by its direction and its step.
         *
         * @return Returns nothing
         */
        void moveByStep();
        /**
         * @brief A function that prints the characteristics of a laser
         * @details A laser is printed as Laser[position(x,y), direction(DIRECTION), step(STEP)]
         *
         * @param ost : The output stream
         * @return virtual void
         */
        virtual void print(std::ostream&) const override;
        /**
         * @brief A function that changes the direction of the laser
         * by 90 degrees to the left.
         * @see directions
         *
         * @return Returns nothing
         */
        void turnLeft();
        /**
         * @brief A function that changes the direction of the laser
         * by 90 degrees to the right.
         * @see directions
         *
         * @return Returns nothing
         */
        void turnRight();

    private:
         /**
          * @brief The direction of the laser
          * @see directions
          */
        laser::directions direction;
        /**
         * @brief The step of the laser
         */
        double step;

        // Constructors
        /**
         * @brief Constructor with a position, a direction and a step
         *
         * @param[in] p : The initial position of the laser
         * @param[in] direction : The initial direction of the laser
         * @param[in] step : The step of the laser when it moves (by default 1.0)
         * @return Creates a laser with its parameters
         */
        laser(const point&, laser::directions, double = 1.0);


}; // End of laser

// Global functions

#endif // LASER_H
