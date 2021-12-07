#ifndef ENUMTYPES_H_INCLUDED
#define ENUMTYPES_H_INCLUDED

namespace enumTypes{

    // Enumerations
    /**
     * @brief Enumeration of the directions
     * @details This enumeration defines the different directions
     * an object can have.
     */
    enum directions : short unsigned int{
        /**
         * @brief Right direction
         */
        RIGHT = 0,
        /**
         * @brief Left direction
         */
        UP = 1,
        /**
         * @brief Up direction
         */
        LEFT = 2,
        /**
         * @brief Down direction
         */
        DOWN = 3
    };

    enum sens : bool  {
        basGauche_hautDroit = 0,
        hautGauche_basDroit = 1
    };
}

#endif // ENUMTYPES_H_INCLUDED
