/// @file Score.h
/// @brief Fichier principal du programme
/// @author Anaël Chardan
/// @author Jérémy Damey
/// @author Osiris Malbranque
/// @version 0.1
/// @date 17/02/2014

#include <iostream>
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

using namespace std;

int main(int argc, const char * argv[])
{

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
    
    Score* my_score = new Score;
    Level* my_level = new Level(my_score);
    my_level->showTmp();
    
    bool isRunning = true;
    int dplt;
    while (isRunning ) {
        cout << endl;
        cout << "Ton Digger est à la position " << ((my_level->getDigger() )->getX()) <<  "   " << ((my_level->getDigger() )->getY()) << endl ;
        cout << "La vie de ton Digger " << (my_level->getDigger())->getLife() << endl << endl;
        
        cout << " Déplacement : " << endl << endl;
        
        cout << " 7 : NordOuest " << " 8 : Nord " << " 9 : NordEst" << endl;
        cout << " 4 : Ouest     " << "          " << " 6 : Est    " << endl;
        cout << " 1 : Sud Ouest " << " 2 : Sud  " << " 3 : SudEst " << endl << endl;
       
        cout << "               Pour arrêter : 5 " << endl;
        
        
        cout << " Entrez votre Déplacement souhaité " << endl;
        cin >> dplt;
        switch ( dplt ) {
            case 1 : my_level->moveSouthWest();
                break;
            case 2 : my_level->moveSouth();
                break;
            case 3 : my_level->moveSouthEast();
                break;
            case 4 : my_level->moveWest();
                break;
            case 5 : isRunning = false;
                break;
            case 6 : my_level->moveEast();
                break;
            case 7 : my_level->moveNorthWest();
                break;
            case 8 : my_level->moveNorth();
                break;
            case 9 : my_level->moveNorthEast();
                break;
        }
        my_level->showTmp();
    }
    
    
    delete my_score;
    delete my_level;
    
    return 0;
}

