#include "SpriteGraphic.h"
#include "../Constantes.h"

sf::Image SpriteGraphic::my_image;

void SpriteGraphic::changeTheme( std::string theme ) {
    
    std::string myimage = "choiceSprite.png";
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