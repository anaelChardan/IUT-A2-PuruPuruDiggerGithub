#ifndef __PuruPuruDigger__AnanasSprite__
#define __PuruPuruDigger__AnanasSprite__

/**
 * \file AnanasSprite.h
 * \brief Notre classe AnanasSprite
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "SpriteGraphic.h"

/*! \class AnanasSprite
 *  \brief Classe pour l'Ananas mode
 */

class AnanasSprite : public SpriteGraphic {
    public :
        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         *  Affichage de l'Ananas mode
         */
        virtual void setImageToSprite();

        /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe AnanasSprite
         */
        virtual ~AnanasSprite();
};

#endif /* defined(__PuruPuruDigger__AnanasSprite__) */
