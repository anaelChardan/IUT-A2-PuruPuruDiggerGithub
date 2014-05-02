#include "GraphicAudibleElement.h"
#include "../Constantes.h"

sf::Image GraphicAudibleElement::my_image;

GraphicAudibleElement::~GraphicAudibleElement() { }

GraphicAudibleElement::GraphicAudibleElement() : isOn(true) { }

void
GraphicAudibleElement::setTeacherMode() {
    setAnanasMode();
}

void
GraphicAudibleElement::setAnanasMode() {
#ifdef __linux
    if ( !my_image.LoadFromFile("../Ressources/Pictures/icon.png" ) )
        std::cerr << " Error when loading icon image " << std::endl;
#else
    if ( !my_image.LoadFromFile("icon.png") ) {
        std::cerr << " Error when loading icon image " << std::endl;
    }
#endif
    else {
        setImageToSprite();
    }
}

void
GraphicAudibleElement::setImageToSprite() {
    my_image.CreateMaskFromColor(sf::Color(0, 55, 97));
    my_sprite.SetImage(my_image);
    my_sprite.Resize( ICONWIDTH, ICONHEIGHT);
}

bool
GraphicAudibleElement::getOnOff() const {
    return isOn;
}


/** Events Subscriber */

void GraphicAudibleElement::mouseMoved( sf::Event event ) {}
void GraphicAudibleElement::keyPressed( sf::Event event ) {}
void GraphicAudibleElement::textEntered( sf::Event event ) {}

void GraphicAudibleElement::mouseButtonPressed( sf::Event event ) {
    if ( isInZone( event.MouseButton.X, event.MouseButton.Y ) ) {
        reverse();
    }
}
void GraphicAudibleElement::postDisplay() {}
void GraphicAudibleElement::preDisplay() {}