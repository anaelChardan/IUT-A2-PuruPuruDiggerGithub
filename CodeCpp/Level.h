#ifndef __purpurudigger__Level__
#define __purpurudigger__Level__

/**
 * \file Level.h
 * \brief Les méthodes liées à notre classe level
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "Score.h"
#include "Cell/Digger.h"
#include "Cell/CellBase.h"
#include "Cell/ValueCell.h"
#include "Cell/GoldCell.h"
#include "Cell/Bomb.h"
#include "Constantes.h"
#include <ctime>

typedef std::vector<std::vector<CellBase*> > Grid; /*!<  Typedef pour faciliter l'écriture */

/*! \class Level
 *  \brief Classe modélisant un level
 */
class Level {

    private :
    
        //La composition de notre Level
        Score* my_score;        /*!<  Score de notre Level */
        Digger* my_digger;    /*!<  Digger de notre Level */
        Grid my_grid;           /*!<  Grille de notre Level */
    
    
        //Les objectifs de notre Level
        int my_goal;            /*!<  Objectif en Point de notre Level */
        int my_currentMove;     /*!<  Mouvement en cours */
        int my_bonus;           /*!<  Bonus en Point de notre Level */
    
        //Les attributs temporels
        time_t my_depart;       /*!<  Temps de commencencement du Level */
        float timeGoal;         /*!<  Objectif en temps du Level */
    
        //La connaissance de ce qu'il se passe dans notre Level.
        bool my_win;            /*!<  Savoir si je viens de gagner un Level */
        bool my_lose;           /*!<  Savoir si je viens de perdre un Level */

        ValueCell* ptr_valueCell;
        GoldCell* ptr_goldCell;

    
        /*!
         *  \brief Déplacement du Digger dans la grille
         *
         *  \param[in] DeltaX La direction vertical de déplacement du digger
         *  \param[in] DeltaY La direction horizontal de déplacement du digger
         */
        void move(  int deltaX,  int deltaY );

    
        /*!
         * \brief Mélange d'un tableau en 2D
         */
        void shuffle();
    
        /*!
         *  \brief Génération de la première grille
         */
        void initGrid();
    
        /*!
         * \brief Nouvelle grille après avoir gagné
         */
        void winLevel();
    
    

    public:
        /*!
         * \brief Méthode pour regénerer une grille après avoir perdu ou gagné sans perdre les attributs de notre Digger
         */
        void reset();
        /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Level
         *
         *  \param *score : score de notre partie (injection de dépendance )
         */
        Level(Score* score);

        /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe Level
         */
        ~Level();
    
        /*!
         *  \brief Perdre le level
         *
         *  Faire perdre une vie et regénération d'un niveau
         */
        void lostLevel();
    
        /*!
         *  \brief remettre win a false
         *
         *  remet l'attribut win  false
         */
        void resetWin();
    
        /*!
         *  \brief remettre lose a false
         *
         *  remet l'attribut lose  false
         */
        void resetLose();
    
        /*!
         *  \brief Connaître l'objectif en point du Level
         *
         *  \return my_goal
         */
        int getGoal() const;
    
        /*!
         *  \brief Connaître nos déplacements en cours
         *
         *  \return my_currentMove
         */
        int getCurrentMove() const;
    
        /*!
         *  \brief Connaître si le temps est écoulé
         *
         *  \return true si le temps est écoulé
         */
        bool timeIsUp() const;
    
        /*!
         *  \brief Connaître le temps restant
         *
         *  \return le temps restant
         */
        float leftTime() const;
    
        /*!
         *  \brief Connaître le temps actuelle à jour
         *
         */
        void resetTime();
    
        /*!
         *  \brief Retourner notre digger pour avoir des informations sur lui
         *
         * \return un pointeur sur notre digger
         */
        Digger* const getDigger() const ;
    
        /*!
         *  \brief Connaître si la case est franchissable ( de type numérique et à côté du Digger
         * 
         * param[in] click_x : la position verticale de notre click
         * param[in] click_y : la position horizontale de notre click
         *
         *  \return true si la case est franchissable
         */
        bool isCellClickable( int click_x, int click_y ) const;

        /*!
         *  \brief Renvoyer notre grille ( affichage )
         *
         *  \return my_grid
         */
        const Grid& getGrid() const;
    
        /*!
         *  \brief Connaître si notre Digger est définitivement mort
         *
         *  \return true si il est mort
         */
        bool isDead() const;
    
        /*!
         *  \brief Connaître si l'on vient juste de gagner un niveau ( affichage )
         *
         *  \return true si l'on vient de gagner un niveau
         */
        bool win() const;
    
        /*!
         *  \brief Connaître si l'on vient juste de perdre un niveau ( affichage )
         *
         *  \return true si l'on vient de perdre un niveau
         */
        bool lose() const;

    
        //Tous nos sucres de languages, il appeleront la fonction move avec notre digger et les bons deltas et le nombre de coup
    
        /*!
         * \brief Sucre pour se déplacer à gauche ( deltaX 0, deltaY -1, voir la methode move()
         * \see deplacement
         */
        void moveWest();
    
        /*!
         * \brief Sucre pour se déplacer à droite ( deltaX 0, deltaY 1, voir la methode move()
         * \see deplacement
         */
        void moveEast();
    
        /*!
         * \brief Sucre pour se déplacer en haut ( deltaX -1, deltaY 0, voir la methode move()
         * \see deplacement
         */
        void moveNorth();
    
        /*!
         * \brief Sucre pour se déplacer en bas ( deltaX 1, deltaY 0, voir la methode move()
         * \see deplacement
         */
        void moveSouth();
    
        /*!
         * \brief Sucre pour se déplacer en haut à droite ( deltaX -1, deltaY 1, voir la methode move()
         * \see deplacement
         */
        void moveNorthEast();
    
        /*!
         * \brief Sucre pour se déplacer en haut à gauche ( deltaX -1, deltaY -1, voir la methode move()
         * \see deplacement
         */
        void moveNorthWest();
    
        /*!
         * \brief Sucre pour se déplacer en bas à gauche ( deltaX 1, deltaY -1, voir la methode move()
         * \see deplacement
         */
        void moveSouthWest();
    
        /*!
         * \brief Sucre pour se déplacer en bas à droite ( deltaX 1, deltaY 1, voir la methode move()
         * \see deplacement
         */
        void moveSouthEast();

};

#endif /* defined(__purpurudigger__Level__) */
