#ifndef __PuruPuruDigger__GraphicMusic__
#define __PuruPuruDigger__GraphicMusic__

/**
 * \file GraphicMusic.h
 * \brief Notre classe GraphicMusic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "GraphicAudibleElement.h"

/*! \class GraphicMusic
 *  \brief Classe pour l'affichage des boutons representant la musique
 */

class GraphicMusic : public GraphicAudibleElement {
    public :
        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         */
        virtual void setImageToSprite();

        /*!
         *  \brief Constructeur par defaut
         *
         *  Constructeur de la classe GraphicMusic
         */
        GraphicMusic();

        /*!
         *  \brief Inverse la musique
         *
         *  Si musique est activé, cela la desactive et inversement
         */
        virtual void reverse();

        /*!
         *  \brief Gestion de la musique avec la souris
         *
         * \param[in] sf::Event event
         */
        virtual void mouseButtonPressed(sf::Event event);
};

#endif /* defined(__PuruPuruDigger__GraphicMusic__) */
