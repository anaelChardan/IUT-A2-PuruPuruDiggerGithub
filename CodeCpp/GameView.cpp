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
using namespace std;
using namespace sf;

GameView::GameView( int w, int h, int bpp ) {
    my_w = w;
    my_h = h;
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
    cout << " 2 : MEILLEUR SCORE " << endl;
    cout << " 3 : QUIT  " << endl << endl;
    
    cout << " CHOICE : ";
}

void
GameView::initMessage(std::map< Language, std::vector<std::string> >LanguageMessage) {
    
    LanguageMessage[french].push_back("zizi");
}

void
GameView::showScore() const {
    
}

void
GameView::showInstruction() const {
    
}

void
GameView::showBestScore() const {
    ifstream scoreLect(FILEBESTSCORE.c_str(), ios::in );
    if ( scoreLect ) {
        string line;
        
        cout << endl;
        cout << endl;
        
        cout << " Voici les meilleurs scores " << endl << endl;
        
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