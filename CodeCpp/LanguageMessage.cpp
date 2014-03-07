#include "LanguageMessage.h"

using namespace std;

LanguageMessage::LanguageMessage() {
    //Les messages francais
    my_languages[francais][choice] = " Choix ";
    my_languages[francais][move] = " Déplacement ";
    my_languages[francais][north] = " Nord ";
    my_languages[francais][south] = " Sud ";
    my_languages[francais][west] = " Ouest ";
    my_languages[francais][east] = " Est ";
    my_languages[francais][nwest] = " Nord Ouest ";
    my_languages[francais][neast] = " Nord Est ";
    my_languages[francais][swest] = " Sud Ouest ";
    my_languages[francais][seast] = " Sud Est ";
    my_languages[francais][stop] = " Quitter ";
    my_languages[francais][score] = " Score ";
    my_languages[francais][level] = " Niveau ";
    my_languages[francais][global] = " Score Global ";
    my_languages[francais][current] = " Score Courrant ";
    my_languages[francais][goal] = " Objectif ";
    my_languages[francais][step] = " En cours ";
    my_languages[francais][life] = " Vie ";
    my_languages[francais][position] = " Position ";
    my_languages[francais][winlevel] = " Vous gagnez un niveau " ;
    my_languages[francais][looselevel] = " Vous perdez une vie, recommencez un niveau ";
    my_languages[francais][loosegame] = " Vous avez perdu la partie ";
    my_languages[francais][name] = " Entrez votre nom ";
    my_languages[francais][by] = " Vous arrêtez la partie " ;
    

}

std::map<Message, std::string>&
LanguageMessage::operator[](Language langue) {
    return my_languages[langue];
}
