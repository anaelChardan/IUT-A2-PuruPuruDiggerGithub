#ifndef __PuruPuruDigger__EmptyGraphic__
#define __PuruPuruDigger__EmptyGraphic__

/**
 * \file EmptyGraphic.h
 * \brief Notre classe EmptyGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "CellBaseGraphic.h"

#include "GraphicElement.h"

/*! \class EmptyGraphic
 *  \brief Classe pour l'affichage d'une case vide
 */

class EmptyGraphic : public CellBaseGraphic {
    public :
        /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe EmptyGraphic
         */
        virtual ~EmptyGraphic();

        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         *  Affichage e l'image choisi
         */
        virtual void setImageToSprite();
};

#endif /* defined(__PuruPuruDigger__EmptyGraphic__) */
