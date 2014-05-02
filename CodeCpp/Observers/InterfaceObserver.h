//
//  InterfaceObserver.h
//  PuruPuruDigger
//
//
//

#ifndef __PuruPuruDigger__InterfaceObserver__
#define __PuruPuruDigger__InterfaceObserver__

#include <iostream>
#include "EventObserver.h"
#include "ButtonGraphic.h"
#include "../Constantes.h"
#include "../Graphics/LanguageGraphic.h"
#include "LanguageMessage.h"
#include "GraphicMusic.h"
#include "GraphicSound.h"
#include "AnanasSprite.h"
#include "ValueGraphic.h"
#include "GoldGraphic.h"
#include "TeacherSprite.h"
#include "BackgroundGraphic.h"
#include "GameModel.h"
#include <string>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "../Graphics/CellBaseGraphic.h"


class InterfaceObserver : public EventObserver {
    
private:
    bool isInPresentation;   // Pour savoir si il est sur le menu de départ
    bool isChoosingOption; // Pour savoir si il est le menu du choix des options
    bool isViewingBestScore;
    bool isEnterABestScore;
    bool isPlaying;
    
    ButtonGraphic my_playButton;
    ButtonGraphic my_settingButton;
    ButtonGraphic my_bestButton;
    ButtonGraphic my_quitButton;
    
    std::map< Language, LanguageGraphic* > my_languageToSprite;
    
    sf::Font* my_fontScore;
    sf::Font* my_fontTitle;
    sf::Font* my_bestScoreFont;
    
    sf::String* my_titleScoreString; // Titre des scores
    sf::String* my_scoreString; // Enoncé dans la grille
    sf::String* my_scoreNum; // Les scores en numéro
    sf::String* my_titleString; // Les titres de pages
    sf::String* my_bestScoreString; //Pour l'affichage des meilleurs scores
    
    
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
    
    
    Language my_language; /*!<  La langue de notre partie */
    LanguageMessage my_messages; /*!<  La bibliothèque de message de notre partie */
    GraphicMusic my_musicIcon;
    GraphicSound my_soundIcon;
    
    AnanasSprite my_ananasSprite;
    TeacherSprite my_teacherSprite;
    
    BackgroundGraphic my_background;
    
    
    std::map< std::string, CellBaseGraphic* > my_stringToSprite;
    GoldCell* ptr_goldCell;
    ValueCell* ptr_valueCell;
    GoldGraphic* ptr_goldGraphic;
    ValueGraphic* ptr_valueGraphic;
    
    
    sf::RenderWindow* my_window;
    GameModel * my_model;
    
    
    
    bool animation;
    bool time;
    bool over;
    
    std::string player;
    
    sf::Clock pause;        //La clock pour la pause
    bool isInBreak = false; //Pour savoir quand on est en pause
    
    /*!
     *  \brief Affichage Menu principal
     */
    void showPresentation();
    void resetButtonNorm();
    void resetLanguageNorm();
    
    void setTextAndDraw( sf::String* s, std::string text, int x, int y, bool useSizeRectX );
    
    /*!
     *  \brief Affichage choix des langes
     */
    void showLanguage();
    void showSpriteChoice();
    void showOption();
    void setTeacherMode();
    void setAnanasMode();
    void showIsEnteringABestScore( std::string player );
    
    /*!
     *  \brief Affichage des scores
     */
    void showScore();
    void showGrid();
    void showLevel();
    void showLoseLevel();
    void showWinLevel();
    
    /*!
     *  \brief Clear le screen
     */

    void newScreen();
    
    /*!
     *  \brief Affichage des instructions de déplacement
     */
    void showInstruction() ;
    
    /*!
     *  \brief Affichage des meilleurs scores
     */
    void showBestScore();
    
    
    void toAnimate();
    void enterScore() const;
    

    
public:
    
    InterfaceObserver( sf::RenderWindow* window, GameModel * model );
    ~InterfaceObserver();
    
    virtual void mouseMoved(sf::Event event);
    virtual void keyPressed(sf::Event event);
    virtual void textEntered(sf::Event event);
    virtual void mouseButtonPressed(sf::Event event);
    virtual void preDisplay();
    virtual void postDisplay();
    
    
    
};
#endif /* defined(__PuruPuruDigger__InterfaceObserver__) */
