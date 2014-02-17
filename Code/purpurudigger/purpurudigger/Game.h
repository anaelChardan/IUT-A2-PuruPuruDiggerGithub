/// @file Score.h
/// @brief Fichier relatif à la gestion générale, du jeu Puru Puru Digger.
/// @author Anaël Chardan
/// @author Jérémy Damey
/// @author Osiris Malbranque
/// @version 0.1
/// @date 17/02/2014

#ifndef __purpurudigger__Game__
#define __purpurudigger__Game__

#include <iostream>
#include "Level.h"
#include "Score.h"

/// @class Score
/// @brief Modélisation de la gestion du jeu

class Game {
    //Un tableau de level je ne sais pas comment on l'alloue (55 pour tester la compilation)
    Level my_lvl[55];
    //Un tableau de score ( les scores réalisés par les joueurs dans chacun des level )
    Score my_score[];
};

#endif /* defined(__purpurudigger__Game__) */
