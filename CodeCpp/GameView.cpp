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
    
    //Les messages anglais
    
    //Les messages espagnol
    
    //Les messages italien
    
    //Les message allemand
    
}

void
GameView::showScore( map< Language, map< Message, string > > LanguageMessage ) const {
    cout << LanguageMessage[my_language][level] << ( my_model->getScore() )->getCurrentStep() << endl;
    cout << LanguageMessage[my_language][global] << ( my_model->getScore() )->getGlobale() << endl;
    cout << LanguageMessage[my_language][current] << ( my_model->getScore() )->getCurrent() << endl;
    cout << LanguageMessage[my_language][goal] << ( my_model->getLevel() )->getGoal() << endl;

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