/**
 * \file main.cpp
 * \brief Notre main terminal
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "GameModel.h"
#include "GameView.h"
#include <cstdlib>

using namespace std;



int main(int argc, const char * argv[])
{    
    std::srand ( unsigned ( std::time(0) ) );
    
    GameModel* model = new GameModel;
    GameView * view = new GameView;
    
    //Injection de dépendance
    view->setModel(model);
    
    view->treatGame();
    
    delete view;
    delete model;

    return 0;
}

