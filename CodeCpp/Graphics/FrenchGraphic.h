#ifndef __PuruPuruDigger__FrenchGraphic__
#define __PuruPuruDigger__FrenchGraphic__

/**
 * \file FrenchGraphic.h
 * \brief Notre classe FrenchGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "LanguageGraphic.h"

/*! \class FrenchGraphic
 *  \brief Classe pour l'affichage du jeu en français
 */

class FrenchGraphic : public LanguageGraphic {
    public :
        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         *  Affichage de l'image choisi
         */
        virtual void setImageToSprite();

        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         *  Affichage du jeu en Français
         */
        virtual ~FrenchGraphic();
};

#endif /* defined(__PuruPuruDigger__FrenchGraphic__) */
