#ifndef __PuruPuruDigger__SpriteGraphic__
#define __PuruPuruDigger__SpriteGraphic__

/**
 * \file SpriteGraphic.h
 * \brief Notre classe SpriteGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "GraphicElement.h"

/*! \class SpriteGraphic
 *  \brief Classe pour l'affichage des images
 */

class SpriteGraphic : public GraphicElement {
    protected :
        static sf::Image my_image ; /*!< image de fond */

    public :
        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         */
        virtual void setImageToSprite();

        /*!
         *  \brief Changer le theme
         *
         *  \param[in] std::string theme
         */
        virtual void changeTheme( std::string theme );
};

#endif /* defined(__PuruPuruDigger__SpriteGraphic__) */
