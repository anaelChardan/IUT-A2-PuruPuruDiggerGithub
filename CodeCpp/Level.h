/// @file Level.h
/// @brief Fichier relatif aux niveaux du Puru Puru Digger.
/// @author Anaël Chardan
/// @author Jérémy Damey
/// @author Osiris Malbranque
/// @version 0.1
/// @date 17/02/2014

#ifndef __purpurudigger__Level__
#define __purpurudigger__Level__

#include <iostream>
#include "Score.h"
#include "Grid.h"

/// @class Level
/// @brief Modélisation des niveaux du jeu
class Level {
    Score my_score;
    Grid my_grid;
    int my_target; //Objectif du level
};

#endif /* defined(__purpurudigger__Level__) */
