/// @file Grid.h
/// @brief Fichier relatif au plateau de jeu du Puru Puru Digger.
/// @author Anaël Chardan
/// @author Jérémy Damey
/// @author Osiris Malbranque
/// @version 0.1
/// @date 17/02/2014

#ifndef __purpurudigger__Grid__
#define __purpurudigger__Grid__

#include <iostream>
#include "CellBase.h"
#include "Constantes.h"
#include "Bomb.h"
#include "vector.h"

/// @class Grid
/// @brief Modélisation du plateau de jeu

class Grid {
    private :
        vector<vector<CellBase*> > my_tab;
    
    public :
        Grid(); //Le constructeur par défaut
        void shuffle();
};

#endif /* defined(__purpurudigger__Grid__) */
