#include "LanguageGraphic.h"
#include "../Constantes.h"

sf::Image LanguageGraphic::my_image;


void
LanguageGraphic::setTeacherMode() {
    setAnanasMode();
}

void
LanguageGraphic::setAnanasMode() {
#ifdef __linux
    if ( !my_image.LoadFromFile("../Ressources/Pictures/languages.png" ) )
        std::cerr << " Error when loading languages image " << std::endl;
#else
    if ( !my_image.LoadFromFile("languages.png") ) {
        std::cerr << " Error when loading languages image " << std::endl;
    }
#endif
    else {
        setImageToSprite();

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