//Declaring libraries
#include "game.h"

//---------- Constructors------------------------------
game::game(unique_ptr<viewer> view) : d_ground{},
                                      d_viewer{move(view)}
{}

game::game(const ground& g, unique_ptr<viewer> view) : d_ground{g},
                                                       d_viewer{move(view)}
{}
//---------- End of constructors-----------------------
//---------- Methods ----------------------------------
bool game::validPosition(int positionX, int positionY)
{
    return positionX >= 0 && positionY >= 0 && positionX < d_ground.getNbCellsHeight() && positionY < d_ground.getNbCellsWidth();
}

void game::addMirror(const point& position_mirror, const sens& sense_mirror)
{
    auto positionX = position_mirror.x();
    auto positionY = position_mirror.y();

    //If coordinates of mirror are valid
    if(validPosition(positionX,positionY))
    {
        auto obj = d_ground.getObjects()[positionX][positionY].get();
        //Reverse of the position of mirror (due of the grid and the vector objects)
        point pMirror = reversePosition(position_mirror) + d_ground.getPosition();
        //If there are already an object in this position
        if(obj)
        {
            //Moreover, if this object is a mirror, the mirror disappears
            if(dynamic_cast<mirror*>(obj))
            {
                d_ground.removeObjectAt(positionX, positionY);
            }
        }
        d_ground.addObjectAt(make_unique<mirror>(pMirror, sense_mirror), positionX, positionY);
    }
    else
    {
        cerr << "ERROR: the position is not on the ground" << endl;
    }
}

void game::removeMirror(const point& p)
{
    auto positionX = p.x();
    auto positionY = p.y();

    //If coordinates of mirror are valid
    if(validPosition(positionX,positionY))
    {
        auto obj = d_ground.getObjects()[positionX][positionY].get();
        //If there are an object in this position
        if(obj)
        {
            //Moreover, if this object is a mirror, the mirror disappears
            if(dynamic_cast<mirror*>(obj))
            {
                d_ground.removeObjectAt(positionX, positionY);
            }
        }
    }
}

int game::score() const
{
    //It can be evoluate with variant
    return 100*(d_ground.getNbMirrorMax()/d_ground.getNbOfMirrors());
}

void game::loadGround(const ground& ground_loaded)
{
    d_ground = ground_loaded;
}

void game::read(const string& nameFile)
{
    if(nameFile == "")
    {
        throw invalid_argument("Chemin vide !");
    }
    ifstream file_in;
    file_in.open(nameFile);

    //If reading is not good (wrong path, file not found, ...)
    if(!file_in.is_open())
    {
        cout << "failed to open " << nameFile << '\n';
    }
    else
    {
        //Loading
        d_ground.loadFrom(file_in);
    }
}

void game::run()
{
    int choice, max_choices = 3;
    point position;
    do
    {
        cout<<"========================== COMMANDE =========================="<<endl;
        cout<<"0 - Tirer le laser"     <<endl;
        cout<<"1 - Ajouter un miroir"  <<endl;
        cout<<"2 - Enlever un miroir"  <<endl;
        cout<<"3 - Afficher le terrain"<<endl;
        cout << "> ";
        cin>>choice;

        //There are 4 possibilities (can evolve)
        switch(choice)
        {
            //Shoot the laser
            case 0:
                {
                    start();
                    break;
                }
            //Adding mirrors in game
            case 1:
                {
                    //If adding mirrors is authorized
                    if(d_ground.getNbOfMirrors() < d_ground.getNbMirrorMax())
                    {
                        //Asking the sense of the installed mirror
                        sens s = askSens();
                        //Asking the position of the installed mirror
                        position = askPosition();
                        addMirror(position, s);
                    }
                    else cout<<"Le nombre maximum de miroirs a ete atteint ! "<<endl;
                    break;
                }
            //Removing mirror in game
            case 2 :
                {
                    //Asking the position of the removed mirror
                    position = askPosition();
                    removeMirror(position);
                    break;
                }
            //Print the ground of the game
            case 3 :
                {
                    d_viewer->printGround(d_ground);
                    break;
                }
            //The choice contains an invalid integer
            default:
                {
                    cerr << "Erreur, entrez un nombre entre 0 et " << max_choices << endl;
                    break;
                }
        }
        cout << endl;
    }
    while(choice != 0);
}

void game::win() const
{
    d_viewer->printGround(d_ground);
    target t = d_ground.getTarget();
    if(t.isAffected())
        cout<<"Votre score est de : "<<score()<<" points, vous etes trop fort !!";
}

void game::save(const string& nameFile) const
{
    if(nameFile == "")
    {
        throw invalid_argument("Chemin vide!");
    }
    ofstream file_out;
    file_out.open(nameFile);

    //If opening is not good (wrong path, file not found, ...)
    if(!file_out.is_open())
    {
        cout << "failed to open " << nameFile << '\n';
    }
    else
    {
       //Saving the game in this file
       d_ground.saveIn(file_out) ;
    }
}
//---------- Private Methods --------------------------
point game::reversePosition(const point& p)
{
    return {p.y(), p.x()};
}

sens game::askSens()
{
    char inclination_mirror;
    cout<<"Saisir l'inclinaison du miroir ( / ou \\ ) : ";
    cin>>inclination_mirror;
    sens s;

    //There are 2 possibilities
    switch(inclination_mirror)
    {
        case('/') :
        {
            s = basGauche_hautDroit;
            break;
        }
        case('\\') :
        {
            s = hautGauche_basDroit;
            break;
        }
    }
    return s;
}

point game::askPosition()
{
    point p;
    cout<<"Saisir la position : ";
    cin>>p;
    return p;
}

void game::reverseDirection(laser& l) const
{
    //There are 2 possibilities
    switch(l.getDirection())
    {
        case UP:
        {
            l.setDirection(DOWN);
            break;
        }
        case DOWN:
        {
            l.setDirection(UP);
            break;
        }
        default:
        {
            break;
        }
    }
}

void game::start()
{
    auto shooter = d_ground.getShooter();
    auto l = shooter.shoot();
    reverseDirection(l);

    point position = reversePosition(l.getPosition() - d_ground.getPosition());
    unsigned x = position.x(),
             y = position.y();

    //Adding laser in the ground of the game
    d_ground.addObjectAt(make_unique<object>(l), x, y);

    //While the laser is alive (the laser does not touch a wall, the shooter or a target
    while(l.getIsAlive())
    {
        //The laser move by step
        l.moveByStep();

        //Changing current position of laser
        position = reversePosition(l.getPosition() - d_ground.getPosition());
        x = position.x();
        y = position.y();

        unsigned i = 0, j = 0;
        //If the laser is dead, stopped while
        while(i < d_ground.getNbCellsHeight() and l.getIsAlive())
        {
            //If the laser is dead, stopped while
            while(j < d_ground.getNbCellsWidth() and l.getIsAlive())
            {
                auto obj = d_ground.getObjects()[i][j].get();
                //If there are an object in this position
                if(obj)
                {
                    //Reversing position to test if the laser hit an other object
                    reverseDirection(l);
                    obj->collide(l);
                    //Reversing to move after
                    reverseDirection(l);
                }
                ++j;
            }
            ++i;
            //Reset of counter j
            j = 0;
        }
        //If the laser is still alive, add laser in the game
        if(l.getIsAlive())
        {
            d_ground.addObjectAt(make_unique<laser>(l), x, y);
        }
    }
    //Test if we win this game
    win();
}
//---------- End of methods ----------------------------






