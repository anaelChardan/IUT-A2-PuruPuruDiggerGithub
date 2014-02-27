/// @file Score.h
/// @brief Fichier relatif à l'implémentation des niveaux du Puru Puru Digger.
/// @author Anaël Chardan
/// @author Jérémy Damey
/// @version 0.1
/// @date 17/02/2014

#include "Level.h"
#include "Bomb.h"
#include "GoldCell.h"
#include <vector>
#include <algorithm>

/*===========================
 Le constructeur
 =============================*/

Level::Level(Score* score) {
    //On fait pointé my_score sur l'adresse du score qu'on lui à donné
    my_score = score;

    //On alloue le digger
    my_digger = new Digger();

    my_grid.resize( LIGNE );
    for( unsigned long i = 0; i < LIGNE; i++ ) {
        my_grid[i].resize( COLONNE );
    }

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

/*===========================
 Le destructeur
 =============================*/

Level::~Level() {
    for ( unsigned long i = 0; i < LIGNE; i++ ) {
        for ( unsigned long j = 0; j < COLONNE; j++ ) {
            delete my_grid[i][j];
        }
    }
}

/*===========================
 Les méthodes
 =============================*/

//Brasse un tableau
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
                my_grid[i][j] = tmp[z];
                //On peut maintenant set chaque case avec les bon x et les bon y dont le digger
                my_grid[i][j]->setX(i);
                my_grid[i][j]->setY(j);
                z++;
            }
        }
    }
}

//Quand on perd une partie
void
Level::reset() {

}

//Permet de vérifier sur une case est clickable
bool
Level::isCellClickable( int click_x, int click_y ){

    int x = my_digger->getX();
    int y = my_digger->getY();
    
    //Il faut d'abord vérifier que la case est juste à côté de notre digger
    if ( ( ( click_x <= x - 1 ) || ( click_x <= x + 1 ) ) && ( ( click_y <= y - 1 ) || ( click_y <= y + 1 ) ) ) {
        //On vérifie son type
        if ( my_grid[click_x][click_y]->getType() == "ValueCell" || my_grid[click_x][click_y]->getType() == "GoldCell" ) {
            return true;
        }
    }
    return false;
}

//Retourne notre Digger
CellBase*
Level::getDigger() {
    return my_digger;
}


void
Level::showTmp() const {
    for ( unsigned long z = 0; z < (COLONNE * 5 + 3); z++ )
        std::cout << "-";
    std::cout << std::endl;
    for ( unsigned long i = 0; i < LIGNE; i++ ) {
        std::cout << " | ";
        for ( unsigned long j = 0; j < COLONNE; j++ ) {
            std::cout << *my_grid[i][j] << " | ";
        }
        std::cout << std::endl;
        for ( unsigned long z = 0; z < (COLONNE * 5 + 3); z++ )
            std::cout << "-";
        std::cout << std::endl;
    }
}

void
Level::move( int DeltaX, int DeltaY, int nbCoup ) { }

/*===========================
 Les sucres
 =============================*/

//On se déplace vers l'ouest ( gauche )
void
Level::moveWest(){
    //Provisoire vu que dans le mode terminal, les clicks sont connus
    if ( isCellClickable( ( my_digger->getX() ), ( my_digger->getY() - 1 ) ) ) {
        //On veut savoir de combien de coup on veut se déplacer
        int nbCoup = my_grid[ my_digger->getX() ][ (my_digger->getY() - 1 ) ]->getValue();
        move( 0, -1, nbCoup );
    }
}

//On se déplace vers l'est ( droite )
void
Level::moveEast() {
    //Provisoire vu que dans le mode terminal, les clicks sont connus
    if ( isCellClickable( ( my_digger->getX() ), ( my_digger->getY() + 1 ) ) ) {
        //On veut savoir de combien de coup on veut se déplacer
        int nbCoup = my_grid[ my_digger->getX() ][ ( my_digger->getY() + 1 ) ]->getValue();
        move( 0, 1, nbCoup );
    }
}

//On se déplace vers le nord ( en haut )
void
Level::moveNorth() {
    //Provisoire vu que dans le mode terminal, les clicks sont connus
    if ( isCellClickable( ( my_digger->getX() - 1 ), ( my_digger->getY() ) ) ) {
        //On veut savoir de combien de coup on va se déplacer
        int nbCoup = my_grid[ ( my_digger->getX() - 1 ) ][ my_digger->getY() ]->getValue();
        move( -1, 0, nbCoup );
    }
}

//On se déplace vers le sud ( en bas )
void
Level::moveSouth() {
    //Provisoire vu que dans le mode terminal, les clicks sont connus
    if ( isCellClickable( ( my_digger->getX() + 1 ), ( my_digger->getY() ) ) ) {
        //On veut savoir de combien de coup on va se déplacer
        int nbCoup = my_grid[ ( my_digger->getX() + 1 ) ][ my_digger->getY() ]->getValue();
        move( 1, 0, nbCoup );
    }
}

//On se déplace vers le nord est ( haut + droite )
void
Level::moveNorthEast() {
    //Provisoire vu que dans le mode terminal, les clicks sont connus
    if ( isCellClickable( ( my_digger->getX() - 1 ), ( my_digger->getY() + 1 ) ) ) {
        //On veut savoir de combien de coup on va se déplacer
        int nbCoup = my_grid[ ( my_digger->getX() - 1 ) ][ ( my_digger->getY() + 1 ) ]->getValue();
        move( -1, +1, nbCoup );
    }
}

// On se déplace vers le nord ouest ( haut + gauche )
void
Level::moveNorthWest() {
    //Provisoire vu que dans le mode terminal, les clicks sont connus
    if ( isCellClickable( ( my_digger->getX() - 1 ), ( my_digger->getY() - 1 ) ) ) {
        //On veut savoir de combien de coup on va se déplacer
        int nbCoup = my_grid[ ( my_digger->getX() - 1 ) ][ ( my_digger->getY() - 1 ) ]->getValue();
        move( -1, -1, nbCoup );
    }
}

// On se déplace vers le sud ouest ( bas + gauche )
void
Level::moveSouthWest() {
    //Provisoire vu que dans le mode terminal, les clicks sont connus
    if ( isCellClickable( ( my_digger->getX() + 1 ), ( my_digger->getY() - 1 ) ) ) {
        //On veut savoir de combien de coup on va se déplacer
        int nbCoup = my_grid[ ( my_digger->getX() + 1 ) ][ ( my_digger->getY() - 1 ) ]->getValue();
        move( 1, -1, nbCoup );
    }
}

// On se déplace vers le sud est ( bas + droite )
void
Level::moveSouthEast() {
    //Provisoire vu que dans le mode terminal, les clicks sont connus
    if ( isCellClickable( ( my_digger->getX() + 1 ), ( my_digger->getY() + 1 ) ) ) {
        //On veut savoir de combien de coup on va se déplacer
        int nbCoup = my_grid[ ( my_digger->getX() + 1 ) ][ ( my_digger->getY() + 1 ) ]->getValue();
        move( 1, 1, nbCoup );
    }
}


