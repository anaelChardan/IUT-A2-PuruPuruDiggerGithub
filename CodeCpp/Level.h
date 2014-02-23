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
#include "Digger.h"
#include "CellBase.h"
#include "Bomb.h"
#include "Constantes.h"

/// @class Level
/// @brief Modélisation des niveaux du jeu
class Level {
    vector<vector<CellBase*> > my_grid;
    int my_goal;
    void init();
    Score* my_score;
    string getCell(int x, int y);
    CellBase* my_digger;
    public:
        Level(Score* score);
        void shuffle();
    
};

#endif /* defined(__purpurudigger__Level__) */
