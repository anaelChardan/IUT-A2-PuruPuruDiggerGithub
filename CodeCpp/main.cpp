/// @file Score.h
/// @brief Fichier principal du programme
/// @author Anaël Chardan
/// @author Jérémy Damey
/// @author Osiris Malbranque
/// @version 0.1
/// @date 17/02/2014

#include <iostream>
#include <cstdlib>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "CellBase.h"
#include "Digger.h"
#include "ValueCell.h"
#include "EmptyCell.h"
#include "Score.h"
#include "Level.h"
#include "GameModel.h"
#include <fstream>
#include "IntDecFunctor.h"

using namespace std;



int main(int argc, const char * argv[])
{
    /*===========================
     ZONE DE TEST
     =============================*/

    //On simule une partie

    GameModel* model = new GameModel;
    int choice;
    int langue;
    int movement;
    bool isRunning = false;
    string nom;

    //showPresentation();

    cin >> choice;
    
    if ( choice == 2 ) {
       // showBestScore();
    }

    if ( choice == 1 ) {

        isRunning = true;
        cout << "Language :    1: English     2: French       3: Spanish " << endl << endl;
        cout << " CHOICE " ;

        cin >> langue;

        while (isRunning && model->isFinish()==false ) {
            cout << endl;
            cout << endl;

            model->showTMP(langue);

            cin >> movement;
            if ( movement != 5 ) {
                model->movement( movement );
            }
            else if ( movement == 5 )
                isRunning = false;

        }

        if ( model->isFinish()== true ) {
            cout << endl;
            cout << " Vous êtes mort, mort, mort et remort, le digger vous retient prisonnier dans sa mine " << endl;
            cout << "Entrez votre nom (sans espaces) " ;
            cin >> nom;
            //enterScore(model, nom);
            //showBestScore();
        }
    }

    delete model;

    return 0;
}

