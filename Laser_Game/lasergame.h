#ifndef LASERGAME_H
#define LASERGAME_H
#include "game.h"
using std::cout;
using std::endl;
class lasergame
{
    public:
        lasergame();
        virtual ~lasergame() = default;
        void menu();
        void typeGraphique();
        void afficheTerrain(const string& path);
        string choisirTerrain();
    private:
        unique_ptr<viewer> d_viewer;
};

#endif // LASERGAME_H
