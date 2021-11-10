#ifndef LASER_H
#define LASER_H

#include "objet.h"


class laser : public objet
{
    private:
        /************************************************
         * @brief The direction of the laser
         * @see enum directions
         ***********************************************/
        short short int direction;
        /************************************************
         * @brief The step of the laser
         ***********************************************/
        double step;

    public:

        // Enumeration
        /************************************************
         * @brief Enumeration of the directions
         *
         * @details This enumeration defines the different directions
         * the laser can have
         ***********************************************/
        enum directions{
            LEFT, RIGHT, UP, DOWN;
        };

        // Constructors
        /************************************************
         * @brief Constructor with a position, a direction and a step
         *
         * @param p : The initial position of the laser
         * @param direction : The initial direction of the laser
         * @param step : The step of the laser when it moves
         * @return Creates a laser
         ***********************************************/
        laser(const point&, int, double);

        // Destructor
        /************************************************
         * @brief Default destructor
         *
         * @details Destroys the laser
         ***********************************************/
        virtual ~laser() = default;

        // Overloads

        // Getters
        short short int getDirection() const;
        double getStep() const;

        // Setters
        void setDirection(short short int);
        void setStep(double);

        // Functions
        void moveByStep();

}; // End of laser

// Global functions

#endif // LASER_H
