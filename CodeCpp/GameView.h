//
//  GameView.h
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 26/02/2014.
//
//

#ifndef __PuruPuruDigger__GameView__
#define __PuruPuruDigger__GameView__

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "GameModel.h"
#include "LanguageMessage.h"

class GameView {
    private :
        Language my_language;
        LanguageMessage my_messages;
        GameModel * my_model;
    
        void showPresentation() const;
        void showLanguage();
        void showScore() ;
        void showGrid() const;
        void showInstruction();
        void showBestScore() const;
    
        void enterScore(std::string nom) const ;

    public:
        GameView();
        void setModel(GameModel * model);
        void treatGame();
};

#endif /* defined(__PuruPuruDigger__GameView__) */
