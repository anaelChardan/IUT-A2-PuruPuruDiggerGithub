#include "LanguageGraphic.h"
#include "Constantes.h"

sf::Image LanguageGraphic::my_image;


void
LanguageGraphic::setTeacherMode() {
    setAnanasMode();
}

void
LanguageGraphic::setAnanasMode() {
#ifdef __linux
    if ( my_image.LoadFromFile("Pictures/languages.png" ) )
        setImageToSprite();
#else
    if ( my_image.LoadFromFile("languages.png") ) {
        setImageToSprite();
    }
#endif
    else {
        std::cerr << " Error when loading languages image " << std::endl;
    }
}

void
LanguageGraphic::setImageToSprite() {
    my_image.CreateMaskFromColor(sf::Color(0, 55, 97));
    my_sprite.SetImage(my_image);
}

void
LanguageGraphic::setHover() {
   my_sprite.SetColor(sf::Color(255,255,255,128));
}

void
LanguageGraphic::reset() {
    my_sprite.SetColor(sf::Color(255,255,255,255));
}