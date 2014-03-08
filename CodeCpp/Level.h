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

typedef std::vector<std::vector<CellBase*> > Grid;

/// @class Level
/// @brief Modélisation des niveaux du jeu
class Level {

    private :
        //Les attributs privés
        Score* my_score; //Le score de la partie qui l'injectera
        CellBase* my_digger; //Le digger de notre partie
        Grid my_grid; //La grille que nous allons utiliser
        int my_goal; //L'objectif du level en nombre de mouvement qui grossira à chaque fois que nous réussirons le level
        int my_currentMove;
        int my_bonus; // Ce que rapportera en point bonus notre level
        bool my_win; //Savoir si je viens de gagner un level
        bool my_lose; //Savoir si je viens de perdre un level

        //Function to know time
        time_t my_depart;
        float timeGoal;
    
        //Une méthode privé qui ne se fera appelé que par les fonctions public, delta X et delta Y étant la direction
        void move(  int deltaX,  int deltaY );

        void shuffle(); //Permet de mélanger un grille
        void initGrid();
        void winLevel();
        void lostLevel();
        void setGoal();

    public:

        //Les constructeurs
        Level(Score* score); //Constructeurs paramétré qui permet de prendre en compte le score injecté.

        //Le destructeur
        ~Level();

        void reset(); // Permet de rebrasser notre grille quand on a gagné ou quand on a perdu sans perdre les attributs de notre digger
        std::string getCell(int x, int y);
        void setCell( int x, int y, std::string type );
        int getGoal() const;
        bool timeIsUp() const;
        float leftTime() const;
        void resetTime();
        std::string getTypeCell(   int click_x,  int click_y ) const;
        CellBase* getDigger();
        bool isCellClickable( int click_x, int click_y ); //Savoir si une case est clickable ( il faut que ce soit une valueCell ou une goldCell et qu'elle soit placé à côté du Digger ) Elle ne servira que quand on devra recueillir des clicks

        const Grid& getGrid() const;
        bool isDead() const;
        bool win() const;
        bool lose() const;
        int getCurrentMove() const;

        //Tous nos sucres de languages, il appeleront la fonction move avec notre digger et les bons deltas et le nombre de coup
        void moveWest();
        void moveEast();
        void moveNorth();
        void moveSouth();
        void moveNorthEast();
        void moveNorthWest();
        void moveSouthWest();
        void moveSouthEast();

};

#endif /* defined(__purpurudigger__Level__) */
