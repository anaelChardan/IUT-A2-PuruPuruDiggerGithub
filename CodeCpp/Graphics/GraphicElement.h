#ifndef __PuruPuruDigger__GraphicElement__
#define __PuruPuruDigger__GraphicElement__

/**
 * \file GraphicElement.h
 * \brief Notre classe GraphicElement
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "../Observers/EventObserver.h"

/*! \class BacgroundGraphicElement
 *  \brief Classe pour l'affichage des element graphique
 */

class GraphicElement : public EventObserver {
    protected :
        sf::Sprite my_sprite; /*!< sprite choisi */

    public :
        /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe GraohicElement
         */
        virtual ~GraphicElement();

        virtual void setImageToSprite() = 0; // On associt l'image à son sprite

        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         *  Affichage de l'image choisie aux coordonnées choisies
         *
         * \param[in] int x
         * \param[in] int y
         * \param[in] int sf::RenderWindow * _window
         */
        virtual void setSpriteAndDraw( int x, int y, sf::RenderWindow * _window );

        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         *  Affichage de l'image choisie
         *
         * \param[in] sf::RenderWindow* _window
         */
        virtual void draw( sf::RenderWindow* _window ) const;

        /*!
         *  \brief Booleen qui permet de savoir si l'image est dans la zone
         *
         *  Savoir si l'image se trouve dans la zone voulue
         *
         * \param[in] int x
         * \param[in] int y
         */
        bool isInZone( int x, int y ) const;

        /*!
         *  \brief Affichage des coordonnees
         *
         *  Affichage des coordonnées en x de l'image
         */
        int getXPos() const;

        /*!
         *  \brief Affichage des coordonnees
         *
         *  Affichage des coordonnées en y de l'image
         */
        int getYPos() const;

        /*!
         *  \brief Affichage des coordonnees
         *
         *  Affichage des coordonnées en x de l'image
         */
        virtual void mouseMoved(sf::Event event);
        virtual void keyPressed(sf::Event event);
        virtual void textEntered(sf::Event event);
        virtual void mouseButtonPressed(sf::Event event);
        virtual void preDisplay();
        virtual void postDisplay();
        virtual void changeTheme( std::string theme );

};

#endif /* defined(__PuruPuruDigger__GraphicElement__) */