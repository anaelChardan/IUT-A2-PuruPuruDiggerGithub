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

using namespace std;

int main(int argc, const char * argv[])
{

    //insert code here...
   // sf::RenderWindow window(sf::VideoMode(640,480, 32), "Test");
    //sf::Sleep(3.0F);
    
    CellBase* my_digger = new Digger;
    
    vector<vector<CellBase*> > my_tab;
    
    my_tab.resize(2);
    for( unsigned long i = 0 ; i < 2 ; i++ )
        my_tab[i].resize(2);
    
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
    
    cout <<  " La vie du digger " << my_tab[0][1]->getLife() << endl;
    cout <<  " La vie d'une case quelconque " << my_tab[0][0]->getLife() << endl;
    
    for ( unsigned long i = 0; i < 2; i++ ) {
        for ( unsigned long j = 0 ; j < 2 ; j++ ) {
            delete my_tab[i][j];
        }
    }
    
    return 0;
}

