#ifndef __PuruPuruDigger__EventObservable__
#define __PuruPuruDigger__EventObservable__

/**
 * \file EventObservable.h
 * \brief Notre classe EventObservable
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include <string>
#include <set>
#include "EventObserver.h"

/*! \class EventObservable
 */

class EventObservable {

    private:
        std::set<EventObserver*> list_observers; /*!<  Liste des observers abonnées */

    public:
        /*!
         *  \brief Destructeur de la classe
         */
        virtual ~EventObservable();
    
        /*!
         *  \brief notification d'un événements aux abonnés
         */
        void notify( sf::Event event ) const;
    
        /*!
         *  \brief preDisplay
         */
        void preDisplay() const;
    
        /*!
         *  \brief postDiplay
         */
        void postDisplay() const;
    
        /*!
         *  \brief Changement de theme
         */
        void changeTheme( std::string theme ) const;
    
        /*!
         *  \brief Ajouté un abonne
         */
        virtual void addObserver( EventObserver* observer );
    
        /*!
         *  \brief Retirer un abonne
         */
        virtual void removeObserver( EventObserver* observer );
};

#endif /* defined(__PuruPuruDigger__EventObservable__) */
