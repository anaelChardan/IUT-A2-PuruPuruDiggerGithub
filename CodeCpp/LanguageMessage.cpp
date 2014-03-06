#include "LanguageMessage.h"

using namespace std;

LanguageMessage::LanguageMessage() {
    //Les messages français
    my_languages[français][choice] = " Choix ";
    my_languages[français][move] = " Déplacement ";
    my_languages[français][north] = " Nord ";
    my_languages[français][south] = " Sud ";
    my_languages[français][west] = " Ouest ";
    my_languages[français][east] = " Est ";
    my_languages[français][nwest] = " Nord Ouest ";
    my_languages[français][neast] = " Nord Est ";
    my_languages[français][swest] = " Sud Ouest ";
    my_languages[français][seast] = " Sud Est ";
    my_languages[français][stop] = " Quitter ";
    my_languages[français][score] = " Score ";
    my_languages[français][level] = " Niveau ";
    my_languages[français][global] = " Score Global ";
    my_languages[français][current] = " Score Courrant ";
    my_languages[français][goal] = " Objectif ";
    my_languages[français][step] = " En cours ";
    my_languages[français][life] = " Vie ";
    my_languages[français][position] = " Position ";
    my_languages[français][winlevel] = " Vous gagnez un niveau " ;
    my_languages[français][looselevel] = " Vous perdez une vie, recommencez un niveau ";
    my_languages[français][loosegame] = " Vous avez perdu la partie ";
    my_languages[français][name] = " Entrez votre nom ";
    my_languages[français][by] = " Vous arrêtez la partie " ;

}

std::map<Message, std::string>&
LanguageMessage::operator[](Language langue) {
    return my_languages[langue];
}