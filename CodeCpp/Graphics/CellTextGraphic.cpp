#include "CellTextGraphic.h"

sf::Font CellTextGraphic::my_font;

CellTextGraphic::~CellTextGraphic() { }

void
CellTextGraphic::setAnanasMode() {
#ifdef __linux__
    if ( !my_font.LoadFromFile("../Ressources/Font/valueFont.ttf") ) {
        std::cerr << " Error when loading valueFont.ttf " << std::endl;
    }
#else
    if ( !my_font.LoadFromFile("valueFont.ttf") )
        std::cerr << " Error when loading valueFont.ttf" << std::endl;
#endif
    else {
        my_string.SetFont(my_font);
        my_string.SetSize(23);
        my_string.SetColor(sf::Color(255,255,255));
        CellBaseGraphic::setAnanasMode();
    }
}

void
CellTextGraphic::setTeacherMode() {
#ifdef __linux__
    if ( !my_font.LoadFromFile("../Ressources/Font/arial.ttf") ) {
        std::cerr << " Error when loading valueFont.ttf " << std::endl;
    }
#else
    if ( !my_font.LoadFromFile("arial.ttf") )
        std::cerr << " Error when loading valueFont.ttf" << std::endl;
#endif
    else {
        my_string.SetFont(my_font);
        my_string.SetSize(20);
        my_string.SetColor(sf::Color(0,0,0));
        my_string.SetStyle( sf::String::Bold );
        CellBaseGraphic::setTeacherMode();
    }
}
void
CellTextGraphic::setSpriteAndDraw(int x, int y, sf::RenderWindow* _window, std::string _string) {
    GraphicElement::setSpriteAndDraw( x, y, _window);
    my_string.SetText(_string);
    my_string.SetPosition( my_sprite.GetPosition().x + ( my_sprite.GetSize().x / 2 ) - ( my_string.GetRect().GetWidth() / 2 ), my_sprite.GetPosition().y + ( my_sprite.GetSize().y / 2 ) - ( my_string.GetRect().GetHeight() / 2 ) );
    _window->Draw(my_string);

}

void
CellTextGraphic::setImageToSprite() {
    CellBaseGraphic::setImageToSprite();
}
