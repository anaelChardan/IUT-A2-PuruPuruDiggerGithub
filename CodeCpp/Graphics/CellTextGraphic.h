#ifndef __PuruPuruDigger__CellTextGraphic__
#define __PuruPuruDigger__CellTextGraphic__

/**
 * \file CellTextGraphic.h
 * \brief Notre classe CellTextGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "CellBaseGraphic.h"

/*! \class CellTextGraphic
 *  \brief Classe pour l'affichage du texte
 */

class CellTextGraphic : public CellBaseGraphic {
    protected :
        static sf::Font my_font; /*!< police d'écriture */
        sf::String my_string; /*!< chaine de caractère */

    public :
        /*!
         *  \brief Affiche le texte demander
         *
         *  Affiche le texte demander
         *
         * \param[in] int x
         * \param[in] int y
         * \param[in] sf::RenderWindow * _window
         * \param[in] std::string _string
         */
        virtual void setSpriteAndDraw( int x, int y, sf::RenderWindow * _window, std::string _string );

        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         *  Affichage de l'image choisi
         */
        virtual void setImageToSprite();

        /*!
         *  \brief Configurer le sprite par rapport à l'image
         *
         *  Affichage du thème choisi
         *
         * \param[in] std::string theme
         */
        virtual void changeTheme( std::string theme );
};

#endif /* defined(__PuruPuruDigger__CellTextGraphic__) */
