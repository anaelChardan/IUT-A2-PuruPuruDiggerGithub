/// @file Game.cpp
/// @brief Fichier relatif à l'implémentation de la gestion du jeu Puru Puru Digger.
/// @author Anaël Chardan
/// @author Jérémy Damey
/// @version 0.1
/// @date 17/02/2014

#include "Game.h"
using namespace std;

Game::Game(){
    
    my_score = new Score();
    my_levels = new Level( my_score );
}