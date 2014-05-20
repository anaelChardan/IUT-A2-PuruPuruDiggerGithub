#ifndef __PuruPuruDigger__SpanishGraphic__
#define __PuruPuruDigger__SpanishGraphic__

/**
 * \file SpanishGraphic.h
 * \brief Notre classe SpanishGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "LanguageGraphic.h"

/*! \class SpanishGraphic
 *  \brief Classe pour l'affichage du jeu en espagnol
 */

class SpanishGraphic : public LanguageGraphic {
    public :
        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         */
        virtual void setImageToSprite();

        /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe SpanishGraphic
         */
        virtual ~SpanishGraphic();
};

#endif /* defined(__PuruPuruDigger__SpanishGraphic__) */
