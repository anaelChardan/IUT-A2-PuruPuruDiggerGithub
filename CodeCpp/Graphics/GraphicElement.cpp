
/**
 * \file GraphicElement.cpp
 * \brief Notre classe GraphicElement
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include "GraphicElement.h"

void GraphicElement::setSpriteAndDraw(int x, int y, sf::RenderWindow *_window ) {
    my_sprite.SetPosition( x, y );
    _window->Draw(my_sprite);
}


GraphicElement::~GraphicElement() { }

bool GraphicElement::isInZone(int x, int y) const {
    if ( x >= my_sprite.GetPosition().x && x <= ( my_sprite.GetPosition().x + my_sprite.GetSize().x ) && y >= my_sprite.GetPosition().y && y <= ( my_sprite.GetPosition().y + my_sprite.GetSize().y ) )
        return true;
    else
        return false;
}

void GraphicElement::draw(sf::RenderWindow *_window) const {
    ///On affiche à l'écran notre sprite
    _window->Draw(my_sprite);
}

int GraphicElement::getXPos() const {
    ///On retourne la position du sprite
    return my_sprite.GetPosition().x;
}

int GraphicElement::getYPos() const {
    return my_sprite.GetPosition().y;
}


/** Events Subscriber */

void GraphicElement::mouseMoved( sf::Event event ) {}
void GraphicElement::keyPressed( sf::Event event ) {}
void GraphicElement::textEntered( sf::Event event ) {}
void GraphicElement::mouseButtonPressed( sf::Event event ) {}
void GraphicElement::postDisplay() {}
void GraphicElement::preDisplay() {}
void GraphicElement::changeTheme( std::string theme ) {}
