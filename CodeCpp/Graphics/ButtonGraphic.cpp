#include "ButtonGraphic.h"
#include "../Constantes.h"
#include <SFML/Audio.hpp>

sf::Image ButtonGraphic::my_image;
sf::Font ButtonGraphic::my_font;

sf::SoundBuffer ButtonGraphic::my_buttonBuffer;
sf::Sound ButtonGraphic::my_buttonSound;

void
ButtonGraphic::setTeacherMode() {

    if ( !my_image.LoadFromFile("buttonTeach.png" ) || !my_font.LoadFromFile("arial.ttf") || !my_buttonBuffer.LoadFromFile("soundButton.wav") )
        std::cerr << " Error when loading button image or button font" << std::endl;
    else {
        my_buttonSound.SetBuffer(my_buttonBuffer);
        my_string.SetFont( my_font );
        my_string.SetSize(30);
        my_string.SetColor(sf::Color(0,0,0));
        setImageToSprite();
    }
}

void
ButtonGraphic::setAnanasMode() {
    if ( !my_image.LoadFromFile("buttonAnanas.png" ) || !my_font.LoadFromFile("buttonFont.ttf") || !my_buttonBuffer.LoadFromFile("soundButton.wav") )
        std::cerr << " Error when loading button image or button font " << std::endl;
    else {
        my_buttonSound.SetBuffer(my_buttonBuffer);
        my_string.SetFont( my_font );
        my_string.SetSize(30);
        my_string.SetColor(sf::Color(251,210,98));
        setImageToSprite();
    }
}


void
ButtonGraphic::setImageToSprite() {
    my_image.CreateMaskFromColor(sf::Color(0, 55, 97));
    my_sprite.SetImage(my_image);
    my_sprite.SetSubRect( sf::IntRect( BUTTONNORMSX, BUTTONCASEBEGIN, BUTTONNORMEX, BUTTONCASEHEIGHT ) );
    my_sprite.Resize( BUTTONWIDTH, BUTTONHEIGHT);
}

void
ButtonGraphic::setHover() {
    my_sprite.SetSubRect( sf::IntRect( BUTTONHOVESX, BUTTONCASEBEGIN, BUTTONHOVEEX, BUTTONCASEHEIGHT ) );
}

void
ButtonGraphic::reset() {
    my_sprite.SetSubRect( sf::IntRect( BUTTONNORMSX, BUTTONCASEBEGIN, BUTTONNORMEX, BUTTONCASEHEIGHT ) );
}


void
ButtonGraphic::setSpriteAndDraw(int x, int y, sf::RenderWindow* _window, std::string _string) {
    GraphicElement::setSpriteAndDraw( x, y, _window);
    my_string.SetText(_string);
    my_string.SetPosition( my_sprite.GetPosition().x + ( my_sprite.GetSize().x / 2 ) - ( my_string.GetRect().GetWidth() / 2 ), my_sprite.GetPosition().y + ( my_sprite.GetSize().y / 2 ) - ( my_string.GetRect().GetHeight() / 2 ) );
    _window->Draw(my_string);
    
}

void
ButtonGraphic::draw(sf::RenderWindow *_window) const {
    _window->Draw(my_sprite);
    _window->Draw(my_string);
}



/** Events Subscriber */

void ButtonGraphic::mouseMoved( sf::Event event ) {
    if ( isInZone( event.MouseMove.X, event.MouseMove.Y ) ) {
        setHover();
    } else {
        reset();
    }
}

void ButtonGraphic::mouseButtonPressed( sf::Event event ) {
    if ( isInZone( event.MouseButton.X, event.MouseButton.Y ) ) {
        if ( my_context->isEnableSound() ) {
            my_buttonSound.Play();
        }
    } else {
        // nothing
    }
}

void ButtonGraphic::keyPressed( sf::Event event ) {}
void ButtonGraphic::textEntered( sf::Event event ) {}
void ButtonGraphic::postDisplay() {}
void ButtonGraphic::preDisplay() {}
