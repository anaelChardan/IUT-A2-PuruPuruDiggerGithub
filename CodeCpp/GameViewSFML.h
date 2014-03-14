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

#include "GameModel.h"
#include "LanguageMessage.h"

class GameView {
    private :
    Language my_language; /*!<  La langue de notre partie */
    LanguageMessage my_messages; /*!<  La bibliothèque de message de notre partie */
    GameModel * my_model; /*!<  La modèle de notre vue */
    
    sf::RenderWindow* my_window;
    
    sf::Font* my_fontScore;
    sf::Font* my_fontTitle;
    sf::Font* my_fontValue;
    
    sf::String* my_valueString;
    sf::String* my_scoreString;
    sf::String* my_titleString;
    
    sf::Image* my_backgroundImage;
    sf::Image* my_caseImage;
    sf::Image* my_buttonImage;
    
    sf::Sprite* my_diggerSprite;
    sf::Sprite* my_valueSprite;
    sf::Sprite* my_goldSprite;
    sf::Sprite* my_emptySprite;
    sf::Sprite* my_bombSprite;
    sf::Sprite* my_backgroundSprite;
    sf::Sprite* my_playButtonSprite;
    
    
    
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
