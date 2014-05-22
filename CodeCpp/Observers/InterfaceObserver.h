#ifndef __PuruPuruDigger__InterfaceObserver__
#define __PuruPuruDigger__InterfaceObserver__

/**
 * \file InterfaceObserver.h
 * \brief Notre classe InterfaceObserver
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

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

typedef char KonamiCode[10]; /*!<  Typedef pour faciliter l'écriture */

/*! \class InstanceObserver
 *  \brief Classe pour la gestion de l'interface
 */

class InterfaceObserver : public EventObserver {

private:
    sf::RenderWindow* my_window; /*!<  La fenêtre */
    GameModel* my_model; /*!<  Le modele */

    ButtonGraphic* my_playButton; /*!<  Le bouton play */
    ButtonGraphic* my_settingButton; /*!<  Le bouton setting */
    ButtonGraphic* my_bestButton; /*!<  le bouton des meilleurs scores */
    ButtonGraphic* my_quitButton; /*!<  Le bouton quitter */

    GraphicMusic *my_musicIcon; /*!<  Le bouton de la musique */
    GraphicSound *my_soundIcon; /*!<  Le bouton des sons */

    std::map< Language, LanguageGraphic* >* my_languageToSprite; /*!<  La map des languages vers les sprites */

    AnanasSprite *my_ananasSprite; /*!<  L'image de l'ananasMode */
    TeacherSprite *my_teacherSprite; /*!<  L'image du teacher Mode */
    BackgroundGraphic *my_background; /*!<  L'image de font */

    sf::Font* my_fontScore; /*!<  la font des score */
    sf::Font* my_fontTitle; /*!<  La font du titre */
    sf::Font* my_bestScoreFont; /*!<  La font des meilleurs scores */

    sf::String* my_titleScoreString; /*!< Titre des scores*/
    sf::String* my_scoreString; /*!< Enoncé dans la grille*/
    sf::String* my_scoreNum; /*!<Les scores en numéro*/
    sf::String* my_titleString; /*!< Les titres de pages*/
    sf::String* my_bestScoreString; /*!<Pour l'affichage des meilleurs scores*/



    LanguageMessage my_messages; /*!<  La bibliothèque de message de notre partie */
    
    KonamiCode my_konamiCode; /*!<  le code konami que l'on modifie */
    KonamiCode my_trueKonamiCode; /*!<  le bon code konami */
    bool my_cheater; /*!<  savoir si on on triché */


    std::map< std::string, CellBaseGraphic* > my_stringToSprite;

    GoldCell* ptr_goldCell; /*!<  Le pointeur de gold celle */
    ValueCell* ptr_valueCell; /*!<  Le pointeur de valueCell */
    GoldGraphic* ptr_goldGraphic; /*!<  Le pointeur de gold graphic */
    ValueGraphic* ptr_valueGraphic; /*!<  Le pointeur de value graphic */




    std::string player; /*!<  Le nom de ntore joueur */

    sf::Clock pause;    /*!<La clock pour la pause */

    /*!
     *  \brief Affichage Menu principal
     */
    void showPresentation();

    /*!
     *  \brief Affichage Menu principal
     */
    void resetLanguageNorm();

    /*!
     *  \brief donne un text à un string le positionne et l'affiche
     *  param[in] text le string
     *  param[in] s le string qui va recevoir le texte
     *  param[in] x la position en x
     *  param[in] y la position en y
     *  param[in] useSizeRectX pour savoir si on veut centrer selon x
     */
    void setTextAndDraw( sf::String* s, std::string text, int x, int y, bool useSizeRectX );

    /*!
     *  \brief Affichage choix des langues
     */
    void showLanguage();
    
    /*!
     *  \brief Affichage choix des sprites
     */
    void showSpriteChoice();
    
    /*!
     *  \brief Affichage des options
     */
    void showOption();
    
    /*!
     *  \brief Affichage le nom de notre joueur
     *  param[in] player le string de notre joueur
     */
    void showIsEnteringABestScore( std::string player );

    /*!
     *  \brief Affichage des scores
     */
    void showScore();
    
    /*!
     *  \brief Affichage de la grille
     */
    void showGrid();
    
    /*!
     *  \brief Affichage du level
     */
    void showLevel();
    
    /*!
     *  \brief Affichage du message de perte
     */
    void showLoseLevel();
    
    /*!
     *  \brief Affichagedu message de gain
     */
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

    
    /*!
     *  \brief Réalisation de l'animation du digger
     */
    void toAnimate();
    
    /*!
     *  \brief On entre le score
     */
    void enterScore() const;
    
    /*!
     *  \brief On vérifie le code Konami
     */
    bool konamiCode( sf::Event event );
    
    /*!
     *  \brief Initialisation de notre code Konami
     */
    void initKonamiCode();
    



public:

    /*!
     *  \brief Constructeur
     */
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
                      TeacherSprite *teacher,
                      BackgroundGraphic *background
                      );

    /*!
     *  \brief Destructeur
     */
    virtual ~InterfaceObserver();

    
    /*!
     *  \brief Evenement mouse move
     *  param[in] event un evénement
     */
    virtual void mouseMoved(sf::Event event);
    
    /*!
     *  \brief Evenement keypressed
     *  param[in] event un evénement
     */
    virtual void keyPressed(sf::Event event);
    
    /*!
     *  \brief Evenement textentered
     *  param[in] event un evénement
     */
    virtual void textEntered(sf::Event event);
    
    /*!
     *  \brief Evenement button pressed
     *  param[in] event un evénement
     */
    virtual void mouseButtonPressed(sf::Event event);
    
    /*!
     *  \brief Préparation de l'affichage
     */
    virtual void preDisplay();
    
    /*!
     *  \brief fin de l'affichage
     */
    virtual void postDisplay();
    
    /*!
     *  \brief changement de theme
     */
    virtual void changeTheme( std::string theme );


};
#endif /* defined(__PuruPuruDigger__InterfaceObserver__) */
