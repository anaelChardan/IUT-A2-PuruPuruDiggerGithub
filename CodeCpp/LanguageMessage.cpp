/**
 * \file LanguageMessage.cpp
 * \brief Notre classe LanguageMessage
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include "LanguageMessage.h"

using namespace std;

LanguageMessage::LanguageMessage() {
    //Les messages français
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
    my_languages[francais][current] = " Score Courant ";
    my_languages[francais][goal] = " Objectif ";                    
    my_languages[francais][step] = " En cours ";
    my_languages[francais][life] = " Vie ";
    my_languages[francais][position] = " Position ";
    my_languages[francais][winlevel] = " Vous gagnez un niveau " ;
    my_languages[francais][looselevel] = " Vous perdez une vie, recommencez un niveau ";
    my_languages[francais][loosegame] = " Vous avez perdu la partie ";
    my_languages[francais][name] = " Entrez votre nom ";
    my_languages[francais][by] = " Vous arrêtez la partie " ;
    my_languages[francais][ltime] = " Temps restant ";
    my_languages[francais][timeup] = " Vous avez mis trop de temps, vous perdez le niveau ";
    

    //les messages anglais
    my_languages[english][choice] = " Choice ";
    my_languages[english][move] = " Move ";
    my_languages[english][north] = " North ";
    my_languages[english][south] = " South ";
    my_languages[english][west] = " West ";
    my_languages[english][east] = " East ";
    my_languages[english][nwest] = " North West ";
    my_languages[english][neast] = " North East ";
    my_languages[english][swest] = " South West ";
    my_languages[english][seast] = " South East ";
    my_languages[english][stop] = " Stop ";
    my_languages[english][score] = " Score ";
    my_languages[english][level] = " Level ";
    my_languages[english][global] = " Global Score ";
    my_languages[english][current] = " Current Score ";
    my_languages[english][goal] = " Goal ";
    my_languages[english][step] = " Step ";
    my_languages[english][life] = " Life ";
    my_languages[english][position] = " Position ";
    my_languages[english][winlevel] = " You win a level " ;
    my_languages[english][looselevel] = " You lost a life, try again ";
    my_languages[english][loosegame] = " You have lose a game ";
    my_languages[english][name] = " Enter your name ";
    my_languages[english][by] = " You stop the game " ;
    my_languages[english][ltime] = " Left Time  ";
    my_languages[english][timeup] = " You during too time, you left a level ";

    //les messages espagnol
    my_languages[espanol][choice] = " Eleccion ";
    my_languages[espanol][move] = " Desplazamiento ";
    my_languages[espanol][north] = " Norte ";
    my_languages[espanol][south] = " Sur ";
    my_languages[espanol][west] = " Oeste ";
    my_languages[espanol][east] = " Este ";
    my_languages[espanol][nwest] = " Norte Oeste ";
    my_languages[espanol][neast] = " Norte Este ";
    my_languages[espanol][swest] = " Sur Oeste ";
    my_languages[espanol][seast] = " Sur Este ";
    my_languages[espanol][stop] = " Dejar ";
    my_languages[espanol][score] = " Puntuacion ";
    my_languages[espanol][level] = " Nivel ";
    my_languages[espanol][global] = " Puntuacion Global ";
    my_languages[espanol][current] = " Calification actual ";
    my_languages[espanol][goal] = " Objetivo ";
    my_languages[espanol][step] = " En marcha ";
    my_languages[espanol][life] = " Vida ";
    my_languages[espanol][position] = " Posicion ";
    my_languages[espanol][winlevel] = " Que obtuvo un nivel " ;
    my_languages[espanol][looselevel] = " Usted gana un juego, iniciar un nivel ";
    my_languages[espanol][loosegame] = " Usted perdio el juego ";
    my_languages[espanol][name] = " Escriba su nombre ";
    my_languages[espanol][by] = " Dejas de parte " ;
    my_languages[espanol][ltime] = " Tiempo restante ";
    my_languages[espanol][timeup] = " Tomó demasiado tiempo, perder un nivel ";

    //les messages italien
    my_languages[italiano][choice] = " Scelta ";
    my_languages[italiano][move] = " Spostamento ";
    my_languages[italiano][north] = " Nord ";
    my_languages[italiano][south] = " Sud ";
    my_languages[italiano][west] = " Ovest ";
    my_languages[italiano][east] = " Oriente ";
    my_languages[italiano][nwest] = " Nord Ovest ";
    my_languages[italiano][neast] = " Nord Oriente ";
    my_languages[italiano][swest] = " Sud Ovest ";
    my_languages[italiano][seast] = " Sud Oriente ";
    my_languages[italiano][stop] = " Lasciare ";
    my_languages[italiano][score] = " Punteggio ";
    my_languages[italiano][level] = " Livello ";
    my_languages[italiano][global] = " Punteggio totale ";
    my_languages[italiano][current] = " Punteggio Courrant ";
    my_languages[italiano][goal] = " Obiettivo ";
    my_languages[italiano][step] = " In corso ";
    my_languages[italiano][life] = " Vita ";
    my_languages[italiano][position] = " Posizione ";
    my_languages[italiano][winlevel] = " Di livello " ;
    my_languages[italiano][looselevel] = " Si perde una vita, avviare un livello ";
    my_languages[italiano][loosegame] = " Hai perso la partita ";
    my_languages[italiano][name] = " Inserisci il tuo nome ";
    my_languages[italiano][by] = " Si smette di parte " ;
    my_languages[italiano][ltime] = " Tempo rimanente  ";
    my_languages[italiano][timeup] = " hai preso troppo a lungo, perdere un livello ";

    //les messages allemands
    my_languages[deutsch][choice] = " Walh ";
    my_languages[deutsch][move] = " Verdrangung ";
    my_languages[deutsch][north] = " Norden ";
    my_languages[deutsch][south] = " Suden ";
    my_languages[deutsch][west] = " Westen ";
    my_languages[deutsch][east] = " Osten ";
    my_languages[deutsch][nwest] = " Norden Westen ";
    my_languages[deutsch][neast] = " Norden Osten ";
    my_languages[deutsch][swest] = " Suden Westen ";
    my_languages[deutsch][seast] = " Suden Osten ";
    my_languages[deutsch][stop] = " Verlassen ";
    my_languages[deutsch][score] = " Partitur ";
    my_languages[deutsch][level] = " Ebene ";
    my_languages[deutsch][global] = " Gesamtnote ";
    my_languages[deutsch][current] = " Aktuelle punktzahl ";
    my_languages[deutsch][goal] = " Ziel ";
    my_languages[deutsch][step] = " Laufend ";
    my_languages[deutsch][life] = " Leben ";
    my_languages[deutsch][position] = " Position ";
    my_languages[deutsch][winlevel] = " Sie hat eine ebene gewonnen " ;
    my_languages[deutsch][looselevel] = " Sie verlieren ein leben, starten sie ine ebene ";
    my_languages[deutsch][loosegame] = " Sie verloren das spiel";
    my_languages[deutsch][name] = " Geben sie ihren namen ";
    my_languages[deutsch][by] = " Sie teil stoppen " ;
    my_languages[deutsch][ltime] = " Restzeit  ";
    my_languages[deutsch][timeup] = " Sie zu lange dauerte, verlieren eine Ebene ";

}

std::map<Message, std::string>&
LanguageMessage::operator[](Language langue) {
    return my_languages[langue];
}
