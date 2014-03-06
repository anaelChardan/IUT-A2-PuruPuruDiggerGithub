//
//  GameView.cpp
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 26/02/2014.
//
//

#include "GameView.h"
#include "Constantes.h"
#include <fstream>
#include "IntDecFunctor.h"
#include <string>
using namespace std;
using namespace sf;

GameView::GameView() {
    initMessage( LanguageMessage );
}

void
GameView::showPresentation() const {
    cout << " -----------                           -----------                    " << endl ;
    cout << "|           |      |           |      |           |      |           |" << endl ;
    cout << "|           |      |           |      |           |      |           |" << endl ;
    cout << "|           |      |           |      |           |      |           |" << endl ;
    cout << "|-----------       |           |      |-----------       |           |" << endl ;
    cout << "|                  |           |      |-                 |           |" << endl ;
    cout << "|                  |           |      |  -               |           |" << endl ;
    cout << "|                  |           |      |    -             |           |" << endl ;
    cout << "|                  |           |      |      -           |           |" << endl ;
    cout << "|                  |           |      |        -         |           |" << endl ;
    cout << "|                  |___________|      |          -       |___________|" << endl << endl << endl;


    cout << "                        PURU                DIGGER                    " << endl << endl << endl;

    cout << "                  BY ANAEL CHARDAN    &     JEREMY DAMEY              " << endl << endl << endl;


    cout << " 1 : START " << endl;
    cout << " 2 : BEST SCORE " << endl;
    cout << " 3 : QUIT  " << endl << endl;

    cout << " CHOICE : ";
}

void
GameView::initMessage(map< Language, map< Message, string > > &LanguageMessage) {
    //Les messages français
    LanguageMessage[français][move] = " Déplacement ";
    LanguageMessage[français][north] = " Nord ";
    LanguageMessage[français][south] = " Sud ";
    LanguageMessage[français][west] = " Ouest ";
    LanguageMessage[français][east] = " Est ";
    LanguageMessage[français][nwest] = " Nord Ouest ";
    LanguageMessage[français][neast] = " Nord Est ";
    LanguageMessage[français][swest] = " Sud Ouest ";
    LanguageMessage[français][seast] = " Sud Est ";
    LanguageMessage[français][looselevel] = " Vous perdez une vie, recommencez un niveau ";
    LanguageMessage[français][win] = " Vous gagnez un niveau " ;
    LanguageMessage[français][loosegame] = " Vous avez perdu la partie :";
    LanguageMessage[français][global] = " Score Global ";
    LanguageMessage[français][current] = " Score Courrant ";
    LanguageMessage[français][step] = " En cours ";
    LanguageMessage[français][goal] = " Objectif ";
    LanguageMessage[français][level] = " Niveau ";
    LanguageMessage[français][quit] = " Quitter ";
    LanguageMessage[français][life] = "Vie ";

    //Les messages anglais

    LanguageMessage[english][move] = " Déplacement ";
    LanguageMessage[english][north] = " Nord ";
    LanguageMessage[english][south] = " Sud ";
    LanguageMessage[english][west] = " Ouest ";
    LanguageMessage[english][east] = " Est ";
    LanguageMessage[english][nwest] = " Nord Ouest ";
    LanguageMessage[english][neast] = " Nord Est ";
    LanguageMessage[english][swest] = " Sud Ouest ";
    LanguageMessage[english][seast] = " Sud Est ";
    LanguageMessage[english][looselevel] = " Vous perdez une vie, recommencez un niveau ";
    LanguageMessage[english][win] = " Vous gagnez un niveau " ;
    LanguageMessage[english][loosegame] = " Vous avez perdu la partie :";
    LanguageMessage[english][global] = " Score Global ";
    LanguageMessage[english][current] = " Score Courrant ";
    LanguageMessage[english][step] = " En cours ";
    LanguageMessage[english][goal] = " Objectif ";
    LanguageMessage[english][level] = " Niveau ";
    LanguageMessage[english][quit] = " Quitter ";
    LanguageMessage[english][life] = "Vie ";

    //Les messages espagnol
    LanguageMessage[español][move] = " Déplacement ";
    LanguageMessage[español][north] = " Nord ";
    LanguageMessage[español][south] = " Sud ";
    LanguageMessage[español][west] = " Ouest ";
    LanguageMessage[español][east] = " Est ";
    LanguageMessage[español][nwest] = " Nord Ouest ";
    LanguageMessage[español][neast] = " Nord Est ";
    LanguageMessage[español][swest] = " Sud Ouest ";
    LanguageMessage[español][seast] = " Sud Est ";
    LanguageMessage[español][looselevel] = " Vous perdez une vie, recommencez un niveau ";
    LanguageMessage[español][win] = " Vous gagnez un niveau " ;
    LanguageMessage[español][loosegame] = " Vous avez perdu la partie :";
    LanguageMessage[español][global] = " Score Global ";
    LanguageMessage[español][current] = " Score Courrant ";
    LanguageMessage[español][step] = " En cours ";
    LanguageMessage[español][goal] = " Objectif ";
    LanguageMessage[español][level] = " Niveau ";
    LanguageMessage[español][quit] = " Quitter ";
    LanguageMessage[español][life] = "Vie ";

    //Les messages italien
    LanguageMessage[italiano][move] = " Déplacement ";
    LanguageMessage[italiano][north] = " Nord ";
    LanguageMessage[italiano][south] = " Sud ";
    LanguageMessage[italiano][west] = " Ouest ";
    LanguageMessage[italiano][east] = " Est ";
    LanguageMessage[italiano][nwest] = " Nord Ouest ";
    LanguageMessage[italiano][neast] = " Nord Est ";
    LanguageMessage[italiano][swest] = " Sud Ouest ";
    LanguageMessage[italiano][seast] = " Sud Est ";
    LanguageMessage[italiano][looselevel] = " Vous perdez une vie, recommencez un niveau ";
    LanguageMessage[italiano][win] = " Vous gagnez un niveau " ;
    LanguageMessage[italiano][loosegame] = " Vous avez perdu la partie :";
    LanguageMessage[italiano][global] = " Score Global ";
    LanguageMessage[italiano][current] = " Score Courrant ";
    LanguageMessage[italiano][step] = " En cours ";
    LanguageMessage[italiano][goal] = " Objectif ";
    LanguageMessage[italiano][level] = " Niveau ";
    LanguageMessage[italiano][quit] = " Quitter ";
    LanguageMessage[italiano][life] = "Vie ";

    //Les message allemand
    LanguageMessage[deutsch][move] = " Déplacement ";
    LanguageMessage[deutsch][north] = " Nord ";
    LanguageMessage[deutsch][south] = " Sud ";
    LanguageMessage[deutsch][west] = " Ouest ";
    LanguageMessage[deutsch][east] = " Est ";
    LanguageMessage[deutsch][nwest] = " Nord Ouest ";
    LanguageMessage[deutsch][neast] = " Nord Est ";
    LanguageMessage[deutsch][swest] = " Sud Ouest ";
    LanguageMessage[deutsch][seast] = " Sud Est ";
    LanguageMessage[deutsch][looselevel] = " Vous perdez une vie, recommencez un niveau ";
    LanguageMessage[deutsch][win] = " Vous gagnez un niveau " ;
    LanguageMessage[deutsch][loosegame] = " Vous avez perdu la partie :";
    LanguageMessage[deutsch][global] = " Score Global ";
    LanguageMessage[deutsch][current] = " Score Courrant ";
    LanguageMessage[deutsch][step] = " En cours ";
    LanguageMessage[deutsch][goal] = " Objectif ";
    LanguageMessage[deutsch][level] = " Niveau ";
    LanguageMessage[deutsch][quit] = " Quitter ";
    LanguageMessage[deutsch][life] = "Vie ";
}

void
GameView::showGrid() const {
    for ( unsigned long z = 0; z < (COLONNE * 5 + 3); z++ )
        cout << "-";
    cout << endl;
    
    for ( unsigned long i = 0; i < LIGNE; i++ ) {
        cout << " | ";
        for ( unsigned long j = 0; j < COLONNE; j++ ) {
            cout << my_model->getLevel()->getGrid()[i][j] << " | ";
        }
        cout << endl;
        for ( unsigned long z = 0; z < (COLONNE * 5 + 3); z++ )
            cout << "-";
        cout << endl;
    }
    cout << endl;
}

void
GameView::showScore( map< Language, map< Message, string > > LanguageMessage ) const {
    cout << LanguageMessage[my_language][level] << ( my_model->getScore() )->getCurrentStep() << endl;
    cout << LanguageMessage[my_language][global] << ( my_model->getScore() )->getGlobale() << endl;
    cout << LanguageMessage[my_language][current] << ( my_model->getScore() )->getCurrent() << endl;
    cout << LanguageMessage[my_language][goal] << ( my_model->getLevel() )->getGoal() << endl;
    cout << LanguageMessage[my_language][step] << ( my_model->getLevel() )->getCurrentMove() << endl;
    cout << LanguageMessage[my_language][life] << " Digger : " <<  ( ( my_model->getLevel() )->getDigger() )->getLife() << endl;
}

void
GameView::showInstruction( map< Language, map< Message, string > > LanguageMessage ) const {
    cout << LanguageMessage[my_language][move] << " : " << endl << endl;
    cout << " 7 : " << LanguageMessage[my_language][nwest] << " 8 : " << LanguageMessage[my_language][north] << " 9 : " << LanguageMessage[my_language][neast] << endl;
    cout << " 4 : " << LanguageMessage[my_language][west] <<          "                      "               << " 6 : " << LanguageMessage[my_language][east] << endl;
    cout << " 1 : " << LanguageMessage[my_language][swest] << " 2 : " << LanguageMessage[my_language][south] << " 3 : " << LanguageMessage[my_language][seast] << endl << endl;

    cout << " 5 : " << LanguageMessage[my_language][quit] << endl;
}

void
GameView::showBestScore() const {
    ifstream scoreLect(FILEBESTSCORE.c_str(), ios::in );
    if ( scoreLect ) {
        string line;

        cout << endl;
        cout << endl;

        cout << " Best Scores " << endl << endl;

        while ( getline(scoreLect, line) ) {
            cout << line << endl;
        }

        scoreLect.close();
    } else {
        cerr << " Error when program is openning text file " << endl;
    }
}

void
GameView::enterScore( string nom ) const{
    ifstream scoreLect(FILEBESTSCORE.c_str(), ios::in );
    if ( scoreLect ) {
        //scoreLect >> "TEST";
        string line;
        int scoreligne;
        string nomligne;
        map< int, string, DecFunctor> Scores;
        int scorePlayer = ( my_model->getScore() )->getGlobale() ;

        while ( !scoreLect.eof() ) {
            //On lit le score et on le stocke dans une map
            scoreLect >> scoreligne >> nomligne;
            Scores[scoreligne] = nomligne.c_str();
        }


        //On ajoute notre joueur à la map
        Scores[scorePlayer] = nom;

        scoreLect.close();

        ofstream scoreEcr(FILEBESTSCORE.c_str(), ios::out | ios::trunc );

        map< int, string>::iterator i;
        if ( Scores.size() < 5 ) {
            i = Scores.end();
        } else {
            i = Scores.begin();
            for ( int cpt = 0 ; cpt < 5; cpt ++ ) ++i;
        }

        for ( map< int, string >::const_iterator it = Scores.begin() ; it!=i ; ++it) {
            scoreEcr << it->first;
            scoreEcr <<  " ";
            scoreEcr <<  it->second;
            scoreEcr << endl;
        }

        scoreEcr.close();
    } else {
        cerr << " Error when program is openning text file " << endl;
    }
}
