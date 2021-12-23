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
        UP,
        /**
         * @brief Up direction
         */
        LEFT,
        /**
         * @brief Down direction
         */
        DOWN
    };

    enum sens : bool{
        basGauche_hautDroit = 0,
        hautGauche_basDroit
    };
}

#endif // ENUMTYPES_H_INCLUDED
