#include "CellBaseGraphic.h"
#include "../Constantes.h"

sf::Image CellBaseGraphic::my_image;

void CellBaseGraphic::changeTheme( std::string theme ) {
#ifdef __linux__
    theme = "../Ressources/Pictures/" + theme;
#endif
    std::string myimage = theme + "_case.png";
    if ( !my_image.LoadFromFile( myimage.c_str() ) ) {
        std::cerr << " Error when loading case image " << std::endl;
    } else {
        setImageToSprite();
    }
}


void CellBaseGraphic::setImageToSprite() {
    my_image.CreateMaskFromColor(sf::Color(0, 55, 97));
    my_sprite.SetImage(my_image);
    my_sprite.Resize( CASEWITDH, CASEHEIGHT);
}


