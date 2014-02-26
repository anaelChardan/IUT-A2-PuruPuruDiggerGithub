/// @file Score.h
/// @brief Fichier relatif à l'implémentation des niveaux du Puru Puru Digger.
/// @author Anaël Chardan
/// @author Jérémy Damey
/// @author Osiris Malbranque
/// @version 0.1
/// @date 17/02/2014

#include "Level.h"
#include "Bomb.h"
#include "GoldCell.h"
#include <vector>
#include <algorithm>

Level::Level(Score* score) {
    //On fait pointé my_score sur l'adresse du score qu'on lui à donné
    my_score = score;


    my_grid.resize( LIGNE );
    for( unsigned long i = 0; i < LIGNE; i++ ) {
        my_grid[i].resize( COLONNE );
    }

    //On alloue le digger
    my_digger = new Digger();

    //On fait pointé notre Digger dessus cette case;
    my_grid[0][0] = my_digger;

    //Calcul du nombre de bombe

    int nbrB = MINOBJ + ( rand() % ( MAXOBJ - MINOBJ ) );

    //Remplissage du tableau avec des bombe
    for ( unsigned long i = 1 ; i <= nbrB; i++ ) {
        my_grid[0][i] = new Bomb;
    }

    //On place les trésors en fonction du nombre de bomb
    for ( unsigned long i = nbrB +1 ; i < COLONNE ; i++ ) {
        my_grid[0][i] = new GoldCell;
    }

    //On rempli tout le reste avec des numéros
    for ( unsigned long i = 1; i < LIGNE; i++ ) {
        for ( unsigned long j = 0; j < COLONNE; j++ ) {
            my_grid[i][j] = new ValueCell;
        }
    }
    //On mélange tout cela
    shuffle();
}

void
Level::shuffle() {

    std::vector<CellBase*> tmp;
    unsigned int taille = LIGNE * COLONNE;
    tmp.resize( taille );
    unsigned long z = 0;

    //2D to 1D
    while ( z < ( taille ) ) {
        for ( int i = 0 ; i < LIGNE ; i++ ){
            for (int j = 0; j < COLONNE ; j++ ){
                tmp[z] = my_grid[i][j];
                z++;
            }
        }
    }

    random_shuffle( tmp.begin(), tmp.end());

    //1D to 2D
    z=0;
    while ( z < taille ) {
        //Parcours en hauteur
        for ( unsigned int i = 0 ; i < LIGNE ; i++ ) {
            //Parcours en longeur
            for ( unsigned int j = 0; j < COLONNE ; j++ ) {
                //On peut maintenant set chaque case avec les bon x et les bon y dont le digger
                my_grid[i][j]->setX(j);
                my_grid[i][j]->setY(i);
                my_grid[i][j] = tmp[z];
                z++;
            }
        }
    }
}

//Quand on perd une partie
void
Level::reset() {

}
