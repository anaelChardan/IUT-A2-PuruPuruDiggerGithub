#ifndef __PuruPuruDigger__InterfaceObserver__
#define __PuruPuruDigger__InterfaceObserver__

#include <iostream>
#include "EventObserver.h"
#include "../Graphics/ButtonGraphic.h"
#include "../Constantes.h"
#include "../Graphics/LanguageGraphic.h"
#include "../LanguageMessage.h"
#include "../Graphics/AnanasSprite.h"
#include "../Graphics/ValueGraphic.h"
#include "../Graphics/GoldGraphic.h"
#include "../Graphics/TeacherSprite.h"
#include "../Graphics/BackgroundGraphic.h"
#include "../GameModel.h"
#include <string>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../Graphics/CellBaseGraphic.h"
#include "../Graphics/GraphicMusic.h"
#include "../Graphics/GraphicSound.h"

class InterfaceObserver : public EventObserver {
    
private:
    
    ButtonGraphic* my_playButton;
    ButtonGraphic* my_settingButton;
    ButtonGraphic* my_bestButton;
    ButtonGraphic* my_quitButton;
    
    GraphicMusic *my_musicIcon;
    GraphicSound *my_soundIcon;
    
    std::map< Language, LanguageGraphic* >* my_languageToSprite;
    
    sf::Font* my_fontScore;
    sf::Font* my_fontTitle;
    sf::Font* my_bestScoreFont;
    
    sf::String* my_titleScoreString; // Titre des scores
    sf::String* my_scoreString; // Enoncé dans la grille
    sf::String* my_scoreNum; // Les scores en numéro
    sf::String* my_titleString; // Les titres de pages
    sf::String* my_bestScoreString; //Pour l'affichage des meilleurs scores
    
    
    
    LanguageMessage my_messages; /*!<  La bibliothèque de message de notre partie */
    
    AnanasSprite *my_ananasSprite;
    TeacherSprite *my_teacherSprite;
    
    BackgroundGraphic my_background;
    
    
    std::map< std::string, CellBaseGraphic* > my_stringToSprite;
    
    GoldCell* ptr_goldCell;
    ValueCell* ptr_valueCell;
    GoldGraphic* ptr_goldGraphic;
    ValueGraphic* ptr_valueGraphic;
    
    
    sf::RenderWindow* my_window;
    GameModel * my_model;
    
    std::string player;
    
    sf::Clock pause;        //La clock pour la pause
    
    /*!
     *  \brief Affichage Menu principal
     */
    void showPresentation();
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
    
    InterfaceObserver(
                      sf::RenderWindow* window,
                      GameModel * model,
                      ButtonGraphic *play,
                      ButtonGraphic *setting,
                      ButtonGraphic *best,
                      ButtonGraphic *quit,
                      GraphicMusic *music,
                      GraphicSound *sound,
                      std::map< Language, LanguageGraphic* >* languageToSprite,
                      AnanasSprite *ananas,
                      TeacherSprite *teacher
                      );
    
    ~InterfaceObserver();
    
    virtual void mouseMoved(sf::Event event);
    virtual void keyPressed(sf::Event event);
    virtual void textEntered(sf::Event event);
    virtual void mouseButtonPressed(sf::Event event);
    virtual void preDisplay();
    virtual void postDisplay();
    
    
    
};
#endif /* defined(__PuruPuruDigger__InterfaceObserver__) */
