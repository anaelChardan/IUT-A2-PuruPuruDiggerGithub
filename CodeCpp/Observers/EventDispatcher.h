#ifndef __PuruPuruDigger__EventDispatcher__
#define __PuruPuruDigger__EventDispatcher__

/**
 * \file EventDispatcher.h
 * \brief Notre classe EventDispatcher
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "EventObservable.h"
#include "../PuruContext.h"
#include "../Manager/SoundManager.h"


/*! 
 * \class EventDispatcher
 * \brief Classe décrivant l'eventDispatcher
 */
class EventDispatcher : public EventObservable {
    private:
        PuruContext *my_context; /*!<  Le context */
    public:
    
        /*!
         *  \brief Destructeur
         */
        virtual ~EventDispatcher();
    
        /*!
         *  \brief Ajouté un abonne
         */
        void addObserver( EventObserver* observer );
    
        /*!
         *  \brief Retirer un abonne
         */
        void removeObserver( EventObserver* observer );
    
        /*!
         *  \brief Constructeur
         */
        EventDispatcher( PuruContext *context );
};


#endif /* defined(__PuruPuruDigger__EventDispatcher__) */
