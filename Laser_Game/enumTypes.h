#ifndef ENUMTYPES_H_INCLUDED
#define ENUMTYPES_H_INCLUDED

/**
 * @namespace enumTypes
 * @brief An enumeration that contains directions and sense
 * @details This enumeration contains @a directions and @a sense
*/
namespace enumTypes
{
    /**
     * @brief Enumeration of the directions
     * @details This enumeration defines the different directions an object can have.
     */
    enum directions : short unsigned int
    {
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

    /**
     * @brief Enumeration of the senses
     * @details This enumeration defines the different sense that a mirror can have.
    */
    enum sens : bool
    {
        /**
         * @brief Equals '/'
        */
        basGauche_hautDroit = 0,
        /**
         * @brief Equals '\'
        */
        hautGauche_basDroit
    };
}

#endif // ENUMTYPES_H_INCLUDED
