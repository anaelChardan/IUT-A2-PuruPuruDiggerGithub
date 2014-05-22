
/**
 * \file CellBaseGraphic.cpp
 * \brief Notre classe CellBaseGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include "CellBaseGraphic.h"
#include "../Constantes.h"

sf::Image CellBaseGraphic::my_image;

void CellBaseGraphic::changeTheme( std::string theme ) {
    std::string myimage;
#ifdef __linux__
    myimage = "Ressources/Pictures/" + theme + "_case.png";
#else
    myimage = theme + "_case.png";
#endif
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


