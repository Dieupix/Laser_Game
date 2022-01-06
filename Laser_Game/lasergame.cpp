//Declaring libraries
#include "lasergame.h"

//---------- Constructors------------------------------
lasergame::lasergame() : d_viewer{1}
{}
//---------- End of constructors-----------------------
//---------- Methods ----------------------------------
void lasergame::menu()
{
    cout << "Launching game..." << endl;

    string path_Ground;
    bool flag = false;
    int choice;

    cout << "Game launched." << endl << endl;

    do
    {
        cout<<"========================== LASER GAME ========================"<<endl;
        cout<<"1 - Choisir un mode graphique"                                 <<endl;
        cout<<"2 - Choisir un terrain"                                        <<endl;
        if(flag)
            cout<<"3 - Lancer une partie"                                         <<endl;
        cout<<"0 - Quitter le jeu"                                            <<endl;
        cout<<"> ";
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
                    flag = true;
                    break;
                }
            //Starting the game
            case 3 :
                {
                    if(flag)
                    {
                        unique_ptr<viewer> d_v;

                        switch(d_viewer)
                        {
                        case 1:
                            {
                                d_v = make_unique<viewerOnWINBGI>();
                                break;
                            }
                        case 2:
                            {
                                d_v = make_unique<viewerOnTerminal>();
                                break;
                            }
                        default:
                            {
                                cerr << "d_viewer is not defined";
                                break;
                            }
                        }

                        game g{move(d_v)};
                        g.read(path_Ground);
                        g.run();
                        break;
                    }
                }
            //Exit the menu
        }
        cout << endl;
    }
    while(choice != 0);

    cout << "Closing game..." << endl;

    cout << "Game closed." << endl;
}

void lasergame::GraphicType()
{
    int choice;
    do
    {
        cout<<"========================== MODE =========================="<<endl;
        cout<<"1 - Mode graphique"                                        <<endl;
        cout<<"2 - Mode console"                                          <<endl;
        cout<<"0 - Retour"                                                <<endl;
        cout<<"> ";
        cin>>choice;
        //There are 3 possibilities
        switch(choice)
        {
            //Graphic mode (WINBGI)
            case 1:
                {
                    d_viewer = 1;
                    choice = 0;
                    break;
                }
            //Terminal mode
            case 2:
                {
                    d_viewer = 2;
                    choice = 0;
                    break;
                }
            default:
                {
                    cerr << "Erreur, veuillez saisir un mode graphique" << endl;
                    break;
                }
        }
        //Back to menu
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
        cout<<"==========================Terrain 3=========================="<<endl;
        printGround("../grounds/ground3.txt");
        cout<<"============================================================="<<endl;
        cout<<"> ";
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
            case 3:
                {
                    return "../grounds/ground3.txt";
                    break;
                }
            default:
                {
                    cerr << "Erreur, veuillez saisir un numero de terrain" << endl;
                    break;
                }
        }
        //Back to menu
    }
    while(choice != 0);
}

//---------- End of methods ----------------------------
