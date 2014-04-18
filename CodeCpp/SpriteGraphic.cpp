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
    if ( my_image.LoadFromFile("Pictures/choiceSprite.png" ) )
        setImageToSprite();
#else
    if ( my_image.LoadFromFile("choiceSprite.png") ) {
        setImageToSprite();
    }
#endif
    else {
        std::cerr << " Error when loading choiceSprite image " << std::endl;
    }
}

void
SpriteGraphic::setImageToSprite() {
    my_image.CreateMaskFromColor(sf::Color(0, 55, 97));
    my_sprite.SetImage(my_image);
}