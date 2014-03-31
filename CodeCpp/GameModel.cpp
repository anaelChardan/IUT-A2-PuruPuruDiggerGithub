/**
 * \file GameModel.cpp
 * \brief Ce que représente une partie
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include "GameModel.h"
using namespace std;

GameModel::GameModel(){
    
    my_score = new Score();
    my_level = new Level( my_score );
}

GameModel::~GameModel() {
    delete my_level;
    delete my_score;
}

void
GameModel::orderMovement( int depl ) {
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

void
GameModel::orderMovement( int xclick, int yclick ) {
    /*
    if ( my_level->isCellClickable( xclick, yclick ) )
        //Maintenant faire les tests de l'emplacement du click
     */
}

bool
GameModel::gameOver() const {
    if ( my_level->isDead() )
        return true;
    else
        return false;
}

Score* const
GameModel::getScore() {
    return my_score;
}

Level* const
GameModel::getLevel() {
    return my_level;
}

void
GameModel::reset() {
    my_score = new Score();
    my_level = new Level( my_score);
}