//
//  Grid.cpp
//  purpurudigger
//
//  Created by Ananas-Mac on 16/02/2014.
//  Copyright (c) 2014 Ananas-Mac. All rights reserved.
//

#include "Grid.h"
#include "Bomb.h"
#include "Digger.h"

Grid::Grid() {
    //On fait que notre matrice fasse
    my_tab.resize(LIGNE);
    for( int i = 0 ; i < LIGNE ; i++ )
        my_tab[i].resize(COLONNE);
    
    //Mise en place du digger
  
    my_tab[0][0] = new Digger;
    
    //Calcul du nombre de bomb
    
    //Calcul du nombre de tresor
    
    //Remplissage du reste par des numéros
    

}

void
Grid::shuffle(){
    
    vector<CellBase*> tmp;
    tmp.resize(25);
    int z = 0;
    
    //2D to 1D
    while ( z < 25 ) {
        for ( int i = 0 ; i < 5 ; i++ ){
            for (int j = 0; j < 5 ; j++ ){
                tmp[z] = my_tab[i][j];
                z++;
            }
        }
    }
    
    random_shuffle( tmp.begin(), tmp.end());
 
    //1D to 2D
    z=0;
    while ( z < 25 ) {
        for ( int i = 0 ; i < 5 ; i++ ){
            for (int j = 0; j < 5 ; j++ ){
                my_tab[i][j] = tmp[z];
                z++;
            }
        }
    }
}