#include "GraphicElement.h"

void
GraphicElement::setSpriteAndDraw(int x, int y, sf::RenderWindow *_window ) {
    my_sprite.SetPosition( x, y );
    _window->Draw(my_sprite);
}


GraphicElement::~GraphicElement() { }

bool
GraphicElement::isInZone(int x, int y) const {
    if ( x >= my_sprite.GetPosition().x && x <= ( my_sprite.GetPosition().x + my_sprite.GetSize().x ) && y >= my_sprite.GetPosition().y && y <= ( my_sprite.GetPosition().y + my_sprite.GetSize().y ) )
        return true;
    else
        return false;
}

void
GraphicElement::draw(sf::RenderWindow *_window) const {
    _window->Draw(my_sprite);
}

int
GraphicElement::getXPos() const {
    return my_sprite.GetPosition().x;
}

int
GraphicElement::getYPos() const {
    return my_sprite.GetPosition().y;
}