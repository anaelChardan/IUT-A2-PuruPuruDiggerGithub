#ifndef __PuruPuruDigger__ItalianoGraphic__
#define __PuruPuruDigger__ItalianoGraphic__

/**
 * \file ItalianoGraphic.h
 * \brief Notre classe ItalianoGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "LanguageGraphic.h"

/*! \class ItalianoGraphic
 *  \brief Classe pour l'affichage du jeu en Italien
 */

class ItalianoGraphic : public LanguageGraphic {
    public :
        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         */
        virtual void setImageToSprite();

        /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe ItalianoGraphic
         */
        virtual ~ItalianoGraphic();
};

#endif /* defined(__PuruPuruDigger__ItalianoGraphic__) */
