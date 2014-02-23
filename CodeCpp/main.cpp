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

using namespace std;

int main(int argc, const char * argv[])
{

    //insert code here...
   // sf::RenderWindow window(sf::VideoMode(640,480, 32), "Test");
    //sf::Sleep(3.0F);
    
    
    vector<vector<CellBase*> > my_tab;
    
    my_tab.resize(2);
    for( unsigned long i = 0 ; i < 2 ; i++ )
        my_tab[i].resize(2);
    
    my_tab[0][0] = new Digger(0,0);
    my_tab[0][1] = new ValueCell;
    my_tab[1][0] = new ValueCell;
    my_tab[1][1] = new ValueCell;
    
    for ( unsigned long i = 0 ; i < 2; i++ ) {
        for ( unsigned long j = 0 ; j < 2 ; j ++ ) {
            cout << my_tab[i][j]->getType();
            if ( my_tab[i][j]->getType() == "ValueCell" )
                cout << my_tab[i][j]->getValue() << endl;
        }
    }
    
    
    
    return 0;
}

