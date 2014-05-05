#include "ButtonGraphic.h"
#include "../Constantes.h"

sf::Image ButtonGraphic::my_image;
sf::Font ButtonGraphic::my_font;



void ButtonGraphic::changeTheme( std::string theme ) {
std::string myimage;
std::string myfont;
#ifdef  __linux__
    myimage = "Ressources/Pictures/" + theme + "_button.png";
    myfont = "Ressources/Font/" + theme + "_buttonfont.ttf";

    if ( theme == "teacher" ) {
        myfont = "Ressources/Font/" + theme + "_arial.ttf";
    }
#else
    myimage = theme + "_button.png";
    myfont = theme + "_buttonfont.ttf";

    if ( theme == "teacher" ) {
        myfont = theme + "_arial.ttf";
    }
#endif
    if ( !my_image.LoadFromFile( myimage.c_str() ) || ( !my_font.LoadFromFile( myfont.c_str() ) )  ) {
        std::cerr << " Error when loading button images and fonts " << std::endl;
    } else {
        my_string.SetFont( my_font );
        my_string.SetSize(30);

        if ( theme == "ananas" ) {
            my_string.SetColor(sf::Color(251,210,98));
        } else {
            my_string.SetColor(sf::Color(0,0,0));
        }

        setImageToSprite();

    }
}

void ButtonGraphic::setImageToSprite() {
    my_image.CreateMaskFromColor(sf::Color(0, 55, 97));
    my_sprite.SetImage(my_image);
    my_sprite.SetSubRect( sf::IntRect( BUTTONNORMSX, BUTTONCASEBEGIN, BUTTONNORMEX, BUTTONCASEHEIGHT ) );
    my_sprite.Resize( BUTTONWIDTH, BUTTONHEIGHT);
}

void ButtonGraphic::setHover() {
    my_sprite.SetSubRect( sf::IntRect( BUTTONHOVESX, BUTTONCASEBEGIN, BUTTONHOVEEX, BUTTONCASEHEIGHT ) );
}

void ButtonGraphic::reset() {
    my_sprite.SetSubRect( sf::IntRect( BUTTONNORMSX, BUTTONCASEBEGIN, BUTTONNORMEX, BUTTONCASEHEIGHT ) );
}


void ButtonGraphic::setSpriteAndDraw(int x, int y, sf::RenderWindow* _window, std::string _string) {
    GraphicElement::setSpriteAndDraw( x, y, _window);
    my_string.SetText(_string);
    my_string.SetPosition( my_sprite.GetPosition().x + ( my_sprite.GetSize().x / 2 ) - ( my_string.GetRect().GetWidth() / 2 ), my_sprite.GetPosition().y + ( my_sprite.GetSize().y / 2 ) - ( my_string.GetRect().GetHeight() / 2 ) );
    _window->Draw(my_string);

}

void ButtonGraphic::draw(sf::RenderWindow *_window) const {
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
        SoundManager::getInstance()->clickButton();
    }
    reset();
}
