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
#include <map>
#include <vector>

#include "GameModel.h"

class GameView {
    private :
        Language my_language;
        std::map< Language, std::map< Message, std::string > > LanguageMessage;
        GameModel * my_model;
    
        void showPresentation() const;
        void showScore( const std::map< Language, std::map< Message, std::string > >LanguageMessage ) const;
    void showInstruction( const std::map< Language, std::map< Message, std::string > >LanguageMessage) const;
        void showMenu() const;
        void showBestScore() const;
        void enterScore(std::string nom) const;
        void initMessage(std::map< Language, std::map< Message, std::string > > &LanguageMessage);
    
    
    public:
        GameView();
        ~GameView();
    
        void setModel(GameModel * model);
        //void synchronize();
        //void afficherScore();
        //void draw();
        bool treatEvents();
};

#endif /* defined(__PuruPuruDigger__GameView__) */
