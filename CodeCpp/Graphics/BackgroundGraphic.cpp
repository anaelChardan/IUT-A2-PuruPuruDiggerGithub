#include "BackgroundGraphic.h"
#include "../Constantes.h"

sf::Image BackgroundGraphic::my_image;



void BackgroundGraphic::changeTheme( std::string theme ) {
#ifdef __linux__
    theme = "Ressources/Pictures/" + theme;
#endif
    std::string myimage = theme + "_wallpapper.png";
    if ( !my_image.LoadFromFile( myimage.c_str() ) ) {
        std::cerr << " Error when loading background image " << std::endl;
    } else {
        setImageToSprite();
    }
}


void BackgroundGraphic::setImageToSprite() {
    my_sprite.SetImage(my_image);
    my_sprite.Resize( WINDOWWITDH, WINDOWHEIGHT);
    my_sprite.SetPosition(0,0);
}
