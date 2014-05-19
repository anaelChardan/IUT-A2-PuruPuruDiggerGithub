#ifndef __PuruPuruDigger__DiggerGraphic__
#define __PuruPuruDigger__DiggerGraphic__

/**
 * \file DiggerGraphic.h
 * \brief Notre classe DiggerGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "CellBaseGraphic.h"

/*! \class DiggerGraphic
 *  \brief Classe pour la gestion du digger
 */

class DiggerGraphic : public CellBaseGraphic {
    public :
        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         *  Affichage du thème choisi
         */
        virtual void setImageToSprite();

        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         *  Affichage de l'image du digger
         */
        virtual ~DiggerGraphic();
};



#endif /* defined(__PuruPuruDigger__DiggerGraphic__) */
