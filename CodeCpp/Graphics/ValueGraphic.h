#ifndef __PuruPuruDigger__ValueGraphic__
#define __PuruPuruDigger__ValueGraphic__

/**
 * \file ValueGraphic.h
 * \brief Notre classe ValueGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "CellTextGraphic.h"

/*! \class ValueGraphic
 *  \brief Classe pour l'affichage des chiffres dans les cases
 */

class ValueGraphic : public CellTextGraphic {
    public :
        /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe ValueGraphic
         */
        virtual ~ValueGraphic();

        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         */
        virtual void setImageToSprite();
};

#endif /* defined(__PuruPuruDigger__ValueGraphic__) */
