#ifndef __PuruPuruDigger__GameView__
#define __PuruPuruDigger__GameView__
/**
 * \file GameView.h
 * \brief Affichage de notre partie
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>

#include "GameModel.h"
#include "LanguageMessage.h"

class GameView {
    private :
        Language my_language; /*!<  La langue de notre partie */
        LanguageMessage my_messages; /*!<  La bibliothèque de message de notre partie */

        GameModel * my_model; /*!<  La modèle de notre vue */

        /*!
         *  \brief Affichage Menu principal
         */
        void showPresentation() const;
    
        /*!
         *  \brief Affichage choix des langes
         */
        void showLanguage() const ;
    
        /*!
         *  \brief Affichage des scores
         */
        void showScore()  ;
    
        /*!
         *  \brief Affichage de la grille
         */
        void showGrid() const;
    
        /*!
         *  \brief Affichage des instructions de déplacement
         */
        void showInstruction() ;
    
        /*!
         *  \brief Affichage des meilleurs scores
         */
        void showBestScore() const;
    
        /*!
         *  \brief Entrée d'un nouveau score
         *
         *  \param[in] nom le nom du joueur
         */
        void enterScore(std::string nom) const ;

    public:
    
        /*!
         *  \brief Injection du modèle à la vue
         *
         * param[in] model : le modèle à interpréter  */
        void setModel(GameModel * model);
    
        /*!
         *  \brief La boucle de jeu
         */
        void treatGame();
};

#endif /* defined(__PuruPuruDigger__GameView__) */
