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

#include "GameModel.h"
#include "LanguageMessage.h"

class GameView {
    private :
    
        Language my_language; /*!<  La langue de notre partie */
        LanguageMessage my_messages; /*!<  La bibliothèque de message de notre partie */
        GameModel * my_model; /*!<  La modèle de notre vue */
    
        std::map< std::string, sf::Sprite > my_stringToSprite;
        std::map< Language, sf::Sprite > my_languageToSprite;
    
        sf::RenderWindow* my_window;
    
        sf::Font* my_fontScore;
        sf::Font* my_fontTitle;
        sf::Font* my_fontValue;
        sf::Font* my_fontButton;
    
        sf::String* my_valueString; // Valeurs dans la grille
        sf::String* my_titleScoreString; // Titre des scores
        sf::String* my_scoreString; // Enoncé dans la grille
        sf::String* my_scoreNum; // Les scores en numéro
        sf::String* my_titleString; // Les titres de pages
        sf::String* my_buttonString; // Pour les boutons
    
        //Les images
        sf::Image* my_backgroundImage;
        sf::Image* my_caseImage;
        sf::Image* my_buttonImage;
        sf::Image* my_languageImage;
        sf::Image* my_spriteImage;
    
        //Mes sprites pour les cases
        sf::Sprite* my_diggerSprite;
        sf::Sprite* my_valueSprite;
        sf::Sprite* my_goldSprite;
        sf::Sprite* my_emptySprite;
        sf::Sprite* my_bombSprite;
    
        //Les boutons
        sf::Sprite* my_optionButtonSprite;
        sf::Sprite* my_playButtonSprite;
        sf::Sprite* my_bestButtonSprite;
        sf::Sprite* my_buttonQuitSprite;
        sf::Sprite* my_quitButtonSprite;
    
        //Mon sprite pour le background
        sf::Sprite* my_backgroundSprite;
    
        //Mes sprites pour les langues
        sf::Sprite* my_frenchSprite;
        sf::Sprite* my_englishSprite;
        sf::Sprite* my_deutschSprite;
        sf::Sprite* my_italianoSprite;
        sf::Sprite* my_spanishSprite;
    
        //Les sprites pour les choix de sprite
        sf::Sprite* my_ananasSprite;
        sf::Sprite* my_teacherSprite;
    
        //Pour les sons
        sf::Music *my_musicLevel;
   
    
    void setImageToSprite();
    /*!
     *  \brief Affichage Menu principal
     */
    void showPresentation();
    void setButtonHover( sf::Sprite* buttonToHover );
    void resetButtonNorm();
    void setHoverLanguage( Language hover );
    void resetLanguageNorm();
    void showLanguage();
    
    /*!
     *  \brief Affichage choix des langes
     */
    //void showLanguage();
    void showSpriteChoice();
    void showOption();
    void setTeacherMode();
    void setAnanasMode();
    
    /*!
     *  \brief Affichage des scores
     */
    void showScore()  ;
    void showLevel();
    void showLoseLevel();
    void showWinLevel();
    
    /*!
     *  \brief Affichage de la grille
     */
    void showGrid();
    void showCGrid();
    
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
