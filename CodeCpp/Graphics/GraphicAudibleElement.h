#ifndef __PuruPuruDigger__GraphicAudibleElement__
#define __PuruPuruDigger__GraphicAudibleElement__

/**
 * \file GraphicAudibleElement.h
 * \brief Notre classe GraphicAudibleElement
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "GraphicElement.h"

/*! \class GraphicAudibleElement
 *  \brief Classe pour le chargement des sons
 */

class GraphicAudibleElement : public GraphicElement {
    protected :
        static sf::Image my_image ; /*!< image de pour la musique */

    public :
        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         *  Affichage de l'image choisie
         */
        virtual void setImageToSprite();

        virtual void reverse() = 0;

        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         *  Affichage du thème choisi
         *
         * \param[in] std::string theme
         */
        virtual void changeTheme( std::string theme );

        /*!
         *  \brief Changer le bouton s'il y a ou non le son
         *
         *  Affichage du bouton demandé
         */
        virtual void mouseButtonPressed(sf::Event event);
};

#endif /* defined(__PuruPuruDigger__GraphicAudibleElement__) */
