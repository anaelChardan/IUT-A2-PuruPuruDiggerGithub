/**
 * \file GameView.cpp
 * \brief Méthode liée à l'affichage de notre partie
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include "GameView.h"
#include "Constantes.h"
#include <fstream>
#include "IntDecFunctor.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include "Utils.h"
#include "Digger.h"
#include "Bomb.h"
#include "EmptyCell.h"
#include "ValueCell.h"
#include "GoldCell.h"
using namespace std;

GameView::GameView() {
    ///On set notre map pour l'affichage
    my_typeToString["Digger"] = colorMessage( "DD" , WHITE );
    my_typeToString["Bomb"] = colorMessage( "BB", RED);
    my_typeToString["EmptyCell"] = colorMessage( "  ", WHITE );
    my_typeToString["GoldCell"] = colorMessage( "*",  PINK );
    my_typeToString["ValueCell"] = colorMessage( " " ,  CYAN );
}

void
GameView::setModel(GameModel *model) {
    my_model = model;
}

void
GameView::showPresentation() const {
    cout << colorMessage( "+===========+                         +===========+                   ", CYAN ) << endl ;
    cout << colorMessage( "|           |      |           |      |           |      |           |", BLUE ) << endl ;
    cout << colorMessage( "|           |      |           |      |           |      |           |", CYAN ) << endl ;
    cout << colorMessage( "|           |      |           |      |           |      |           |", BLUE ) << endl ;
    cout << colorMessage( "+===========+      |           |      +===========+      |           |", CYAN ) << endl ;
    cout << colorMessage( "|                  |           |      |=                 |           |", BLUE ) << endl ;
    cout << colorMessage( "|                  |           |      |  =               |           |", CYAN ) << endl ;
    cout << colorMessage( "|                  |           |      |    =             |           |", BLUE ) << endl ;
    cout << colorMessage( "|                  |           |      |      =           |           |", CYAN ) << endl ;
    cout << colorMessage( "|                  |           |      |        =         |           |", BLUE )<< endl ;
    cout << colorMessage( "|                  |===========|      |          =       +===========+", CYAN ) << endl << endl << endl;


    cout << colorMessage( "                        PURU                DIGGER                    ", RED ) << endl << endl << endl;

    cout << colorMessage( "                  BY ANAEL CHARDAN    &     JEREMY DAMEY              ", GREEN ) << endl << endl << endl;


    cout << colorMessage( " 1 : START ", YELLOW ) << endl;
    cout << colorMessage( " 2 : BEST SCORE ", PINK ) << endl;
    cout << colorMessage( " 3 : QUIT  ", WHITE ) << endl << endl;

    cout << colorMessage( " CHOICE : ", YELLOW );
}

void
GameView::showLanguage() const {
    cout << endl << colorMessage( " 1 : Francais  2 : English  3 : Deutsch  4 : Espanol  5 : Italiano ", WHITE ) << endl << endl;
    cout << colorMessage( " CHOICE : ", YELLOW ) ;
}

void
GameView::showGrid() {
    ///Affichage de la première ligne
    for ( int z = 0; z < (COLONNE * 5 + 3); z++ ) {
        if ( z%5 == 1 )
            cout << colorMessage( "+", YELLOW );
        else
            cout << colorMessage( "-", YELLOW );
    }


    cout << endl;

    ///Affichage de la grille selon le getType bien utile
    for ( int i = 0; i < LIGNE; i++ ) {
        cout << colorMessage( " | ", YELLOW );
        for ( int j = 0; j < COLONNE; j++ ) {
            
            cout << my_typeToString.at(my_model->getLevel()->getGrid()[i][j]->getType());
            
            if ( (my_model->getLevel()->getGrid()[i][j])->getType()  == "GoldCell" ) {
                ///On copie le contenu du pointeur donné, qui ne renverra normalement pas nul
                ptr_goldCell = dynamic_cast<GoldCell*>(my_model->getLevel()->getGrid()[i][j]);
                cout << colorMessage( intToString( ptr_goldCell->getValue() ).c_str(), PINK);
            }
            else if ( (my_model->getLevel()->getGrid()[i][j])->getType()  == "ValueCell" ) {
                ///On copie le contenu du pointeur donné, qui ne renverra normalement pas nul
                ptr_valueCell = dynamic_cast<ValueCell*>(my_model->getLevel()->getGrid()[i][j]);
                cout << colorMessage( intToString( ptr_valueCell->getValue() ).c_str() ,  CYAN );
            }
            
            cout << colorMessage( " | ", YELLOW );
        }
        cout << endl;

        ///Affichage de la ligne en dessous de chaque case
        for ( int z = 0; z < (COLONNE * 5 + 3); z++ ) {
            if ( z%5 == 1 )
                cout << colorMessage( "+", YELLOW );
            else
                cout << colorMessage( "-", YELLOW );
        }
        cout << endl;
    }
    cout << endl;
}

void
GameView::showScore() {
    cout << my_messages[my_language][score] << " : " << endl << endl;
    cout << my_messages[my_language][level] << my_model->getScore()->getCurrentStep() << endl;
    cout << my_messages[my_language][global] << my_model->getScore()->getGlobale() << endl;
    cout << my_messages[my_language][current] << ( my_model->getScore() )->getCurrent() << endl;
    cout << my_messages[my_language][goal] << ( my_model->getLevel() )->getGoal() << endl;
    cout << my_messages[my_language][step] << ( my_model->getLevel() )->getCurrentMove() << endl;
    cout << my_messages[my_language][life] << " Digger : " <<  ( ( my_model->getLevel() )->getDigger() )->getLife() << endl;
    cout << my_messages[my_language][position] << " Digger :  [ " << my_model->getLevel()->getDigger()->getX() << " ] [ " << my_model->getLevel()->getDigger()->getY() << " ] " << endl << endl;

    cout << my_messages[my_language][ltime];  for ( int i = 0; i < my_model->getLevel()->leftTime(); i++ ) { cout << colorMessage(":", CYAN ); }
    cout << " " << my_model->getLevel()->leftTime() << endl << endl;

}

void
GameView::showInstruction( ) {
    cout << my_messages[my_language][move] << " : " << endl << endl;
    cout << " 7 : " << my_messages[my_language][nwest] << " 8 : " << my_messages[my_language][north] << " 9 : " << my_messages[my_language][neast] << endl;
    cout << " 4 : " << my_messages[my_language][west] <<          "               "                 << "  6 : " << my_messages[my_language][east] << endl;
    cout << " 1 : " << my_messages[my_language][swest] << "  2 : " << my_messages[my_language][south] << "  3 : " << my_messages[my_language][seast] << endl << endl;

    cout << " 5 : " << my_messages[my_language][stop] << endl << endl;

    cout << my_messages[my_language][choice];
}

void
GameView::showBestScore() const {
    ifstream scoreLect(FILEBESTSCORE.c_str(), ios::in );
    if ( scoreLect ) {
        string line;

        cout << endl << endl << " Best Scores " << endl << endl;

        while ( getline(scoreLect, line) ) {
            cout << line << endl;
        }

        scoreLect.close();

        cout << endl;
    } else {
        cerr << " Error when program is openning text file " << endl;
    }
}

void
GameView::enterScore( string nom ) const{
    ifstream scoreLect(FILEBESTSCORE.c_str(), ios::in );
    if ( scoreLect ) {
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


        //On ajoute notre joueur dans la map
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

void
GameView::treatGame() {
    bool isRunning = true;
    bool isPlaying = false;
    int menuChoice;
    int languechoice;
    int movechoice;
    string nom;
    while ( isRunning ) {
        showPresentation();
        cin >> menuChoice;
        while ( !(menuChoice>= 1 && menuChoice<=3 ) ) {
            showPresentation();
            cin >> menuChoice;
        }
        switch ( menuChoice ) {
            case 1 : isPlaying = true;
                break;
            case 2 : showBestScore();
                break;
            case 3 : isRunning = false;

        }

        if ( isPlaying ) {
            showLanguage();
            cin >> languechoice;
            while ( !(languechoice >= 1 && languechoice<=5 ) ) {
                showLanguage();
                cin>>languechoice;
            }
            cout << endl;
            switch ( languechoice ) {
                case 1 : my_language = francais;
                    break;
                case 2 : my_language = english;
                    break;
                case 3 : my_language = deutsch;
                    break;
                case 4 : my_language = espanol;
                    break;
                case 5 : my_language = italiano;
                    break;
            }
            my_model->reset();

            while (isPlaying) {
                showGrid();
                showScore();
                showInstruction();

                cin >> movechoice;

                //Pour ne pas rentrer des choses fausses
                while ( !(movechoice >= 0 && movechoice <= 9) ) {
                    showInstruction();
                    cin >>movechoice;
                }
                //On vérifie le temps, s'il est écoulé
                if ( my_model->getLevel()->timeIsUp() ) {
                    cout << endl << endl;
                    cout << my_messages[my_language][timeup] << endl;
                    //on fait perdre un niveau
                    my_model->getLevel()->lostLevel();
                    //On vérifie si ce n'est pas gameOver
                    if ( my_model->gameOver() ) {
                        cout << my_messages[my_language][loosegame] << endl;
                        isPlaying = false;
                    }

                } else {
                    if ( movechoice == 5 ) {
                        cout << my_messages[my_language][by] << endl;
                        isPlaying = false;
                    } else {
                        //On fait le mouvment
                        my_model->orderMovement(movechoice);
                        //Si le digger gagne un level
                        if ( my_model->getLevel()->win() ) {
                            my_model->getLevel()->resetWin();
                            cout << my_messages[my_language][winlevel] << endl ;

                        } else {
                            //Si la partie est fini
                            if ( my_model->gameOver() ) {
                                cout << my_messages[my_language][loosegame] << endl;
                                isPlaying = false;
                            } else {
                                //Si le digger perd un level
                                if ( my_model->getLevel()->lose() ) {
                                    my_model->getLevel()->resetLose();
                                    cout << my_messages[my_language][looselevel] << endl;
                                }
                            }
                        }
                    }
                }
            }

            //La partie est finie
            cout << my_messages[my_language][name];
            cin >> nom;
            enterScore(nom);
            showBestScore();
        }
    }

    cout << " GOOD BYE " << endl;
}
