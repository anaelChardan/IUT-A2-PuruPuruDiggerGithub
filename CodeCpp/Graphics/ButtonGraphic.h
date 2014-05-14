#ifndef __PuruPuruDigger__ButtonGraphic__
#define __PuruPuruDigger__ButtonGraphic__

/**
 * \file ButtonGraphic.h
 * \brief Notre classe ButtonGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "GraphicElement.h"

/*! \class ButtonGraphic
 *  \brief Classe pour l'affichage des boutons
 */

class ButtonGraphic : public GraphicElement {
    protected :
        static sf::Image my_image; /*!< image du bouton */
        static sf::Font my_font; /*!< fond du bouton */

        sf::String my_string; /*!< texte de l'image */

    public :
        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         *  Affichage du bouton
         */
        virtual void setImageToSprite();

        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         *  Affichage du thème choisi
         *
         *  \param[in] int x
         *  \param[in] int y
         *  \param[in] sf::RenderWindow * _window
         *  \param[in] std::string
         */
        virtual void setSpriteAndDraw( int x, int y, sf::RenderWindow * _window, std::string );

        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         *  Affichage du bouton
         */
        void setHover();
        void reset();
        virtual void draw(sf::RenderWindow* _window) const;
        virtual void mouseMoved(sf::Event event);
        virtual void mouseButtonPressed(sf::Event event);
        virtual void changeTheme( std::string theme );
};

#endif /* defined(__PuruPuruDigger__ButtonGraphic__) */
