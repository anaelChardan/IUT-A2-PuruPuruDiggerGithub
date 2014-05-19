#ifndef __PuruPuruDigger__DeutschGraphic__
#define __PuruPuruDigger__DeutschGraphic__

/**
 * \file DeutschGraphic.h
 * \brief Notre classe DeutschGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "LanguageGraphic.h"

/*! \class DeutschGraphic
 *  \brief Classe pour l'affichage du jeu en Allemand
 */

class DeutschGraphic : public LanguageGraphic {
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
         *  Affichage de tout le jeu en Allemand
         */
        virtual ~DeutschGraphic();
};

#endif /* defined(__PuruPuruDigger__DeutschGraphic__) */
