#include "lasergame.h"

lasergame::lasergame() : d_viewer{make_unique<viewerOnTerminal>()}
{}

void lasergame::menu()
{
    string cheminTerrain;
    int choix;
    do
    {
        cout<<"==========================LASER GAME=========================="<<endl;
        cout<<"1 - Choisir un mode graphique"<<endl;
        cout<<"2 - Choisir un terrain"<<endl;
        cout<<"3 - Lancer une partie"<<endl;
        cout<<"0 - Quitter le jeu"<<endl;

        cout<<">";
        cin>> choix;

        switch(choix)
        {
            case 1 :
                typeGraphique();
                break;
            case 2 :
                cheminTerrain = choisirTerrain();
                break;
            case 3 :
                game partie{d_viewer};
                partie.read(cheminTerrain);
                partie.run();
                break;
        }
    }while(choix != 0);
}

void lasergame::typeGraphique()
{
    int choix;
    do
    {
        cout<<"1 - Mode graphique"<<endl;
        cout<<"2 - Mode console"<<endl;
        cout<<"0 - Retour"<<endl;

        cout<<">";
        cin>>choix;

        switch(choix)
        {
        case 1 :
            d_viewer = move(make_unique<viewerOnWINBGI>());
            break;
        case 2 :
            d_viewer = move(make_unique<viewerOnTerminal>());
            break;
        }
    }while(choix != 0);
}

void lasergame::afficheTerrain(const string& path)
{
    viewerOnTerminal afficheur{};
    ground terrain{};

    ifstream ifs(path);

    terrain.loadFrom(ifs);
    afficheur.printGround(terrain);
}

string lasergame::choisirTerrain()
{
    int choix;
    do
    {
        cout<<"==========================Terrain 1=========================="<<endl;
        afficheTerrain("../grounds/ground1.txt");
        cout<<"============================================================="<<endl;
        cout<<"==========================Terrain 2=========================="<<endl;
        afficheTerrain("../grounds/ground2.txt");
        cout<<"============================================================="<<endl;
        cout<<"0 - Retour"<<endl;

        cout<<">";
        cin>>choix;

        switch(choix)
        {
            case 1 :
                return "../grounds/ground1.txt";
                break;
            case 2 :
                return "../grounds/ground2.txt";
                break;
        }
    }while(choix != 0);
}

