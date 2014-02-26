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
    private :
        CellBase* my_digger; //Le digger de notre partie
        std::vector<std::vector<CellBase*> > my_grid; //La grille que nous allons utiliser
        int my_goal; //L'objectif du level qui grossira à chaque fois que nous réussirons le level
        Score* my_score; //Le score de la partie qui l'injectera


    public:

        //Les constructeurs
        Level(Score* score); //Constructeurs paramétré qui permet de prendre en compte le score injecté.

        void shuffle(); //Permet de mélanger un grille
        void reset();
        std::string getCell(int x, int y);
        void init();
        void setCell( int x, int y, std::string type );
        CellBase* getCell() const;
        void setGoal();
        CellBase* getDigger();
        void move( int click_x, int click_y );
        bool isCellClickable( int click_x, int click_y );

};

#endif /* defined(__purpurudigger__Level__) */
