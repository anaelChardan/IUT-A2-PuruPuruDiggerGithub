//
//  LanguageMessage.h
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 06/03/2014.
//
//

#ifndef __PuruPuruDigger__LanguageMessage__
#define __PuruPuruDigger__LanguageMessage__

#include <iostream>
#include <map>
#include <string>
#include "Constantes.h"

class LanguageMessage {
    public :
        std::map< Language, std::map< Message, std::string> > my_languages;
        LanguageMessage();
        std::map<Message, std::string>& operator[]( Language language );
};

#endif /* defined(__PuruPuruDigger__LanguageMessage__) */
