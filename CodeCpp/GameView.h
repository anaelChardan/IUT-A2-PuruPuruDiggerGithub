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

class GameView {
    private :
        int my_w;
        int my_h;
    
        //sf::RenderWindow * _window;
        //sf::Font* _font;
    
        //sf::Image* _background_image;
        //sf::Image* _ball_image;
        //sf::Image* _bat_image;
    
    //  GraphicElement _background_graph;
    //  GraphicElement _bomb_graph;
    //  GraphicElement _digger_graph;
    //  GraphicElement _gold_graph;
    //  GraphicElement _value_graph;
    
    //std::map<Movable_Element * const, GraphicElement *> _elementToGraphicElement;
    
    //GameModel * _model;
    
    public:
        GameView(int w, int h, int bpp);
        ~GameView();
    
        void setModel(GameModel * model);
        //void synchronize();
        //void afficherScore();
        //void draw();
        bool treatEvents();
};

#endif /* defined(__PuruPuruDigger__GameView__) */
