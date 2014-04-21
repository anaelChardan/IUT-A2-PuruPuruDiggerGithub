//
//  GameViewSFML.h
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 12/03/2014.
//
//

#ifndef __PuruPuruDigger__GameViewSFML__
#define __PuruPuruDigger__GameViewSFML__

#include <iostream>

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "CellBaseGraphic.h"
#include "LanguageGraphic.h"
#include "ButtonGraphic.h"
#include "GraphicMusic.h"
#include "GraphicSound.h"
#include "BackgroundGraphic.h"
#include "ValueGraphic.h"
#include "GoldGraphic.h"

#include <string>

#include "GameModel.h"
#include "LanguageMessage.h"
#include "GraphicElement.h"
#include "AnanasSprite.h"
#include "TeacherSprite.h"

class GameView {
    private :

        Language my_language; /*!<  La langue de notre partie */
        LanguageMessage my_messages; /*!<  La bibliothèque de message de notre partie */
        GameModel * my_model; /*!<  La modèle de notre vue */

        std::map< std::string, CellBaseGraphic* > my_stringToSprite;
        std::map< Language, LanguageGraphic* > my_languageToSprite;

        sf::RenderWindow* my_window;

        sf::Font* my_fontScore;
        sf::Font* my_fontTitle;
        sf::Font* my_bestScoreFont;

        sf::String* my_titleScoreString; // Titre des scores
        sf::String* my_scoreString; // Enoncé dans la grille
        sf::String* my_scoreNum; // Les scores en numéro
        sf::String* my_titleString; // Les titres de pages
        sf::String* my_bestScoreString;
    
        ButtonGraphic my_playButton;
        ButtonGraphic my_settingButton;
        ButtonGraphic my_bestButton;
        ButtonGraphic my_quitButton;
    
        GraphicMusic my_musicIcon;
        GraphicSound my_soundIcon;
    
        AnanasSprite my_ananasSprite;
        TeacherSprite my_teacherSprite;
    
        BackgroundGraphic my_background;
    
        GoldCell* ptr_goldCell;
        ValueCell* ptr_valueCell;
        GoldGraphic* ptr_goldGraphic;
        ValueGraphic* ptr_valueGraphic;
    
        bool animation;

        //Pour les sons
        sf::Music *my_musicLevel;
        sf::SoundBuffer *my_buttonBuffer;
        sf::Sound *my_buttonSound;
        sf::SoundBuffer *my_textBuffer;
        sf::Sound *my_textSound;
        sf::SoundBuffer *my_gameOverBuffer;
        sf::Sound *my_gameOverSound;
        sf::SoundBuffer *my_clickableBuffer;
        sf::Sound *my_clickableSoundCell;
        sf::SoundBuffer *my_isNotClickableBuffer;
        sf::Sound *my_isNotClickableSound;
        sf::SoundBuffer *my_loseLevelBuffer;
        sf::Sound *my_loseLevelSound;
    
    
    


    /*!
     *  \brief Affichage Menu principal
     */
    void showPresentation();
    void setButtonHover( sf::Sprite* buttonToHover );
    void resetButtonNorm();
    void resetLanguageNorm();
    void showLanguage();

    void setTextAndDraw( sf::String* s, std::string text, int x, int y, bool useSizeRectX );

    /*!
     *  \brief Affichage choix des langes
     */
    //void showLanguage();
    void showSpriteChoice();
    void showOption();
    void setTeacherMode();
    void setAnanasMode();
    void showIsEnteringABestScore( std::string player );

    /*!
     *  \brief Affichage des scores
     */
    void showScore()  ;
    void showLevel();
    void showLoseLevel( bool time, bool over);
    void showWinLevel();

    /*!
     *  \brief Affichage de la grille
     */
    void showGrid();

    void newScreen();

    /*!
     *  \brief Affichage des instructions de déplacement
     */
    void showInstruction() ;

    /*!
     *  \brief Affichage des meilleurs scores
     */
    void showBestScore();

    /*!
     *  \brief Entrée d'un nouveau score
     *
     *  \param[in] nom le nom du joueur
     */
    void enterScore(std::string nom) const ;
    
    void toAnimate();


public:

    GameView();
    ~GameView();
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



#endif /* defined(__PuruPuruDigger__GameViewSFML__) */
