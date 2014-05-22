/**
 * \file SpriteGraphic.cpp
 * \brief Notre classe SpriteGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include "SpriteGraphic.h"
#include "../Constantes.h"

sf::Image SpriteGraphic::my_image;

void SpriteGraphic::changeTheme( std::string theme ) {
    std::string myimage;
#ifdef __linux__
    myimage = "Ressources/Pictures/choiceSprite.png";
#else
    myimage = "choiceSprite.png";
#endif

    if ( !my_image.LoadFromFile( myimage.c_str() ) ) {
        std::cerr << " Error when loading choiceSprite image " << std::endl;
    } else {
        setImageToSprite();
    }
}



void SpriteGraphic::setImageToSprite() {
    my_image.CreateMaskFromColor(sf::Color(0, 55, 97));
    my_sprite.SetImage(my_image);
}
