#ifndef __PuruPuruDigger__GraphicSound__
#define __PuruPuruDigger__GraphicSound__

/**
 * \file GraphicSound.h
 * \brief Notre classe GraphicSound
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "GraphicAudibleElement.h"

/*! \class GraphicSound
 *  \brief Classe pour l'affichage des sons
 */

class GraphicSound : public GraphicAudibleElement {
    public :
        /*!
         *  \brief configurer le sprite par rapport à l'image
         *
         *  Destructeur de la classe GraohicElement
         */
        virtual void setImageToSprite();

        /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe GraohicSound
         */
        virtual ~GraphicSound();

        /*!
         *  \brief Inverse le son
         *
         *  Si le son est activé, cela le desactice et inversement
         */
        virtual void reverse();
};

#endif /* defined(__PuruPuruDigger__GraphicSound__) */
