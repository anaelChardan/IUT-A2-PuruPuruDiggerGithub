#ifndef __PuruPuruDigger__GoldGraphic__
#define __PuruPuruDigger__GoldGraphic__

/**
 * \file GoldGraphic.h
 * \brief Notre classe GoldGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "CellTextGraphic.h"

/*! \class GoldGraphic
 *  \brief Classe pour l'affichage du digger
 */

class GoldGraphic : public CellTextGraphic {
    public :
        /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe GoldGraphic
         */
        virtual ~GoldGraphic();

        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         *  Affichage de l'image choisie
         */
        virtual void setImageToSprite();
};

#endif /* defined(__PuruPuruDigger__GoldGraphic__) */
