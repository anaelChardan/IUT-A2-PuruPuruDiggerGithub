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

void showPresentation() {
    cout << " -----------                           -----------                    " << endl ;
    cout << "|           |      |           |      |           |      |           |" << endl ;
    cout << "|           |      |           |      |           |      |           |" << endl ;
    cout << "|           |      |           |      |           |      |           |" << endl ;
    cout << "|-----------       |           |      |-----------       |           |" << endl ;
    cout << "|                  |           |      |-                 |           |" << endl ;
    cout << "|                  |           |      |  -               |           |" << endl ;
    cout << "|                  |           |      |    -             |           |" << endl ;
    cout << "|                  |           |      |      -           |           |" << endl ;
    cout << "|                  |           |      |        -         |           |" << endl ;
    cout << "|                  |___________|      |          -       |___________|" << endl << endl << endl;
    
    
    cout << "                        PURU                DIGGER                    " << endl << endl << endl;
    
    cout << "                  BY ANAEL CHARDAN    &     JEREMY DAMEY              " << endl << endl << endl;
    
    
    cout << " 1 : START " << endl;
    cout << " 2 : MEILLEUR SCORE " << endl;
    cout << " 3 : QUIT  " << endl << endl;
    
    cout << " CHOICE : ";
    
}

void enterScore( GameModel* model, string nom ) {
    ifstream scoreLect(FILEBESTSCORE.c_str(), ios::in );
    if ( scoreLect ) {
        //scoreLect >> "TEST";
        string line;
        int scoreligne;
        string nomligne;
        map< int, string, DecFunctor> Scores;
        int scorePlayer = model->getScore();
        
        while ( !scoreLect.eof() ) {
            //On lit le score et on le stocke dans une map
            scoreLect >> scoreligne >> nomligne;
            Scores[scoreligne] = nomligne.c_str();
        }
        
        
        //On ajoute notre joueur à la map
        Scores[scorePlayer] = nom;
        
        scoreLect.close();
        
        ofstream scoreEcr(FILEBESTSCORE.c_str(), ios::out | ios::trunc );
        
        map< int, string>::iterator i;
        if ( Scores.size() < 5 ) {
            i = Scores.end();
        } else {
            i = Scores.begin();
            for ( int cpt = 0 ; cpt < 5; cpt ++ ) ++i;
        }
        
        for ( map< int, string >::const_iterator it = Scores.begin() ; it!=i ; ++it) {
            scoreEcr << it->first;
            scoreEcr <<  " ";
            scoreEcr <<  it->second;
            scoreEcr << endl;
        }
        
        scoreEcr.close();
    } else {
        cerr << " Erreur d'ouverture de fichier " << endl;
    }
}

void showBestScore() {
    ifstream scoreLect(FILEBESTSCORE.c_str(), ios::in );
    if ( scoreLect ) {
        string line;
        
        cout << endl;
        cout << endl;
        
        cout << " Voici les meilleurs scores " << endl << endl;
        
        while ( getline(scoreLect, line) ) {
            cout << line << endl;
        }
        
        scoreLect.close();
    } else {
        cerr << " Erreur d'ouverture de fichier " << endl;
    }

}

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

    showPresentation();

    cin >> choice;
    
    if ( choice == 2 ) {
        showBestScore();
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
            enterScore(model, nom);
            showBestScore();
        }
    }

    delete model;

    return 0;
}

