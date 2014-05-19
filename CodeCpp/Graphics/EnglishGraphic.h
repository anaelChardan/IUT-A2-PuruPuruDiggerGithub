#ifndef __PuruPuruDigger__EnglishGraphic__
#define __PuruPuruDigger__EnglishGraphic__

/**
 * \file EnglishGraphic.h
 * \brief Notre classe EnglishGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "LanguageGraphic.h"

/*! \class EnglishGraphic
 *  \brief Classe pour l'affichage du jeu en anglais
 */

class EnglishGraphic : public LanguageGraphic {
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
         *  Affichage du jeu en Anglais
         */
        virtual ~EnglishGraphic();
};

#endif /* defined(__PuruPuruDigger__EnglishGraphic__) */
