#ifndef __PuruPuruDigger__BackgroundGraphic__
#define __PuruPuruDigger__BackgroundGraphic__

/**
 * \file BacgroundGraphic.h
 * \brief Notre classe BacgroundGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "GraphicElement.h"

/*! \class BacgroundGraphic
 *  \brief Classe pour le changement de thème
 */

class BackgroundGraphic : public GraphicElement {
    protected :
        static sf::Image my_image; /*!< image de fond */

    public :
        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         *  Affichage du thème choisi
         */
        virtual void setImageToSprite();

        /*!
         *  \brief Permet de changer le thème du jeu
         *
         *  Prise en compte du nouveau thème choisi
         *
         * \param[in] std::string theme
         */
        void changeTheme( std::string theme );
};

#endif /* defined(__PuruPuruDigger__BackgroundGraphic__) */
