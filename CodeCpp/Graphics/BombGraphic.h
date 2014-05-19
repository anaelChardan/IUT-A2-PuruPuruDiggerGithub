#ifndef __PuruPuruDigger__BombGraphic__
#define __PuruPuruDigger__BombGraphic__

/**
 * \file BombGraphic.h
 * \brief Notre classe BombGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */


#include <iostream>
#include "CellBaseGraphic.h"
#include "GraphicElement.h"

/*! \class BombGraphic
 *  \brief Classe l'affichage des bombes
 */

class BombGraphic : public CellBaseGraphic {
    public :
        /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe BombGraphic
         */
        virtual ~BombGraphic();

        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         *  Affichage de l'image bomb
         */
        virtual void setImageToSprite();
};

#endif /* defined(__PuruPuruDigger__BombGraphic__) */
