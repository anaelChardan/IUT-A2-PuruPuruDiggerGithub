#include "BackgroundGraphic.h"
#include "../Constantes.h"

sf::Image BackgroundGraphic::my_image;


void
BackgroundGraphic::setTeacherMode() {
#ifdef __linux
    if ( !my_image.LoadFromFile("../Ressources/Pictures/wallpapperTeach.png" ) )
        std::cerr << " Error when loading background image " << std::endl;
#else
    if ( !my_image.LoadFromFile("wallpapperTeach.png") ) {
        std::cerr << " Error when loading background image " << std::endl;
    }
#endif
    else {
        setImageToSprite();
    }
}

void
BackgroundGraphic::setAnanasMode() {
#ifdef __linux
    if ( !my_image.LoadFromFile("../Ressources/Pictures/wallpapper.png" ) )
        std::cerr << " Error when loading background image " << std::endl;
#else
    if ( !my_image.LoadFromFile("wallpapper.png") ) {
        std::cerr << " Error when loading background image " << std::endl;
    }
#endif
    else {
        setImageToSprite();
    }
}

void
BackgroundGraphic::setImageToSprite() {
    my_sprite.SetImage(my_image);
    my_sprite.Resize( WINDOWWITDH, WINDOWHEIGHT);
    my_sprite.SetPosition(0,0);
}