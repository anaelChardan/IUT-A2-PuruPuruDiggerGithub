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
         *  \brief Affichage des informations du sprite demandé
         *
         *  Affichage des informations du sprite demandé
         */
        void setHover();

        /*!
         *  \brief Affichage du sprite à sa position initiale
         *
         *  Affiche le sprite demandé à sa position de depart
         */
        void reset();

        /*!
         *  \brief Dessine le sprite et affiche le texte associé
         *
         *  Dessine le sprite et affiche le texte associé
         */
        virtual void draw(sf::RenderWindow* _window) const;

        /*!
         *  \brief Change le boutton de couleur
         *
         *  Le boutton change de couleur quand on passe dessus avec la souris
         */
        virtual void mouseMoved(sf::Event event);

        /*!
         *  \brief Ecoute d'un son
         *
         *  Un son est associé en fonction du bouton
         */
        virtual void mouseButtonPressed(sf::Event event);

        /*!
         *  \brief Changelent de thème
         *
         *  Possibilité dans le menu option de changer de thème
         */
        virtual void changeTheme( std::string theme );
};

#endif /* defined(__PuruPuruDigger__ButtonGraphic__) */
