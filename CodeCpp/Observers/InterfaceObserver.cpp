/**
 * \file InterfaceObserver.cpp
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */


#include "InterfaceObserver.h"
#include "../Graphics/EnglishGraphic.h"
#include "../Graphics/FrenchGraphic.h"
#include "../Graphics/SpanishGraphic.h"
#include "../Graphics/DeutschGraphic.h"
#include "../Graphics/ItalianoGraphic.h"
#include "../Utils.h"
#include <sstream>
#include <fstream>
#include "../Graphics/DiggerGraphic.h"
#include "../Graphics/EmptyGraphic.h"
#include "../Graphics/ValueGraphic.h"
#include "../Graphics/BombGraphic.h"
#include "../Graphics/GoldGraphic.h"
#include "../IntDecFunctor.h"

using namespace std;
using namespace sf;

InterfaceObserver::InterfaceObserver(
                                     sf::RenderWindow* window,
                                     GameModel* model,
                                     ButtonGraphic *play,
                                     ButtonGraphic *setting,
                                     ButtonGraphic *best,
                                     ButtonGraphic *quit,
                                     GraphicMusic *music,
                                     GraphicSound *sound,
                                     std::map< Language, LanguageGraphic* >* languageToSprite,
                                     AnanasSprite *ananas,
                                     TeacherSprite *teacher,
                                     BackgroundGraphic *background
                                     ) :
                                        my_window( window ),
                                        my_model( model ),
                                        my_playButton(play),
                                        my_settingButton(setting),
                                        my_bestButton(best),
                                        my_quitButton(quit),
                                        my_musicIcon(music),
                                        my_soundIcon(sound),
                                        my_languageToSprite(languageToSprite),
                                        my_ananasSprite( ananas ),
                                        my_teacherSprite( teacher ),
                                        my_background(background)


    {

    my_fontScore = new Font();
    my_fontTitle = new Font();
    my_bestScoreFont = new Font();

    my_scoreString = new String();
    my_titleScoreString = new String();
    my_scoreNum = new String();
    my_titleString = new String();
    my_bestScoreString = new String();

    player = "";

    my_stringToSprite["Digger"]    = new DiggerGraphic();
    my_stringToSprite["EmptyCell"] = new EmptyGraphic();
    my_stringToSprite["GoldCell"]  = new GoldGraphic();
    my_stringToSprite["ValueCell"] = new ValueGraphic();
    my_stringToSprite["Bomb"]      = new BombGraphic();
        
    ///On initialise le vrai konamiCode
        
    my_trueKonamiCode[0] = my_trueKonamiCode[1] = 'U';
    my_trueKonamiCode[2] = my_trueKonamiCode[3] ='D';
    my_trueKonamiCode[4] = my_trueKonamiCode[6] ='L';
    my_trueKonamiCode[5] = my_trueKonamiCode[7] ='R';
    my_trueKonamiCode[8] = 'B';
    my_trueKonamiCode[9] = 'A';
        
        
    ///On initialise le cheater
    my_cheater = false;
        
    initKonamiCode();

}

//Constructeur
InterfaceObserver::~InterfaceObserver() {
    delete my_fontScore;
    delete my_fontTitle;
    delete my_bestScoreFont;

    delete my_scoreString;
    delete my_scoreNum;
    delete my_titleScoreString;
    delete my_bestScoreString;
    delete my_titleString;


    for ( map<string, CellBaseGraphic*>::const_iterator it = my_stringToSprite.begin() ; it!=my_stringToSprite.end(); ++it) {
        delete my_stringToSprite[ it->first ];
    }

}

void InterfaceObserver::initKonamiCode() {
    //On initialise notre konamiCode
    for ( unsigned int i = 0; i < 10; ++i ) {
        my_konamiCode[i] = 'Z';
    }
}

void InterfaceObserver::resetLanguageNorm() {
    for ( std::map<Language, LanguageGraphic*>::const_iterator it = my_languageToSprite->begin() ; it!=my_languageToSprite->end(); ++it) {
        (*my_languageToSprite)[ it->first ]->reset();
    }

}

void InterfaceObserver::newScreen() {
    my_window->Clear();
    my_background->draw(my_window);
    my_musicIcon->draw(my_window);
    my_soundIcon->draw(my_window);
}

void InterfaceObserver::showPresentation() {
    ///On affiche un écran "propre"
    newScreen();
    ///On affiche tout sce dont on a besoin
    my_titleString->SetColor(Color(255,255,255));
    my_titleString->SetSize(60);
    setTextAndDraw( my_titleString, "PURU PURU DIGGER ", ( WINDOWWITDH / 2 ), 100, true );
    my_playButton->setSpriteAndDraw(PLAYX, PLAYY, my_window, my_messages[my_context->getLanguage()][play]);
    my_settingButton->setSpriteAndDraw(OPTIONX, OPTIONY, my_window, my_messages[my_context->getLanguage()][setting]);
    my_bestButton->setSpriteAndDraw(BESTX, BESTY, my_window, my_messages[my_context->getLanguage()][best]);
    my_quitButton->setSpriteAndDraw(QUITX, QUITY, my_window, my_messages[my_context->getLanguage()][stop]);

}

void InterfaceObserver::showOption() {
    newScreen();
    //Le titre de la page
    setTextAndDraw( my_titleString, my_messages[my_context->getLanguage()][setting], ( WINDOWWITDH / 2 ), 10, true);
    //L'énoncé langue
    setTextAndDraw( my_scoreString, my_messages[my_context->getLanguage()][language], QUITONX + 50, CHOICELANGUEHIGH, false);
    setTextAndDraw( my_scoreString, my_messages[my_context->getLanguage()][actual], QUITONX + 50, MYLANGUEY, false );
    setTextAndDraw( my_scoreString, my_messages[my_context->getLanguage()][theme], QUITONX + 50, CHOICESPRITEY, false );
    showLanguage();

    //On place notre langue en cours
    (*my_languageToSprite)[my_context->getLanguage()]->setSpriteAndDraw(MYLANGUEX, MYLANGUEY, my_window);
    showSpriteChoice();
    my_quitButton->setSpriteAndDraw(QUITONX, QUITONY, my_window, my_messages[my_context->getLanguage()][stop]);

}

void InterfaceObserver::showLanguage() {
        (*my_languageToSprite)[english]->setSpriteAndDraw(ENGLISHX, CHOICELANGUEHIGH, my_window);
        (*my_languageToSprite)[francais]->setSpriteAndDraw(FRENCHX, CHOICELANGUEHIGH, my_window);
        (*my_languageToSprite)[espanol]->setSpriteAndDraw(SPANISHX, CHOICELANGUEHIGH, my_window);
        (*my_languageToSprite)[deutsch]->setSpriteAndDraw(DEUTSCHX, CHOICELANGUEHIGH, my_window);
        (*my_languageToSprite)[italiano]->setSpriteAndDraw(ITALIANOX, CHOICELANGUEHIGH, my_window);

}

void InterfaceObserver::showSpriteChoice() {
    my_ananasSprite->setSpriteAndDraw(CHOICEANANASX, CHOICESPRITEY, my_window);
    my_teacherSprite->setSpriteAndDraw(CHOICETEACHERX, CHOICESPRITEY, my_window);
}

void InterfaceObserver::showBestScore() {
    newScreen();

    ifstream scoreLect(FILEBESTSCORE.c_str(), ios::in );
    if ( scoreLect ) {
        string line;

        my_titleString->SetColor(Color(255,255,255));
        my_titleString->SetSize(60);

        //Le titre de la page
        setTextAndDraw( my_titleString, my_messages[my_context->getLanguage()][score], ( WINDOWWITDH / 2 ), 10, true ) ;
        int i = 200;
        //Le contenu de notre fichier
        while ( getline(scoreLect, line) ) {
            //Pour garantir la plus grand taille
            setTextAndDraw(my_bestScoreString, line, ( WINDOWWITDH / 2 ) , i, true );
            i += 100;
        }

        //On affiche le bouton quitter avec son string
        my_quitButton->setSpriteAndDraw(QUITONX, QUITONY, my_window, my_messages[my_context->getLanguage()][stop]);
        scoreLect.close();
    } else {
        cerr << " Error when program is openning text file " << endl;
    }
}

//Cette méthode sert à mettre un text à un string, le positionner, et le dessiner
void InterfaceObserver::setTextAndDraw( sf::String* s, string text, int x, int y, bool useSizeRectX ) {

    s->SetText(text);
    
    ///Si le texte est plus grand que la fenêtre, on le réduit
    if ( s->GetRect().GetWidth() > WINDOWWITDH ) {
        while ( s->GetRect().GetWidth() > WINDOWWITDH )
            s->SetSize( s->GetSize() - 5 );
    }
    
    ///Si l'on veut centrer
    if ( useSizeRectX )
        x -=  ( ( s->GetRect().GetWidth()  ) / 2 );

    s->SetPosition(x, y);
    my_window->Draw(*s);
}

void InterfaceObserver::showIsEnteringABestScore( string player ) {
    newScreen();
    setTextAndDraw( my_bestScoreString, my_messages[my_context->getLanguage()][by], ( WINDOWWITDH / 2 ), 10, true );
    setTextAndDraw( my_bestScoreString, my_messages[my_context->getLanguage()][name], ( WINDOWWITDH / 2 ), 100, true );
    setTextAndDraw( my_bestScoreString, player, ( WINDOWWITDH / 2 ) , WINDOWHEIGHT / 2, true ) ;
}

void InterfaceObserver::showGrid() {
    if ( my_context->isInAnimation() )
        toAnimate();
    else {
        for ( int i = 0; i < LIGNE ; i++ ) {
            for ( int j = 0; j < COLONNE; j++ ) {
                //On dessine le contenu de la case
                if ( my_model->getLevel()->getGrid()[i][j]->getType() == "GoldCell" ) {
                    ptr_goldCell = dynamic_cast<GoldCell*>(my_model->getLevel()->getGrid()[i][j]);
                    ptr_goldGraphic = dynamic_cast<GoldGraphic*>(my_stringToSprite["GoldCell"]);
                    ptr_goldGraphic->setSpriteAndDraw( convertIndiceXToPixel( j ), convertIndiceYToPixel( i ), my_window, intToString(ptr_goldCell->getValue()) );
                } else if ( my_model->getLevel()->getGrid()[i][j]->getType() == "ValueCell" ) {
                    ptr_valueCell = dynamic_cast<ValueCell*>(my_model->getLevel()->getGrid()[i][j]);
                    ptr_valueGraphic = dynamic_cast<ValueGraphic*>(my_stringToSprite["ValueCell"]);
                    ptr_valueGraphic->setSpriteAndDraw( convertIndiceXToPixel( j ), convertIndiceYToPixel( i ), my_window, intToString(ptr_valueCell->getValue()) );
                } else
                    my_stringToSprite[my_model->getLevel()->getGrid()[i][j]->getType()]->setSpriteAndDraw(convertIndiceXToPixel( j ), convertIndiceYToPixel( i ), my_window);
            }
        }
    }
}

void InterfaceObserver::showLoseLevel() {
    newScreen();
    my_titleString->SetSize(40);

    my_titleString->SetColor(Color(0,0,0));

    if ( !my_context->isTimeOver() && !my_context->isOver() ) {
        setTextAndDraw( my_titleString, my_messages[my_context->getLanguage()][looselevel],( WINDOWWITDH / 2 ), WINDOWHEIGHT / 2, true ) ;
    } else if ( my_context->isTimeOver() ) {
        setTextAndDraw( my_titleString, my_messages[my_context->getLanguage()][timeup], ( WINDOWWITDH / 2 ), WINDOWHEIGHT / 2, true );
    } else if ( my_context->isOver() ) {
        setTextAndDraw( my_titleString, my_messages[my_context->getLanguage()][loosegame], ( WINDOWWITDH / 2 ), WINDOWHEIGHT / 2, true );
    } else if ( my_context->isTimeOver() && my_context->isOver() ) {
        setTextAndDraw( my_titleString, my_messages[my_context->getLanguage()][loosegame], ( WINDOWWITDH / 2 ), WINDOWHEIGHT / 2, true );
    }
}

void InterfaceObserver::showWinLevel() {
    newScreen();

    my_titleString->SetSize(40);
    my_titleString->SetColor(Color(0,0,0));

    setTextAndDraw( my_titleString, my_messages[my_context->getLanguage()][winlevel], ( WINDOWWITDH / 2 ), WINDOWHEIGHT / 2, true ) ;
    
    if ( my_cheater ) {
        setTextAndDraw( my_titleString, my_messages[my_context->getLanguage()][cheater] , ( WINDOWWITDH / 2 ), 70 + WINDOWHEIGHT / 2, true ) ;
    }
}

void InterfaceObserver::showScore() {
    //Le titre
    setTextAndDraw( my_titleScoreString, my_messages[my_context->getLanguage()][score] + " : ", 100, 80, false);
    //Level et son num
    setTextAndDraw( my_scoreString, my_messages[my_context->getLanguage()][level] + " : ", 20, 140, false);
    setTextAndDraw( my_scoreNum, intToString(my_model->getScore()->getCurrentStep() ), my_scoreString->GetRect().GetWidth() + 40, 140, false );
    //Score Total
    setTextAndDraw( my_scoreString, my_messages[my_context->getLanguage()][global] + " : ", 20, 180, false);
    setTextAndDraw( my_scoreNum, intToString(my_model->getScore()->getGlobale() ), my_scoreString->GetRect().GetWidth() + 40, 180, false );
    //Score en cours
    setTextAndDraw( my_scoreString, my_messages[my_context->getLanguage()][current] + " : ", 20, 220, false);
    setTextAndDraw( my_scoreNum, intToString(my_model->getScore()->getCurrent() ), my_scoreString->GetRect().GetWidth() + 40, 220, false );
    //Objectif
    setTextAndDraw( my_scoreString, my_messages[my_context->getLanguage()][goal] + " : ", 20, 260, false);
    setTextAndDraw( my_scoreNum, intToString(my_model->getLevel()->getGoal() ), my_scoreString->GetRect().GetWidth() + 40, 260, false );
    //En cours
    setTextAndDraw( my_scoreString, my_messages[my_context->getLanguage()][step] + " : ", 20, 300, false);
    setTextAndDraw( my_scoreNum, intToString(my_model->getLevel()->getCurrentMove() ), my_scoreString->GetRect().GetWidth() + 40, 300 , false);
    //La vie
    setTextAndDraw( my_scoreString, my_messages[my_context->getLanguage()][life] + " : ", 20, 340, false);
    setTextAndDraw( my_scoreNum, intToString(my_model->getLevel()->getDigger()->getLife()), my_scoreString->GetRect().GetWidth() + 40, 340, false );

    //Le temps
    setTextAndDraw( my_scoreString, my_messages[my_context->getLanguage()][ltime] + " : ", 20, 380, false);
    setTextAndDraw( my_scoreNum, intToString( my_model->getLevel()->leftTime() ) , my_scoreString->GetRect().GetWidth() + 40, 380 , false);

    //La position
    setTextAndDraw( my_scoreString, my_messages[my_context->getLanguage()][position] + " : ", 20, 420, false);
    setTextAndDraw( my_scoreNum, "[ " + intToString( my_model->getLevel()->getDigger()->getX() ) + " ] [ " +  intToString( my_model->getLevel()->getDigger()->getY() )  + " ] " , my_scoreString->GetRect().GetWidth() + 40, 420, false );

}

void InterfaceObserver::showLevel() {
    
    if ( !my_context->isInAnimation() ) {
        newScreen();
        my_titleString->SetColor(Color(255,255,255));
        my_titleString->SetSize(60);
        setTextAndDraw( my_titleString, " PURU PURU DIGGER " , ( WINDOWWITDH / 2 ), 10, true ) ;
        //On dessine le score
        showScore();
        my_quitButton->setSpriteAndDraw(QUITONX, QUITONY, my_window, my_messages[my_context->getLanguage()][stop]);
    }
    //On dessine la grille
    showGrid();
}

void InterfaceObserver::enterScore() const{
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

        //On ajoute notre joueur à la map
        Scores[scorePlayer] = player;

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

void InterfaceObserver::toAnimate() {
    
    if ( ( convertIndiceXToPixel( my_model->getLevel()->getDigger()->getY() ) - my_stringToSprite["Digger"]->getXPos() ) == 0 && ( convertIndiceYToPixel( my_model->getLevel()->getDigger()->getX() ) - my_stringToSprite["Digger"]->getYPos() ) == 0 )
        my_context->setAnimation( false );
    
    else {
        
        //Premier temps, on place la case vide
        
        if (  my_model->getMovement() == South || my_model->getMovement() == East || my_model->getMovement() == SEast )
            my_stringToSprite["EmptyCell"]->setSpriteAndDraw( convertIndiceXToPixel( convertXPixel( my_stringToSprite["Digger"]->getXPos() ) ), convertIndiceYToPixel( convertYPixel( my_stringToSprite["Digger"]->getYPos() ) ), my_window );
        
        else if ( my_model->getMovement() == North || my_model->getMovement() == NEast )
            my_stringToSprite["EmptyCell"]->setSpriteAndDraw( convertIndiceXToPixel( convertXPixel( my_stringToSprite["Digger"]->getXPos() ) ), convertIndiceYToPixel( convertYPixel( my_stringToSprite["Digger"]->getYPos()  + CASEHEIGHT + 1 ) ), my_window );
        
        else if ( my_model->getMovement() == West || my_model->getMovement() == SWest )
            my_stringToSprite["EmptyCell"]->setSpriteAndDraw( convertIndiceXToPixel( convertXPixel( my_stringToSprite["Digger"]->getXPos() + CASEWITDH + 1 ) ), convertIndiceYToPixel( convertYPixel( my_stringToSprite["Digger"]->getYPos() ) ), my_window );
            
        else if ( my_model->getMovement() == Nwest )
            my_stringToSprite["EmptyCell"]->setSpriteAndDraw( convertIndiceXToPixel( convertXPixel(my_stringToSprite["Digger"]->getXPos() + CASEWITDH ) ), convertIndiceYToPixel( convertYPixel( my_stringToSprite["Digger"]->getYPos() + CASEHEIGHT) ), my_window );
        
        //Second temps, on place le digger
        switch ( my_model->getMovement() ) {
            case South :
                my_stringToSprite["Digger"]->setSpriteAndDraw( my_stringToSprite["Digger"]->getXPos(), my_stringToSprite["Digger"]->getYPos() + 2, my_window );
                break;
            
            case North :
                my_stringToSprite["Digger"]->setSpriteAndDraw( my_stringToSprite["Digger"]->getXPos(), my_stringToSprite["Digger"]->getYPos() - 2, my_window );
                break;
                
            case West :
                my_stringToSprite["Digger"]->setSpriteAndDraw( my_stringToSprite["Digger"]->getXPos() - 2, my_stringToSprite["Digger"]->getYPos(), my_window );
                break;
                
            case East :
                my_stringToSprite["Digger"]->setSpriteAndDraw( my_stringToSprite["Digger"]->getXPos() + 2, my_stringToSprite["Digger"]->getYPos(), my_window );
                break;
                
            case SEast :
                my_stringToSprite["Digger"]->setSpriteAndDraw( my_stringToSprite["Digger"]->getXPos() + 2, my_stringToSprite["Digger"]->getYPos() + 2, my_window );
                break;
                
            case SWest :
                my_stringToSprite["Digger"]->setSpriteAndDraw( my_stringToSprite["Digger"]->getXPos() - 2, my_stringToSprite["Digger"]->getYPos() + 2, my_window );
                break;
                
            case NEast :
                my_stringToSprite["Digger"]->setSpriteAndDraw( my_stringToSprite["Digger"]->getXPos() + 2, my_stringToSprite["Digger"]->getYPos() - 2, my_window );
                break;
                
            case Nwest :
                my_stringToSprite["Digger"]->setSpriteAndDraw( my_stringToSprite["Digger"]->getXPos() - 2, my_stringToSprite["Digger"]->getYPos() - 2, my_window);
                break;
                
            default :
                break;
        }
        
    }

}

bool InterfaceObserver::konamiCode( Event event ) {

    
    bool check;
    int lastElement = 0;
    
    while ( my_konamiCode[lastElement] != 'Z') {
        lastElement++;
    }
    
    switch (event.Key.Code ) {
        case Key::A :
            my_konamiCode[lastElement] = 'A';
            check = true;
            break;
            
        case Key::B :
            my_konamiCode[lastElement] = 'B';
            check = true;
            break;
            
        case Key::Up :
            my_konamiCode[lastElement] = 'U';
            check = true;
            break;
            
        case Key::Down :
            my_konamiCode[lastElement] = 'D';
            check = true;
            break;
            
        case Key::Left :
            my_konamiCode[lastElement] = 'L';
            check = true;
            break;
            
        case Key::Right :
            my_konamiCode[lastElement] = 'R';
            check = true;
            break;
            
        default:
            check = false;
            break;
    }
    
    if ( check ) {
        unsigned int z = 0;
        
        while ( check && z <= lastElement ) {
            if ( my_konamiCode [z] != my_trueKonamiCode[z] ) {
                check =false;
            } else
                z++;
        }
        
    }
    
    
    if ( check == false || lastElement == 9 ) {
        for ( unsigned int i = 0; i < 10; ++i )
            my_konamiCode[i] = 'Z';
    }
    
    return ( check && lastElement == 9 );
}

/** Events Subscriber */

void InterfaceObserver::mouseMoved(sf::Event event) { }

void InterfaceObserver::keyPressed(sf::Event event) {
    
    ///Si l'on joue, on peu faire le code konami
    if ( my_context->isPlaying() ) {
        if ( konamiCode( event ) ) {
            my_model->getLevel()->winLevel();
            my_cheater = true;
        }
        
        ///Si l'on est en train de taper notre nom
    } else if ( my_context->isEnterABestScore() ) {
        switch (event.Key.Code) {
            ///Entrer pour valider
            case Key::Return :
                if ( player.length() > 0 ) {
                    my_context->setEnterABestScore( false );
                    my_context->setViewingBestScore( true );
                    enterScore();
                    player = "";

                }
                break;
            
            ///BackSpace pour effacer des lettres
            case Key::Back :
                if ( player.length() > 0 )
                    player.erase( player.length() - 1, 1 );
                break;

            default :
                break;
        }
    }
}

void InterfaceObserver::textEntered(sf::Event event) {
    ///Si l'on est en train de rentrer notre nom
    if ( my_context->isEnterABestScore() ) {
        ///On bloque les caractères selon la table ascii
        if ( event.Text.Unicode >= 48 && event.Text.Unicode <127 && player.length() < 25 ) {
            ///On transtype et on ajoute au bout de notre nom de joueur
            player += static_cast<char>(event.Text.Unicode);
            SoundManager::getInstance()->touchPress();
        }
    }
}

void InterfaceObserver::mouseButtonPressed(sf::Event event) {
    if ( my_quitButton->isInZone( event.MouseButton.X, event.MouseButton.Y ) ) {
        initKonamiCode();
        SoundManager::getInstance()->stopMusic();
        my_context->setMusic( my_context->isEnableMusic() );
    }
}

void InterfaceObserver::preDisplay() {

    if ( my_context->isInPresentation() ) {
        showPresentation();

    } else if ( my_context->isChoosingOption() ) {
        showOption();

    } else if ( my_context->isViewingBestScore() ) {
        showBestScore();

    } else if ( my_context->isPlaying() ) {

        //On check le temps, et l'on peut perdre à cause de lui.
        if ( my_model->getLevel()->timeIsUp() ) {
            my_model->getLevel()->lostLevel();
            my_context->setTimeOver( true );
        }

        if ( my_model->gameOver() ) {
            if ( !my_context->isInBreak() ) {
                pause.Reset();
                SoundManager::getInstance()->gameOver();
            }
            my_context->setOver( true );
            my_context->setInBreak( true );
            my_context->setAnimation( false );

        }

        if ( my_model->getLevel()->lose() ) {
            if ( !my_context->isInBreak() ) {
                pause.Reset();
                SoundManager::getInstance()->youLoose();
            }
            showLoseLevel();
            my_context->setInBreak( true );
            my_context->setAnimation( false );

        } else if ( my_model->getLevel()->win()  ) {
            if ( !my_context->isInBreak() ) {
                pause.Reset();
                SoundManager::getInstance()->youWin();
            }
            showWinLevel();
            my_context->setInBreak( true );
            my_context->setAnimation( false );
        } else {
            showLevel();
        }
    } else if ( my_context->isEnterABestScore() ) {
        showIsEnteringABestScore( player );
    }

}

void InterfaceObserver::postDisplay() {
    if ( my_context->isInBreak() ) {

        if ( pause.GetElapsedTime() > 1.5 ) {

            my_model->getLevel()->resetLose();
            my_model->getLevel()->resetWin();
            my_cheater = false;
            my_model->getLevel()->resetTime();
            my_context->setInBreak( false );
            my_context->setTimeOver( false );
            pause.Reset();
            if ( my_model->gameOver() ) {
                initKonamiCode();
                my_context->setPlaying( false );
                my_context->setEnterABestScore( true );
                my_context->setOver( false );
                if ( my_context->isEnableMusic() ) {
                    SoundManager::getInstance()->pauseMusic();
                }
            }
        }
    }
}

void InterfaceObserver::changeTheme( std::string theme ) {
    std::string mypath;
#ifdef __linux__
    mypath = "Ressources/Font/" + theme;
#else
    mypath = theme;
#endif
    string fontScore = mypath + "_scoreFont.ttf";
    string fontTitle = mypath + "_titleFont.ttf";
    string bestScoreFont = mypath + "_BestFont.ttf";

    if ( theme == "teacher" ) {
        fontScore = mypath + "_arial.ttf";
        fontTitle = mypath + "_arial.ttf";
        bestScoreFont = mypath + "_arial.ttf";
    }

    if (!my_fontScore->LoadFromFile( fontScore.c_str() ) || !my_fontTitle->LoadFromFile( fontTitle.c_str() ) || !my_bestScoreFont->LoadFromFile( bestScoreFont.c_str() ) ) {
        cout << "Error when loading fonts" << endl;
    } else {
        for ( map<string, CellBaseGraphic*>::const_iterator it = my_stringToSprite.begin() ; it!=my_stringToSprite.end(); ++it) {
            my_stringToSprite[ it->first ]->changeTheme( theme );
        }

        my_titleScoreString->SetFont( *my_fontScore );
        my_scoreString->SetFont( *my_fontScore );
        my_scoreNum->SetFont( * my_fontScore );
        my_titleString->SetFont( *my_fontTitle );
        my_bestScoreString->SetFont( *my_bestScoreFont );

        my_titleScoreString->SetStyle(String::Underlined | String::Bold | String::Italic );
        my_scoreString->SetStyle(String::Underlined);

        my_scoreString->SetSize(30);
        my_titleScoreString->SetSize(40);
        my_bestScoreString->SetSize(28);

        if ( theme == "ananas" ) {

            my_titleScoreString->SetColor(Color(50,50,150));
            my_scoreString->SetColor(Color(251,210,98));
            my_scoreNum->SetColor(Color(255,100,100));
            my_bestScoreString->SetColor(Color(49,140,231));
        } else {
            my_titleScoreString->SetColor(Color(255,255,255));
            my_scoreString->SetColor(Color(255, 255,255));
            my_scoreNum->SetColor(Color(255,255,255));
            my_bestScoreString->SetColor(Color(255,255,255));
        }
    }
}


