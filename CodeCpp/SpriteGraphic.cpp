#include "SpriteGraphic.h"
#include "Constantes.h"

sf::Image SpriteGraphic::my_image;


void
SpriteGraphic::setTeacherMode() {
    setAnanasMode();
}

void
SpriteGraphic::setAnanasMode() {
#ifdef __linux
    if ( !my_image.LoadFromFile("Pictures/choiceSprite.png" ) )
        std::cerr << " Error when loading choiceSprite image " << std::endl;
#else
    if ( !my_image.LoadFromFile("choiceSprite.png") ) {
        std::cerr << " Error when loading choiceSprite image " << std::endl;
    }
#endif
    else {
        setImageToSprite();
    }
}

void
SpriteGraphic::setImageToSprite() {
    my_image.CreateMaskFromColor(sf::Color(0, 55, 97));
    my_sprite.SetImage(my_image);
}