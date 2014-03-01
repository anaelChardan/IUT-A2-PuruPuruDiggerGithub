/// @file Game.cpp
/// @brief Fichier relatif à l'implémentation de la gestion du jeu Puru Puru Digger.
/// @author Anaël Chardan
/// @author Jérémy Damey
/// @version 0.1
/// @date 17/02/2014

#include "GameModel.h"
using namespace std;

GameModel::GameModel(){
    
    my_score = new Score();
    my_level = new Level( my_score );
}

GameModel::~GameModel() { }

void
GameModel::showTMP( int langue ) const {
    my_level->showTmp( langue );
    my_score->showTmpScore(langue);
    
    cout << " Déplacement :      7 : NordOuest        8 : Nord        9 : NordEst" << endl;
    cout << "                    4 : Ouest                            6 : Est    " << endl;
    cout << "                    1 : Sud Ouest        2 : Sud         3 : SudEst " << endl << endl << endl;
    
    
    cout << "                                     Pour arrêter : 5               " << endl;
    
    
    cout << " Entrez votre Déplacement souhaité  : ";
}

void
GameModel::movement( int depl ) {
    switch ( depl ) {
        case 1 : my_level->moveSouthWest();
            break;
        case 2 : my_level->moveSouth();
            break;
        case 3 : my_level->moveSouthEast();
            break;
        case 4 : my_level->moveWest();
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
}