#ifndef __PuruPuruDigger__LanguageGraphic__
#define __PuruPuruDigger__LanguageGraphic__

/**
 * \file LanguageGraphic.h
 * \brief Notre classe LanguageGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "GraphicElement.h"

/*! \class LanguageGraphic
 *  \brief Classe pour l'affichage de la charte graphique des langages
 */

class LanguageGraphic : public GraphicElement {
    protected :
        static sf::Image my_image ; /*!< image de fond */

    public :
        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         *  Destructeur de la classe GraphicElement
         */
        virtual void setImageToSprite();

        /*!
         *  \brief Change la couleur du sprite
         */
        void setHover();

        /*!
         *  \brief Reinitialise la couleur de l'image
         *
         */
        void reset();

        /*!
         *  \brief Change la couleur du sprite enfocntion de la position de la souris
         *
         */
        virtual void mouseMoved(sf::Event event);

        /*!
         *  \brief Changer de theme
         *
         *  \param[in] std::string theme
         */
        virtual void changeTheme( std::string theme );

};

#endif /* defined(__PuruPuruDigger__LanguageGraphic__) */
