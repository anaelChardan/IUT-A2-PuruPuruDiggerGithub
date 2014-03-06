/// @file Score.h
/// @brief Fichier principal du programme
/// @author Anaël Chardan
/// @author Jérémy Damey
/// @author Osiris Malbranque
/// @version 0.1
/// @date 17/02/2014

#include <iostream>
#include "GameModel.h"
#include "GameView.h"

using namespace std;



int main(int argc, const char * argv[])
{


    //On simule une partie

    GameModel* model = new GameModel;
    GameView * view = new GameView;
    
    //Injection de dépendance
    view->setModel(model);
    
    view->treatGame();
    
    delete view;
    delete model;

    return 0;
}

