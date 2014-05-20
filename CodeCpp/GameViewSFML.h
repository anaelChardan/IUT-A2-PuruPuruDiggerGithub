#ifndef __PuruPuruDigger__GameViewSFML__
#define __PuruPuruDigger__GameViewSFML__

/**
 * \file GameViewSFML.h
 * \brief Notre classe GameViewSFML
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include <SFML/Window.hpp>

#include "GameModel.h"
#include "Graphics/ButtonGraphic.h"
#include "Observers/EventDispatcher.h"
#include "Graphics/GraphicMusic.h"
#include "Graphics/GraphicSound.h"
#include "PuruContext.h"
#include "Graphics/LanguageGraphic.h"
#include "Graphics/AnanasSprite.h"
#include "Graphics/TeacherSprite.h"
#include "Manager/SoundManager.h"
#include "Graphics/BackgroundGraphic.h"

/*! \class GameViewSFML
 *  \brief Classe qui gere tout l'affichage du jeu
 */

class GameView {
    private :

        sf::RenderWindow* my_window; /*!<  La fenetre de notre jeu */
        GameModel * my_model; /*!<  La modèle de notre vue */
        EventDispatcher* my_eventDispatcher;

        ButtonGraphic* my_playButton; /*!<  Le bouton play */
        ButtonGraphic* my_settingButton; /*!<  Le bouton option */
        ButtonGraphic* my_bestButton; /*!<  Le bouton meilleur score */
        ButtonGraphic* my_quitButton; /*!<  Le bouton quitter */

        GraphicMusic *my_musicIcon; /*!<  Le bouton pour la musique */
        GraphicSound *my_soundIcon; /*!<  Le bouton pour le son */

        AnanasSprite *my_ananasSprite; /*!<  Le mode ananas */
        TeacherSprite *my_teacherSprite; /*!<  Le mode du professeur */

        BackgroundGraphic *my_background; /*!<  Le fond de notre jeu */

        std::map< Language, LanguageGraphic* >* my_languageToSprite; /*!<  Le choix des langages */

        PuruContext* my_context; /*!<  Le context */
        SoundManager *my_soundManager; /*!<  Le choix du son */

        /*!
         *  \brief Permet d'aaceder au menu
         */
        void goToPresentation();

        /*!
         *  \brief Permet d'acceder au menu option
         */
        void goToSettings();

        /*!
         *  \brief Permet de jouer
         */
        void goToPlay();

        /*!
         *  \brief Permet d'acceder au score
         */
        void goToScore();

        /*!
         *  \brief Permet de rentrer un score
         */
        void goToEnterScore();

        /*!
         *  \brief Initialise le jeu
         */
        void initView();

        /*!
         *  \brief Initialise le menu
         */
        void initPresentation();

        /*!
         *  \brief Initialise le menu option
         */
        void initSettings();

        /*!
         *  \brief Initailise le smeilleurs score
         */
        void initBestScore();

        /*!
         *  \brief Initialise le fait de saisir un score
         */
        void initEnterScore();

        /*!
         *  \brief Initialise le jeu
         */
        void initPlay();



    public :
         /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe GameViewSFML
         */
         GameView();

         /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe GameViewSFML
         */
        ~GameView();
        /*!
         *  \brief Injection du modèle à la vue
         *
         * \param[in] model : le modèle à interpréter  */
        void setModel(GameModel * model);

    /*!
     *  \brief La boucle de jeu
     */
        void treatGame();
};



#endif /* defined(__PuruPuruDigger__GameViewSFML__) */
