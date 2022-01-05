//Declaring libraries
#include "lasergame.h"

//---------- Constructors------------------------------
lasergame::lasergame() : d_viewer{make_unique<viewerOnTerminal>()}
{}
//---------- End of constructors-----------------------
//---------- Methods ----------------------------------
void lasergame::menu()
{
    string path_Ground;
    int choice;
    do
    {
        cout<<"========================== LASER GAME ========================"<<endl;
        cout<<"0 - Quitter le jeu"                                            <<endl;
        cout<<"1 - Choisir un mode graphique"                                 <<endl;
        cout<<"2 - Choisir un terrain"                                        <<endl;
        cout<<"3 - Lancer une partie"                                         <<endl;
        cout<<">";
        cin>>choice;
        //There are 4 possibilities
        switch(choice)
        {
            //Making choice for graphic type
            case 1:
                {
                    GraphicType();
                    break;
                }
            //Making choice for a ground
            case 2:
                {
                    path_Ground = Ground_choice();
                    break;
                }
            //Starting the game
            case 3 :
<<<<<<< HEAD
            /*   game partie{d_viewer};
                partie.read(cheminTerrain);
                partie.run();*/
                break;
=======
                {
                    game g{move(d_viewer)};
                    g.read(path_Ground);
                    g.run();
                    break;
                }
            //Exit the menu
>>>>>>> e3e37fb517976c8543a07e00f077698fa8be75ab
        }
    }
    while(choice != 0);
}

void lasergame::GraphicType()
{
    int choice;
    do
    {
        cout<<"========================== MODE =========================="<<endl;
        cout<<"0 - Retour"                                                <<endl;
        cout<<"1 - Mode graphique"                                        <<endl;
        cout<<"2 - Mode console"                                          <<endl;
        cout<<">";
        cin>>choice;
        //There are 3 possibilities
        switch(choice)
        {
            //Graphic mode (WINBGI)
            case 1:
                {
                    d_viewer = move(make_unique<viewerOnWINBGI>());
                    break;
                }
            //Terminal mode
            case 2:
                {
                    d_viewer = move(make_unique<viewerOnTerminal>());
                    break;
                }
            //Back to menu
        }
    }
    while(choice != 0);
}

void lasergame::printGround(const string& path)
{
    viewerOnTerminal viewerOT{};
    ground g{};
    ifstream ifs(path);
    //Loading of the file
    g.loadFrom(ifs);
    //Print of the ground
    viewerOT.printGround(g);
}

string lasergame::Ground_choice()
{
    int choice;
    do
    {
        cout<<"0 - Retour"<<endl;
        cout<<"==========================Terrain 1=========================="<<endl;
        printGround("../grounds/ground1.txt");
        cout<<"============================================================="<<endl;
        cout<<"==========================Terrain 2=========================="<<endl;
        printGround("../grounds/ground2.txt");
        cout<<"============================================================="<<endl;
        cout<<">";
        cin>>choice;

        switch(choice)
        {
            //Ground 1
            case 1 :
                {
                    return "../grounds/ground1.txt";
                    break;
                }
            //Ground 2
            case 2 :
                {
                    return "../grounds/ground2.txt";
                    break;
                }
            //Back to menu
        }
    }
    while(choice != 0);
}
//---------- End of methods ----------------------------
