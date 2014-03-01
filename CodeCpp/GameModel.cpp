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
    my_levels = new Level( my_score );
}

GameModel::~GameModel() { }

void
GameModel::showTMP( int langue ) const {
    my_levels->showTmp( langue );
    my_score->showTmpScore(langue);
    
    cout << " Déplacement :      7 : NordOuest        8 : Nord        9 : NordEst" << endl;
    cout << "                    4 : Ouest                            6 : Est    " << endl;
    cout << "                    1 : Sud Ouest        2 : Sud         3 : SudEst " << endl << endl << endl;
    
    
    cout << "                                     Pour arrêter : 5               " << endl;
    
    
    cout << " Entrez votre Déplacement souhaité " << endl;
}