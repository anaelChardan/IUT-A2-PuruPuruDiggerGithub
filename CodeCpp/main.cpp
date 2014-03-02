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

using namespace std;

int main(int argc, const char * argv[])
{
    //GameModel * model = new GameModel(MODEL_WIDTH, MODEL_HEIGHT, 0, 0 );
    //GameView * view = new GameView(VIEW_WIDTH, VIEW_HEIGHT, VIEWBPP);
    //view->setModel(model);
    
    //while(view->treatEvents()){
    //    view->synchronize();
    //    model->nextStep();
    //    view->draw();
    //    sf::Sleep(0.01f);
    //}
   
    
    //insert code here...
   // sf::RenderWindow window(sf::VideoMode(640,480, 32), "Test");
    //sf::Sleep(3.0F);
   
    
    /*===========================
     ZONE DE TEST
     =============================*/
   /* CellBase* my_digger = new Digger;
    
    //vector<vector<CellBase*> > my_tab;
    
    CellBase* my_tab[2][2];
    
    //my_tab.resize(2);
    //for( unsigned long i = 0 ; i < 2 ; i++ )
    //    my_tab[i].resize(2);
    
    my_tab[0][0] = my_digger;
    my_tab[0][1] = new ValueCell;
    my_tab[1][0] = new ValueCell;
    my_tab[1][1] = new ValueCell;
    
    for ( unsigned long i = 0 ; i < 2; i++ ) {
        for ( unsigned long j = 0 ; j < 2 ; j ++ ) {
            cout << *my_tab[i][j] ;
        }
        cout << endl;
    }
    
    //On tente de déplacer le digger
    delete my_tab[0][1];
    
    my_tab[0][1] = my_digger;
    my_tab[0][0] = new EmptyCell;
    
    
    for ( unsigned long i = 0 ; i < 2; i++ ) {
        for ( unsigned long j = 0 ; j < 2 ; j ++ ) {
            cout << *my_tab[i][j] ;
        }
        cout << endl;
    }
    
    cout <<  " La vie du digger " << my_tab[0][1]->getLife() << endl;
    
    my_tab[0][1]->lostLife();
    
    my_tab[0][1]->setX(12);
    my_tab[0][1]->setY(1);
    
    cout << "Dans le tableau" << my_tab[0][1]->getX() << " " << my_tab[0][1]->getY() << endl;
    cout << "Le digger à part " << my_digger->getX() << " " << my_digger->getY() << endl;
    
    cout <<  " La vie du digger " << my_tab[0][1]->getLife() << endl;
    cout << "La vie du pointeur " << my_digger->getLife() << endl;
    cout <<  " La vie d'une case quelconque " << my_tab[0][0]->getLife() << endl;
    
    for ( unsigned long i = 0; i < 2; i++ ) {
        for ( unsigned long j = 0 ; j < 2 ; j++ ) {
            delete my_tab[i][j];
        }
    } */
    
    //On simule une partie
    
    GameModel* model = new GameModel;
    int choice;
    int langue;
    int movement;
    bool isRunning = false;
    string nom;
    
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
    cout << " 2 : QUIT  " << endl << endl;
    
    cout << " CHOICE : ";
    
    cin >> choice;
    
    
    if ( choice == 1 ) {
        ifstream score("bestScores.txt", ios::in | ios::app );
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
            
            if ( score ) {
                string line;
                int cpt = 0;
                int scoreligne;
                string nomligne;
                map< int, string> Scores;
                int scorePlayer = model->getScore();
                while ( getline(score, line) ) {
                    //On lit le score et on le stocke dans une map
                    score >> scoreligne >> nomligne;
                    Scores[scoreligne] = nomligne;
                }
                Scores[scorePlayer] = nom;
                
                for ( map<int, string>::const_iterator it = Scores.begin() ; ( cpt< 5); ++it) {
                    score << it->first <<  " " <<  it->second << endl;
                    cpt++;
                }
            }
        }
    }
    
    delete model;
    
    //delete view;
    //delete model;
    
    return 0;
}

