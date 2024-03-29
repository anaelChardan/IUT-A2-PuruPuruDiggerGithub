#ifndef __purpurudigger__Game__
#define __purpurudigger__Game__

/**
 * \file GameModel.h
 * \brief Ce que représente une partie
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include <vector>
#include "Level.h"
#include "Score.h"

/*! \class GameModel
 *  \brief Classe modélisant une partie
 */

class GameModel {
    private :
        Level* my_level; /*!<  Nos Levels ( en vérité un mais infini ) */
        Score* my_score; /*!<  Les scores de notre partie */
        Movement my_movement;


    public :
        /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe GameModel
         */
        GameModel();

        /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe GameModel
         */
        ~GameModel();

        /*!
         *  \brief Retourner notre score ( affichage )
         *
         * \return un pointeur constant sur le score
         */
        Score* const getScore();

        /*!
         *  \brief Retourner notre Level ( affichage )
         *
         * \return un pointeur constant sur le level
         */
        Level* const getLevel();

        /*!
         *  \brief Ordonner un mouvement à notre grille
         *
         *  \param[in] le mouvement
         */
        void orderMovement( int depl );

        /*!
         *  \brief Ordonner un mouvement à notre grille en fonction de la position de la souris
         *
         *  \param[in] int xclick
         *  \param[in] int yclick
         */
        void orderMovement( int xclick , int yclick );

        /*!
         *  \brief Retourne le mouvement
         *
         */
        Movement getMovement() const;

        /*!
         *  \brief Savoir si la partie est terminée
         *
         *  \return true si la partie est finie
         */
        bool gameOver() const ;

    void reset() ;
};

#endif /* defined(__purpurudigger__Game__) */
