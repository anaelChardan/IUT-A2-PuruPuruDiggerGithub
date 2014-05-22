

#ifndef __PuruPuruDigger__PuruContext__
#define __PuruPuruDigger__PuruContext__

/**
 * \file PuruContext.h
 * \brief Notre classe PuruContext
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "Constantes.h"

/*! \class PuruContext
 *  \brief Classe modélisant les setters et les getters pour faire fonctionner le jeu
 */

class PuruContext {
    private :
        bool my_isInBreak; /*!<  Savoir si le jeu est en pause */
        bool my_isInPresentation; /*!<  Savoir si on est dans le menu principal */
        bool my_isChoosingOption; /*!<  Savoir si on est dans le menu option */
        bool my_isEnterABestScore; /*!<  Savoir si on rentre un score */
        bool my_isPlaying; /*!<  Savoir si on est en train de jouer */
        bool my_isInAnimation; /*!<  Savoir s'il y a l'animation */
        bool my_isOver; /*!<  Savoir si la partie est finie */
        bool my_isTimeOver; /*!<  Savoir si le temps est écoulé */
        bool my_isViewingBestScore; /*!<  savoir si on est dans le tableau des scores */
        bool my_isEnableSound; /*!<  Savoir si le son est activé ou pas */
        bool my_isEnableMusic; /*!<  Savoir si la musique est activé ou pas */
        Language my_language; /*!<  Langage du jeu */
    
    public :
    	/*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe PuruContext
         */
        PuruContext();

        /*!
         *  \brief Setteur du jeu en pause
         *
         *  Affecte si oui ou non le jeu est en pausse
         *
         * \param[in] bool set
         */
        void setInBreak( bool set );

        /*!
         *  \brief Setteur du menu principale
         *
         *  Affecte si oui ou non on est dans le menu
         *
         * \param[in] bool set
         */
        void setInPresentation( bool set );

        /*!
         *  \brief Setteur du menu option
         *
         *  Affecte si oui ou non on est dans le menu option
         *
         * \param[in] bool set
         */
        void setChoosingOption( bool set );

        /*!
         *  \brief Setteur de la saisie des meilleurs score
         *
         *  Affecte si oui ou non on rentre un score
         *
         * \param[in] bool set
         */
        void setEnterABestScore( bool set );

        /*!
         *  \brief Setteur de play
         *
         *  Affecte si oui ou non on est en train de jouer
         *
         * \param[in] bool set
         */
        void setPlaying( bool set );

        /*!
         *  \brief Setteur de animation
         *
         *  Affecte si oui ou non il y a des animations
         *
         * \param[in] bool set
         */
        void setAnimation( bool set );

        /*!
         *  \brief Setteur de over
         *
         *  Affecte si oui ou non la partie est fini
         *
         * \param[in] bool set
         */
        void setOver( bool set );

        /*!
         *  \brief Setteur du temps
         *
         *  Affecte si oui ou non le temps est écoulé
         *
         * \param[in] bool set
         */
        void setTimeOver( bool set );

        /*!
         *  \brief Setteur des meilleurs score
         *
         *  Affecte si oui ou non on est train de saisir un score
         *
         * \param[in] bool set
         */
        void setViewingBestScore( bool set );

        /*!
         *  \brief Setteur du son
         *
         *  Affecte si oui ou non il y a du son
         *
         * \param[in] bool set
         */
        void setSound( bool set );

        /*!
         *  \brief Setteur de musique
         *
         *  Affecte si oui ou non il y a de la musique
         *
         * \param[in] bool set
         */
        void setMusic( bool set );

        /*!
         *  \brief Setteur de langage
         *
         *  Affecte le langage utilisé
         *
         * \param[in] Language language
         */
        void setLanguage( Language language );
    	

    	/*!
         *  \brief Guetteur du menu option
         *
         *  retourne l'option choisi
         */
        bool isChoosingOption() const;

        /*!
         *  \brief Guetteur du jeu en pause
         *
         *  retourne vrai ou faux en fonction si le jeu est en pause ou non
         */
        bool isInBreak() const;

        /*!
         *  \brief Guetteur du menu principal
         *
         *  retourne vrai ou faux en fonction si on est dans le menu principal
         */
        bool isInPresentation() const;

        /*!
         *  \brief Guetteur des meilleurs score
         *
         *  retourne vrai ou faux en fonction si on est en train de saisir un score
         */
        bool isEnterABestScore() const;

        /*!
         *  \brief Guetteur de play
         *
         *  retourne vrai ou faux en fonction si on est en train de jouer ou pas
         */
        bool isPlaying() const;

        /*!
         *  \brief Guetteur des animations
         *
         *  retourne vrai ou faux en fonction si il y a des animations
         */
        bool isInAnimation() const;

        /*!
         *  \brief Guetteur de over
         *
         *  retourne vrai ou faux en fonction si la prati est fini
         */
        bool isOver() const;

        /*!
         *  \brief Guetteur du temps
         *
         *  retourne vrai ou faux en fonction si le temps est écoulé
         */
        bool isTimeOver() const;

        /*!
         *  \brief Guetteur du menu principales meilleurs score
         *
         *  retourne vrai ou faux en fonction si on est dans le menu des meilleurs score
         */
        bool isViewingBestScore() const;

        /*!
         *  \brief Guetteur des sons
         *
         *  retourne vrai ou faux en fonction si il y a un son
         */
        bool isEnableSound() const;

        /*!
         *  \brief Guetteur des musiques
         *
         *  retourne vrai ou faux en fonction si il y a de la musique
         */
        bool isEnableMusic() const;

        /*!
         *  \brief Guetteur du langage
         *
         *  retourne le lnagage
         */
        Language getLanguage() const;
};

#endif /* defined(__PuruPuruDigger__PuruContext__) */
