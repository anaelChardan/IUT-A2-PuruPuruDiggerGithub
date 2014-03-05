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
        cerr << " Erreur d'ouverture de fichier " << endl;
    }
}