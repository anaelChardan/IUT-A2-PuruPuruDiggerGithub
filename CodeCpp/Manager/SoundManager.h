#ifndef __PuruPuruDigger__SoundManager__
#define __PuruPuruDigger__SoundManager__

/**
 * \file SoundManager.h
 * \brief Notre classe SoundManager
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include <SFML/Audio.hpp>
#include "../PuruContext.h"

/*! \class GraphicElement
 *  \brief Classe pour la gestion des sons
 */


class SoundManager {

    public:
        /*!
         *  \brief Retourne une instance
         *
         */
        static SoundManager* getInstance() {
            static SoundManager instance;   // Instantiated when this function is called
            return &instance;
        }

        /*!
         *  \brief Active ou non le son
         *
         */
        void clickButton();

        /*!
         *  \brief Selectionne ou non le son
         *
         */
        void clickCell();

        /*!
         *  \brief Active le son
         *
         */
        void playMusic();

        /*!
         *  \brief Met le son en pause
         *
         */
        void pauseMusic();

        /*!
         *  \brief Stop entierement le son
         *
         */
        void stopMusic();

        /*!
         *  \brief Permet de savoir si l'on a perdu un niveau
         *
         */
        void youLoose();

        /*!
         *  \brief Permet de savoir si on a gagné un niveau
         *
         */
        void youWin();

        /*!
         *  \brief Permet de savoir si l'on a perdu la partie
         *
         */
        void gameOver();

        /*!
         *  \brief Permet de savoir si une touche est appuyé
         *
         */
        void touchPress();

        /*!
         *  \brief Modifie la valeur de context
         *
         */
        void setContext( PuruContext *context );

    private:
        /*!
         *  \brief Constructeur par defaut
         *
         * Constructeur de la classe SoundManager
         *
         */
        SoundManager(); // constructor is private

        /*!
         *  \brief Constructeur par copie
         *
         * Constructeur de la classe SoundManager
         *
         */
        SoundManager(SoundManager const&);                 // copy constructor is private

        /*!
         *  \brief Operateur d'affectation
         *
         */
        SoundManager& operator=(SoundManager const&);  // assignment operator is private

        /*!
         *  \brief Destructeur
         *
         * Destructeur de la classe SoundManager
         *
         */
        ~SoundManager();                                 // destructor is private

        PuruContext *my_context; /*!< conetext */

        sf::SoundBuffer *my_textBuffer; /*!< son quand on écrit du texte */
        sf::Sound *my_textSound;

        sf::SoundBuffer *my_gameOverBuffer; /*!< son quand on perd */
        sf::Sound *my_gameOverSound;

        sf::SoundBuffer *my_clickableBuffer; /*!< son quand on clique */
        sf::Sound *my_clickableSoundCell;

        sf::SoundBuffer *my_isNotClickableBuffer; /*!< son quand on déclique */
        sf::Sound *my_isNotClickableSound;

        sf::SoundBuffer *my_loseLevelBuffer; /*!< son quand perd un niveau */
        sf::Sound *my_loseLevelSound;

        sf::SoundBuffer *my_buttonBuffer; /*!< son quand on clique sur un bouton */
        sf::Sound *my_buttonSound;

        sf::Music *my_musicLevel; /*!< music quand on joue un niveau */

};
#endif /* defined(__PuruPuruDigger__SoundManager__) */
