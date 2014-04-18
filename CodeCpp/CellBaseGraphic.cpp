#include "CellBaseGraphic.h"
#include "Constantes.h"

sf::Image CellBaseGraphic::my_image;

CellBaseGraphic::CellBaseGraphic() {
    setAnanasMode();
}

CellBaseGraphic::~CellBaseGraphic() { }

void
CellBaseGraphic::setAnanasMode() {
#ifdef __linux
    if ( my_image.LoadFromFile("Pictures/case.png" ) )
        setImageToSprite();
#else
    if ( my_image.LoadFromFile("case.png") ) {
        setImageToSprite();
    }
#endif
    else {
        std::cerr << " Error when loading case image " << std::endl;
    }
}

void
CellBaseGraphic::setTeacherMode() {
#ifdef __linux
    if ( my_image.LoadFromFile("Pictures/caseTeach.png" ) )
        setImageToSprite();
#else
    if ( my_image.LoadFromFile("caseTeach.png") ) {
        setImageToSprite();
    }
#endif
    else {
        std::cerr << " Error when loading caseTeach image " << std::endl;
    }
}

void
CellBaseGraphic::setImageToSprite() {
    my_image.CreateMaskFromColor(sf::Color(0, 55, 97));
    my_sprite.SetImage(my_image);
    my_sprite.Resize( CASEWITDH, CASEHEIGHT);
}


