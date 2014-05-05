#include "BackgroundGraphic.h"
#include "../Constantes.h"

sf::Image BackgroundGraphic::my_image;



void BackgroundGraphic::changeTheme( std::string theme ) {
    std::string myimage;
#ifdef __linux__
    myimage = "Ressources/Pictures/" + theme + "_wallpapper.png";
#else
    myimage = theme + "_wallpapper.png";
#endif
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
