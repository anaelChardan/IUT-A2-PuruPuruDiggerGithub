#ifndef __PuruPuruDigger__TeacherSprite__
#define __PuruPuruDigger__TeacherSprite__

/**
 * \file TeacherSprite.h
 * \brief Notre classe TeacherSprite
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "SpriteGraphic.h"

/*! \class TeacherSprite
 *  \brief Classe pour l'affichage du jeu avec les sprites du professeur
 */

class TeacherSprite : public SpriteGraphic {
    public :
        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         */
        virtual void setImageToSprite();

        /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe TeacherSprite
         */
        virtual ~TeacherSprite();
};

#endif /* defined(__PuruPuruDigger__TeacherSprite__) */
