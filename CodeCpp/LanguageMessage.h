#ifndef __PuruPuruDigger__LanguageMessage__
#define __PuruPuruDigger__LanguageMessage__

/**
 * \file LanguageMessage.h
 * \brief Notre classe LanguageMessage
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include <map>
#include <string>
#include "Constantes.h"

/*! \class LanguageMessage
 *  \brief Classe pour enregistrer notre multilangue */
class LanguageMessage {
    public :
        std::map< Language, std::map< Message, std::string> > my_languages; /*!<  Notre map */
    
        /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe LanguageMessage
         */
        LanguageMessage();
    
        /*!
         *  \brief Surcharge de l'opérateur crochet
         *
         */
        std::map<Message, std::string>& operator[]( Language language );
};

#endif /* defined(__PuruPuruDigger__LanguageMessage__) */
