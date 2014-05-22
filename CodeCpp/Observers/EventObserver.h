#ifndef __PuruPuruDigger__EventObserver__
#define __PuruPuruDigger__EventObserver__

/**
 * \file EventObserver.h
 * \brief Notre classe abstraite EventObserver
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <string>
#include <set>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../PuruContext.h"
#include "../Manager/SoundManager.h"


/*! \class EventObserver
 *  \brief Classe abstraite pour décrire un observer
 */
class EventObserver {
    protected:
        PuruContext *my_context; /*!<  Le context de notre jeu */

    public:
        /*!
         *  \brief Destructeur de la classe
         */
        virtual ~EventObserver();
    
        /*!
         *  \brief Réaction de l'observer selon l'événement mouseMoved
         *  param[in] un événement
         */
        virtual void mouseMoved(sf::Event event) = 0;
    
        /*!
         *  \brief Réaction de l'observer selon l'événement keyPressed
         *  param[in] un événement
         */
        virtual void keyPressed(sf::Event event) = 0;
    
        /*!
         *  \brief Réaction de l'observer selon l'événement textEntered
         *  param[in] un événement
         */
        virtual void textEntered(sf::Event event) = 0;
    
        /*!
         *  \brief Réaction de l'observer selon l'événement boutonPressed
         *  param[in] un événement
         */
        virtual void mouseButtonPressed(sf::Event event) = 0;

        /*!
         *  \brief predDisplay
         */
        virtual void preDisplay() = 0;
    
        /*!
         *  \brief postDisplay
         */
        virtual void postDisplay() = 0;
    
        /*!
         *  \brief changement de theme
         */
        virtual void changeTheme( std::string theme ) = 0;
    
        /*!
         *  \brief injection de dépendance context
         */
        void setContext( PuruContext *context );

};


#endif /* defined(__PuruPuruDigger__EventObserver__) */
