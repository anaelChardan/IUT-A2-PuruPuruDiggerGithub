/// @file Score.h
/// @brief Fichier relatif à l'implémentation des niveaux du Puru Puru Digger.
/// @author Anaël Chardan
/// @author Jérémy Damey
/// @version 0.1
/// @date 17/02/2014

#include "Level.h"
#include "Bomb.h"
#include "GoldCell.h"
#include "EmptyCell.h"
#include <vector>
#include <algorithm>

/*===========================
 Le constructeur
 =============================*/

Level::Level(Score* score) {
    //On fait pointé my_score sur l'adresse du score qu'on lui à donné
    my_score = score;
    my_currentMove = 0;
    my_goal = 10;
    my_bonus = 100;
    //On alloue le digger
    my_digger = new Digger();

    my_grid.resize( LIGNE );
    for( unsigned long i = 0; i < LIGNE; i++ ) {
        my_grid[i].resize( COLONNE );
    }

    //On fait pointé notre Digger dessus cette case;
    my_grid[0][0] = my_digger;

    //Calcul du nombre de bombe

    unsigned int nbrB = MINOBJ + ( rand() % ( MAXOBJ - MINOBJ ) );

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

    // Il faut vérifier si l'on ne sort pas du tableau
    
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
    
    std::cout << " Ton Score : " << std::endl;
    my_score->showTmpScore();
    std::cout << " Move  " << my_currentMove << std::endl;
    std::cout << " Target " << std::endl;
    std::cout << "   " << my_goal << std::endl;
}

std::string
Level::getTypeCell( int x, int y ) const {
    return my_grid[x][y]->getType();
}

void
Level::move( int DeltaX, int DeltaY ) {
    //On veut savoir de combien de coup on veut se déplacer
    int nbStep = my_grid[ (my_digger->getX() + DeltaX) ][ (my_digger->getY() + DeltaY ) ]->getValue();

    //On veut connaître les points en jeu
    int pointInGame = my_grid[ (my_digger->getX() + DeltaX) ][ (my_digger->getY() + DeltaY ) ]->getPoints();

    int cpt = 0;
    
    //Tant que l'on à pas fait le bon nombre de coup et que la case d'a côté est bien une gold ou une value
    while ( cpt < nbStep && ( isCellClickable( ( my_digger->getX() + DeltaX ), ( my_digger->getY() + DeltaY ) ) ) ) {
        //Si pendant que notre Digger se déplace, il passe sur une case de trésor
        //Pour l'instant, on lui fait prendre des points supplémentaires, mais après, l'on pourra mettre aléatoirement, de la vie
        //des points ou du temps avec le modulo TEMPSMAX ou MODULO VIEMAX
        if ( my_grid[ ( my_digger->getX() + DeltaX ) ][ ( my_digger->getY() + DeltaY ) ]->getType() == "GoldCell" ) {
            my_score->addPoints( my_grid[ ( my_digger->getX() + DeltaX ) ][ ( my_digger->getY() + DeltaY ) ]->getPoints() );
        }
        
        //On delete la case suivante
        delete my_grid[ ( my_digger->getX() + DeltaX ) ][ ( my_digger->getY() + DeltaY ) ];
        
        //On y place notre digger
        my_grid[ ( my_digger->getX() + DeltaX ) ][ ( my_digger->getY() + DeltaY ) ] = my_digger;
        
        //On remplace notre ancienne case du digger par une case Vide
        my_grid[ my_digger->getX() ][ my_digger->getY() ] = new EmptyCell( my_digger->getX(), my_digger->getY() );
       
        //On set les case de notre digger
        my_digger->setX( my_digger->getX() + DeltaX );
        my_digger->setY( my_digger->getY() + DeltaY );
        
        //On passe au coup suivant
        cpt++;
    }
    
    //Si le déplacement s'est mal passé ( donc cpt a bougé et est différent de 0 )
    //Les autres renvoient -1
    if ( cpt != 0 &&  cpt < nbStep ) {
        my_digger->lostLife();
        
    } else if ( nbStep != -1 ){
        my_currentMove += nbStep;
        my_score->addPoints(pointInGame);
    }

}

/*===========================
 Les sucres
 =============================*/

//On se déplace vers l'ouest ( gauche )
void
Level::moveWest(){
    move( 0, -1 );
}

//On se déplace vers l'est ( droite )
void
Level::moveEast() {
    move( 0, 1 );
}

//On se déplace vers le nord ( en haut )
void
Level::moveNorth() {
    move( -1, 0 );
}

//On se déplace vers le sud ( en bas )
void
Level::moveSouth() {
    move( 1, 0 );
}

//On se déplace vers le nord est ( haut + droite )
void
Level::moveNorthEast() {
    move( -1, +1 );
}

// On se déplace vers le nord ouest ( haut + gauche )
void
Level::moveNorthWest() {
    move( -1, -1 );
}

// On se déplace vers le sud ouest ( bas + gauche )
void
Level::moveSouthWest() {
    move( 1, -1 );
}

// On se déplace vers le sud est ( bas + droite )
void
Level::moveSouthEast() {
    move( 1, 1 );
}


