#ifndef __PuruPuruDigger__CellBaseGraphic__
#define __PuruPuruDigger__CellBaseGraphic__

/**
 * \file CellBaseGraphic.h
 * \brief Notre classe CellBaseGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "GraphicElement.h"

/*! \class CellBaseGraphic
 *  \brief Classe pour la gestion des cases numérotés
 */

class CellBaseGraphic : public GraphicElement {
    protected :
        static sf::Image my_image; /*!< image de fond */

    public :
        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         *  Affichage de l'image
         */
        virtual void setImageToSprite();

        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         *  Affichage du thème choisi, permet de changer de thème
         *
         * \param[in] std::string theme
         */
        virtual void changeTheme( std::string theme );
};

#endif /* defined(__PuruPuruDigger__CellBaseGraphic__) */
