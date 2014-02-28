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
    
    //On met nos mouvements courants à 0
    my_currentMove = 0;
    
    //Comme c'est le premier niveau, l'objectif est 10
    my_goal = 10;
    
    //Comme c'est le premier niveau, le bonus généré par le level est 500
    my_bonus = 500;
    
    //On alloue le digger
    my_digger = new Digger();

    //On bloque la taille de notre vecteur
    my_grid.resize( LIGNE );
    
    for( unsigned long i = 0; i < LIGNE; i++ ) {
        my_grid[i].resize( COLONNE );
    }

    //On fait pointé notre Digger dessus cette case;
    my_grid[0][0] = my_digger;

    //On appelle la fonction n'initialisation
    initGrid();
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
 Les méthodes privés
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

//Gagner un level
void
Level::winLevel() {
    //On additionne le bonus au score courant
    my_score->addPoints( my_bonus );
    //On dit que l'on fait un nouveau niveau
    my_score->addSuccess();
    //On augmente le bonus du level
    my_bonus += 500;
    //On augmente la difficulté
    my_goal +=10;
    //On remet nos mouvements à 0
    my_currentMove = 0;
    //On reset le level
    reset();
}

//Perdre un level
void
Level::lostLevel() {
    //On fait perdre une vie au digger
    my_digger->lostLife();
    //On reset le score actuel
    my_score->resetScore();
    //On remet nos mouvements à 0
    my_currentMove = 0;
    //On reset le level
    reset();
}

//Initialiser une grille
void
Level::initGrid() {
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


//Quand on perd une partie
void
Level::reset() {
    //On efface la nouvelle place du digger
    delete my_grid[0][0];
    
    //On la remplace par le digger
    my_grid[0][0] = my_digger;
    
    //On remplace notre case du digger par une case vide
    my_grid[ my_digger->getX() ][ my_digger->getY() ] = new EmptyCell( my_digger->getX(), my_digger->getY() );
    
    //On delete toutes la premmière ligne sauf le digger
    for ( unsigned int i = 1; i < COLONNE; i++ ) {
        delete my_grid[0][i];
    }
    
    //On delete les autres lignes
    for ( unsigned long i = 1; i < LIGNE; i++ ) {
        for ( unsigned long j = 0; j < COLONNE; j++ ) {
            delete my_grid[i][j];
        }
    }
    
    initGrid();

}



void
Level::move( int DeltaX, int DeltaY ) {
    //On veut savoir de combien de coup on veut se déplacer
    int nbStep = my_grid[ (my_digger->getX() + DeltaX) ][ (my_digger->getY() + DeltaY ) ]->getValue();

    //On veut connaître les points en jeu
    int pointInGame = my_grid[ (my_digger->getX() + DeltaX) ][ (my_digger->getY() + DeltaY ) ]->getPoints();

    //On met notre compteur à 0
    int cpt = 0;
    
    //Tant que l'on à pas fait le bon nombre de coup et que la case d'a côté est bien une gold ou une value
    while ( cpt < nbStep && ( isCellClickable( ( my_digger->getX() + DeltaX ), ( my_digger->getY() + DeltaY ) ) ) ) {
        
        //Si l'on rencontre un trésor pendant un déplacement
        if ( my_grid[ ( my_digger->getX() + DeltaX ) ][ ( my_digger->getY() + DeltaY ) ]->getType() == "GoldCell" ) {
            //On prend les points du bonus
            my_score->addPoints( my_grid[ ( my_digger->getX() + DeltaX ) ][ ( my_digger->getY() + DeltaY ) ]->getPoints() );
        }
        
        //On delete la case suivante
        delete my_grid[ ( my_digger->getX() + DeltaX ) ][ ( my_digger->getY() + DeltaY ) ];
        
        //On y place notre digger
        my_grid[ ( my_digger->getX() + DeltaX ) ][ ( my_digger->getY() + DeltaY ) ] = my_digger;
        
        //On remplace notre ancienne case du digger par une case Vide avec un autoSet
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
        lostLevel();
    } else if ( nbStep != -1 ){
        my_currentMove += nbStep;
        my_score->addPoints(pointInGame);
        
        //Si on a atteint l'objectif
        if ( my_currentMove >= my_goal ) {
            winLevel();
        }
    }

}

/*===========================
 Les méthodes publics
 =============================*/

//Permet de vérifier sur une case est clickable
bool
Level::isCellClickable( int click_x, int click_y ){
    
    int x = my_digger->getX();
    int y = my_digger->getY();
    
    // Il faut vérifier si l'on ne sort pas du tableau
    if ( click_x == -1 || click_x == LIGNE || click_y == -1 || click_y == COLONNE ) {
        return false;
    }
    
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

//Affiche notre niveau temporairement, en attendant le GameView
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

//Connaître le type d'une case
std::string
Level::getTypeCell( int x, int y ) const {
    return my_grid[x][y]->getType();
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


