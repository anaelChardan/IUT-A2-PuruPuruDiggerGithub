#include "BackgroundGraphic.h"
#include "Constantes.h"

sf::Image BackgroundGraphic::my_image;


void
BackgroundGraphic::setTeacherMode() {
#ifdef __linux
    if ( my_image.LoadFromFile("Pictures/wallpapperTeach.png" ) )
        setImageToSprite();
#else
    if ( my_image.LoadFromFile("wallpapperTeach.png") ) {
        setImageToSprite();
    }
#endif
    else {
        std::cerr << " Error when loading background image " << std::endl;
    }
}

void
BackgroundGraphic::setAnanasMode() {
#ifdef __linux
    if ( !my_image.LoadFromFile("Pictures/wallpapper.png" ) )
        std::cerr << " Error when loading image " << std::endl;
#else
    if ( !my_image.LoadFromFile("wallpapper.png") ) {
        std::cerr << " Error when loading image " << std::endl;
    }
#endif
    else {
        setImageToSprite();
        std::cerr << " Error when loading image " << std::endl;
    }
}

void
BackgroundGraphic::setImageToSprite() {
    my_sprite.SetImage(my_image);
    my_sprite.Resize( WINDOWWITDH, WINDOWHEIGHT);
    my_sprite.SetPosition(0,0);
}