#ifndef LASER_H
#define LASER_H

#include "objet.h"

/**
 * @class laser laser.h
 * @brief A class that represents a laser
 * @details This class represents a laser with its position,
 * its direction and a step
 */
class laser : public objet
{
    private:
         /**
          * @brief The direction of the laser
          * @see enum directions
          */
        short int direction;
        /**
         * @brief The step of the laser
         */
        double step;

    public:

        // Enumeration
        /**
         * @brief Enumeration of the directions
         * @details This enumeration defines the different directions
         * the laser can have.
         */
        enum directions{
            RIGHT,
            LEFT,
            UP,
            DOWN
        };
        /** \var laser::directions laser::RIGHT
         * @brief Right direction
         * @details The direction when the laser goes to the right.
         */
        /** \var laser::directions laser::LEFT
         * @brief Left direction
         * @details The direction when the laser goes to the left.
         */
        /** \var laser::directions laser::UP
         * @brief Up direction
         * @details The direction when the laser goes to the top.
         */
        /** \var laser::directions laser::DOWN
         * @brief Down direction
         * @details The direction when the laser goes to the bottom.
         */

        // Constructors
        /**
         * @brief Constructor with a position, a direction and a step
         *
         * @param p : The initial position of the laser
         * @param direction : The initial direction of the laser
         * @param step : The step of the laser when it moves (by default 1.0)
         * @return Creates a laser with its parameters
         */
        laser(const point&, short int, double = 1.0);

        // Destructor
        /**
         * @brief Default-implemented destructor
         * @details Destroys the laser
         */
        virtual ~laser() = default;

        // Overloads

        // Getters
        /**
         * @brief Constant getter function for the direction of the laser
         *
         * @return Returns the direction of the laser
         */
        short int getDirection() const;
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
         * @param direction : The new direction of the laser
         * @return Returns nothing
         */
        void setDirection(short int);
        /**
         * @brief Setter function for the step of the laser
         *
         * @param step : The new step of the laser
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
         * @brief A function that prints the laser on an output stream
         *
         * @param ost : The output stream
         * @return Returns nothing
         */
        void print(std::ostream&) const override;


}; // End of laser

// Global functions

#endif // LASER_H
