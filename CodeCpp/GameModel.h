/// @file Game.h
/// @brief Fichier relatif à la gestion générale, du jeu Puru Puru Digger.
/// @author Anaël Chardan
/// @author Jérémy Damey
/// @author Osiris Malbranque
/// @version 0.1
/// @date 17/02/2014

#ifndef __purpurudigger__Game__
#define __purpurudigger__Game__

#include <iostream>
#include <vector>
#include "Level.h"
#include "Score.h"

/// @class Game
/// @brief Modélisation de la gestion du jeu

class GameModel {
    private :
        //Notre level, en vérité infini
        Level* my_level;
        //Un tableau de score ( les scores réalisés par les joueurs dans chacun des level )
        Score* my_score;
    
    public :
        //Le constructeur
        GameModel();
        //Le destructeur
        ~GameModel();
        //Les getteurs
        Score* const getScore();
        Level* const getLevel();
        void orderMovement( int depl );
        bool gameOver() const ;
};

#endif /* defined(__purpurudigger__Game__) */
