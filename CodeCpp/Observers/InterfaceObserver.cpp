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

//Constructeur
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
                                     TeacherSprite *teacher
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
                                        my_teacherSprite( teacher )


    {
    
    my_fontScore = new Font();
    my_fontTitle = new Font();
    my_bestScoreFont = new Font();
    
    my_scoreString = new String();
    my_titleScoreString = new String();
    my_scoreNum = new String();
    my_titleString = new String();
    my_bestScoreString = new String();
    
    my_textBuffer = new SoundBuffer();
    my_textSound = new Sound();
    my_gameOverBuffer = new SoundBuffer();
    my_gameOverSound = new Sound();
    my_clickableBuffer = new SoundBuffer();
    my_clickableSoundCell = new Sound();
    my_isNotClickableBuffer = new SoundBuffer();
    my_isNotClickableSound = new Sound();
    my_loseLevelBuffer= new SoundBuffer();
    my_loseLevelSound = new Sound();

    player = "";

    my_stringToSprite["Digger"]    = new DiggerGraphic();
    my_stringToSprite["EmptyCell"] = new EmptyGraphic();
    my_stringToSprite["GoldCell"]  = new GoldGraphic();
    my_stringToSprite["ValueCell"] = new ValueGraphic();
    my_stringToSprite["Bomb"]      = new BombGraphic();
    
    
    //Chargement des images selon le mode
    setAnanasMode();
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

    for ( std::map<Language, LanguageGraphic*>::const_iterator it = my_languageToSprite->begin() ; it!=my_languageToSprite->end(); ++it) {
        delete (*my_languageToSprite)[ it->first ];
    }
    
    for ( map<string, CellBaseGraphic*>::const_iterator it = my_stringToSprite.begin() ; it!=my_stringToSprite.end(); ++it) {
        delete my_stringToSprite[ it->first ];
    }
    
}


void InterfaceObserver::resetLanguageNorm() {
    for ( std::map<Language, LanguageGraphic*>::const_iterator it = my_languageToSprite->begin() ; it!=my_languageToSprite->end(); ++it) {
        (*my_languageToSprite)[ it->first ]->reset();
    }
    
}


void InterfaceObserver::setAnanasMode() {

    if (!my_fontScore->LoadFromFile("scoreFont.ttf") || !my_fontTitle->LoadFromFile("titleFont.ttf") || !my_bestScoreFont->LoadFromFile("BestFont.ttf") || !my_textBuffer->LoadFromFile("soundEnterText.wav") || !my_gameOverBuffer->LoadFromFile("soundGameOver.wav") || !my_clickableBuffer->LoadFromFile("soundIsClickable.wav") || !my_isNotClickableBuffer->LoadFromFile("soundIsNotClickable.wav") || !my_loseLevelBuffer->LoadFromFile("soundLoseLevel.wav") ) {
        cout << "Error when loading font" << endl;
    } else {
        
        //Les affichages de valeurs seront toujours identiques, du coup on les set dir
        my_playButton->setAnanasMode();
        my_settingButton->setAnanasMode();
        my_bestButton->setAnanasMode();
        my_quitButton->setAnanasMode();
        
        for ( std::map<Language, LanguageGraphic*>::const_iterator it = my_languageToSprite->begin() ; it!=my_languageToSprite->end(); ++it) {
            (*my_languageToSprite)[ it->first ]->setAnanasMode();
        }
        
        for ( map<string, CellBaseGraphic*>::const_iterator it = my_stringToSprite.begin() ; it!=my_stringToSprite.end(); ++it) {
            my_stringToSprite[ it->first ]->setAnanasMode();
        }
        
        my_titleScoreString->SetFont( *my_fontScore );
        my_titleScoreString->SetSize(40);
        my_titleScoreString->SetColor(Color(50,50,150));
        my_titleScoreString->SetStyle(String::Underlined | String::Bold | String::Italic );
        
        my_scoreString->SetFont( *my_fontScore );
        my_scoreString->SetSize(30);
        my_scoreString->SetColor(Color(251,210,98));
        my_scoreString->SetStyle(String::Underlined);
        
        my_scoreNum->SetFont( * my_fontScore );
        my_scoreNum->SetColor(Color(255,100,100));
        
        my_titleString->SetFont( *my_fontTitle );
        
        my_bestScoreString->SetFont( *my_bestScoreFont );
        my_bestScoreString->SetColor(Color(49,140,231));
        my_bestScoreString->SetSize(30);
        
        
        my_musicIcon->setAnanasMode();
        my_soundIcon->setAnanasMode();
        my_ananasSprite->setAnanasMode();
        my_teacherSprite->setAnanasMode();
        my_background.setAnanasMode();
    
        
        //Pour la musique
        my_textSound->SetBuffer(*my_textBuffer);
        my_gameOverSound->SetBuffer(*my_gameOverBuffer);
        my_clickableSoundCell->SetBuffer(*my_clickableBuffer);
        my_isNotClickableSound->SetBuffer(*my_isNotClickableBuffer);
        my_loseLevelSound->SetBuffer(*my_loseLevelBuffer);
    }

    
}

void InterfaceObserver::setTeacherMode() {

    if ( !my_fontScore->LoadFromFile("../Ressources/Font/arial.ttf") || !my_bestScoreFont->LoadFromFile("../Ressources/Font/arial.ttf") || !my_fontTitle->LoadFromFile("../Ressources/Font/arial.ttf") || !my_textBuffer->LoadFromFile("../Ressources/Music/soundEnterText.wav") || !my_gameOverBuffer->LoadFromFile("../Ressources/Music/soundGameOver.wav") || !my_clickableBuffer->LoadFromFile("../Ressources/Music/soundIsClickable.wav") || !my_isNotClickableBuffer->LoadFromFile("../Ressources/Music/soundIsNotClickable.wav") || !my_loseLevelBuffer->LoadFromFile("../Ressources/Music/soundLoseLevel.wav")) {
        cout << "Error when loading font" << endl;
    } else {
        
        my_playButton->setTeacherMode();
        my_settingButton->setTeacherMode();
        my_bestButton->setTeacherMode();
        my_quitButton->setTeacherMode();
        
        for ( std::map<Language, LanguageGraphic*>::const_iterator it = my_languageToSprite->begin() ; it!=my_languageToSprite->end(); ++it) {
            (*my_languageToSprite)[ it->first ]->setTeacherMode();
        }
        
        for ( map<string, CellBaseGraphic*>::const_iterator it = my_stringToSprite.begin() ; it!=my_stringToSprite.end(); ++it) {
            my_stringToSprite[ (*it).first ]->setTeacherMode();
        }
        
        //Le string pour la page de présentation
        my_titleString->SetFont( *my_fontTitle );
        
        //Le string pour le titre des scores
        my_titleScoreString->SetFont( *my_fontScore );
        my_titleScoreString->SetSize(40);
        my_titleScoreString->SetStyle(String::Underlined | String::Bold | String::Italic );
        my_titleScoreString->SetColor(Color(255,255,255));
        
        //Le string pour l'énoncé des scores de la classe language message
        my_scoreString->SetSize(30);
        my_scoreString->SetFont( *my_fontScore );
        my_scoreString->SetColor(Color(255, 255,255));
        my_scoreString->SetStyle(String::Underlined);
        
        //Le string pour le intToString
        my_scoreNum->SetFont( * my_fontScore );
        my_scoreNum->SetColor(Color(255,255,255));
        
        my_bestScoreString->SetFont( *my_bestScoreFont);
        my_bestScoreString->SetColor(Color(255,255,255));
        my_bestScoreString->SetSize(25);
        
        
        my_musicIcon->setTeacherMode();
        my_soundIcon->setTeacherMode();
        my_ananasSprite->setTeacherMode();
        my_teacherSprite->setTeacherMode();
        my_background.setTeacherMode();
        

        my_textSound->SetBuffer(*my_textBuffer);
        my_gameOverSound->SetBuffer(*my_gameOverBuffer);
        my_clickableSoundCell->SetBuffer(*my_clickableBuffer);
        my_isNotClickableSound->SetBuffer(*my_isNotClickableBuffer);
        my_loseLevelSound->SetBuffer(*my_loseLevelBuffer);
        
                
        
    }
}


void InterfaceObserver::newScreen() {
    my_window->Clear();
    my_background.draw(my_window);
    my_musicIcon->draw(my_window);
    my_soundIcon->draw(my_window);
}

void InterfaceObserver::showPresentation() {
    newScreen();
    
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
    
    if ( s->GetRect().GetWidth() > WINDOWWITDH ) {
        while ( s->GetRect().GetWidth() > WINDOWWITDH )
            s->SetSize( s->GetSize() - 5 );
    }
    
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
        if ( my_model->getMovement() == South ) {
            my_stringToSprite["EmptyCell"]->setSpriteAndDraw( convertIndiceXToPixel( convertXPixel( my_stringToSprite["Digger"]->getXPos() ) ), convertIndiceYToPixel( convertYPixel( my_stringToSprite["Digger"]->getYPos() ) ), my_window );
            
            my_stringToSprite["Digger"]->setSpriteAndDraw( my_stringToSprite["Digger"]->getXPos(), my_stringToSprite["Digger"]->getYPos() + 2, my_window );
            
            
        } else if ( my_model->getMovement() == North ) {
            my_stringToSprite["EmptyCell"]->setSpriteAndDraw( convertIndiceXToPixel( convertXPixel( my_stringToSprite["Digger"]->getXPos() ) ), convertIndiceYToPixel( convertYPixel( my_stringToSprite["Digger"]->getYPos()  + CASEHEIGHT ) ), my_window );
            
            my_stringToSprite["Digger"]->setSpriteAndDraw( my_stringToSprite["Digger"]->getXPos(), my_stringToSprite["Digger"]->getYPos() - 2, my_window );
            
        } else if ( my_model->getMovement() == West ) {
            my_stringToSprite["EmptyCell"]->setSpriteAndDraw( convertIndiceXToPixel( convertXPixel( my_stringToSprite["Digger"]->getXPos() + CASEWITDH) ), convertIndiceYToPixel( convertYPixel( my_stringToSprite["Digger"]->getYPos() ) ), my_window );
            
            my_stringToSprite["Digger"]->setSpriteAndDraw( my_stringToSprite["Digger"]->getXPos() - 2, my_stringToSprite["Digger"]->getYPos(), my_window );
            
        } else if ( my_model->getMovement() == East ) {
            my_stringToSprite["EmptyCell"]->setSpriteAndDraw( convertIndiceXToPixel( convertXPixel( my_stringToSprite["Digger"]->getXPos() ) ), convertIndiceYToPixel( convertYPixel( my_stringToSprite["Digger"]->getYPos() ) ), my_window );
            
            my_stringToSprite["Digger"]->setSpriteAndDraw( my_stringToSprite["Digger"]->getXPos() + 2, my_stringToSprite["Digger"]->getYPos(), my_window );
            
        } else if ( my_model->getMovement() == SEast ) {
            my_stringToSprite["EmptyCell"]->setSpriteAndDraw( convertIndiceXToPixel( convertXPixel( my_stringToSprite["Digger"]->getXPos() ) ), convertIndiceYToPixel( convertYPixel( my_stringToSprite["Digger"]->getYPos() ) ), my_window );
            
            my_stringToSprite["Digger"]->setSpriteAndDraw( my_stringToSprite["Digger"]->getXPos() + 2, my_stringToSprite["Digger"]->getYPos() + 2, my_window );
            
        } else if ( my_model->getMovement() == SWest ) {
            my_stringToSprite["EmptyCell"]->setSpriteAndDraw( convertIndiceXToPixel( convertXPixel( my_stringToSprite["Digger"]->getXPos() + CASEWITDH  )  ), convertIndiceYToPixel( convertYPixel( my_stringToSprite["Digger"]->getYPos() ) ), my_window );
            
            my_stringToSprite["Digger"]->setSpriteAndDraw( my_stringToSprite["Digger"]->getXPos() - 2, my_stringToSprite["Digger"]->getYPos() + 2, my_window );
            
        }  else if ( my_model->getMovement() == NEast ) {
            my_stringToSprite["EmptyCell"]->setSpriteAndDraw( convertIndiceXToPixel( convertXPixel( my_stringToSprite["Digger"]->getXPos() ) ), convertIndiceYToPixel( convertYPixel( my_stringToSprite["Digger"]->getYPos() + CASEHEIGHT ) ), my_window );
            
            my_stringToSprite["Digger"]->setSpriteAndDraw( my_stringToSprite["Digger"]->getXPos() + 2, my_stringToSprite["Digger"]->getYPos() - 2, my_window );
            
        } else if ( my_model->getMovement() == Nwest ) {
            my_stringToSprite["EmptyCell"]->setSpriteAndDraw( convertIndiceXToPixel( convertXPixel(my_stringToSprite["Digger"]->getXPos() + CASEWITDH ) ), convertIndiceYToPixel( convertYPixel( my_stringToSprite["Digger"]->getYPos() + CASEHEIGHT) ), my_window );
            
            my_stringToSprite["Digger"]->setSpriteAndDraw( my_stringToSprite["Digger"]->getXPos() - 2, my_stringToSprite["Digger"]->getYPos() - 2, my_window);
        }
    }
    
}

/** Events Subscriber */

void InterfaceObserver::mouseMoved(sf::Event event) {
}


void InterfaceObserver::keyPressed(sf::Event event) {
    
    if ( my_context->isPlaying() ) {
        // La touche qui a été appuyée
        switch (event.Key.Code) {
            case Key::Escape : // Echap
                my_window->Close();
                break;
                
            case Key::Right :
                if ( !my_context->isInBreak() )
                    my_model->orderMovement(6);
                break;
                
            case Key::Up:
                if ( !my_context->isInBreak() )
                    my_model->orderMovement(8);
                break;
                
            case Key::Left :
                if ( !my_context->isInBreak() )
                    my_model->orderMovement(4);
                break;
                
            case Key::Down:
                if ( !my_context->isInBreak() )
                    my_model->orderMovement(2);
                break;
                
            case Key::Return:
                cout << my_window->GetWidth() << endl;
                break;
            default :
                break;
        }
        
    } else if ( my_context->isEnterABestScore() ) {
        switch (event.Key.Code) {
            case Key::Return :
                if ( player.length() > 0 ) {
                    my_context->setEnterABestScore( false );
                    my_context->setViewingBestScore( true );
                    enterScore();
                    player = "";
                    
                }
                break;
                
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
    if ( my_context->isEnterABestScore() ) {
        if ( event.Text.Unicode >= 48 && event.Text.Unicode <127 && player.length() < 25 ) {
            player += static_cast<char>(event.Text.Unicode);
            if ( my_soundIcon->getOnOff() )
                my_textSound->Play();
        }
    }
}

void InterfaceObserver::mouseButtonPressed(sf::Event event) {
    if ( my_context->isPlaying() ) {
        if ( convertYPixel( event.MouseButton.Y ) != -1 && convertXPixel( event.MouseButton.X ) != -1 && !my_context->isInAnimation() ) {
            if ( my_soundIcon->getOnOff() )
                my_clickableSoundCell->Play();
            my_model->orderMovement( convertYPixel( event.MouseButton.Y ), convertXPixel( event.MouseButton.X ) );
            my_context->setAnimation( true );
        }
        if ( my_quitButton->isInZone(event.MouseButton.X, event.MouseButton.Y) ) {
            my_context->setPlaying( false );
            my_context->setEnterABestScore( true );
            my_context->setMusic( false );
            my_context->setAnimation( false );
        }
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
                if ( my_soundIcon->getOnOff() )
                    my_gameOverSound->Play();
            }
            my_context->setOver( true );
            my_context->setInBreak( true );
            my_context->setAnimation( false );
            
        }
        
        if ( my_model->getLevel()->lose() ) {
            if ( !my_context->isInBreak() ) {
                pause.Reset();
                if ( !my_context->isTimeOver() && my_soundIcon->getOnOff() )
                    my_loseLevelSound->Play();
            }
            showLoseLevel();
            my_context->setInBreak( true );
            my_context->setAnimation( false );
            
        } else if ( my_model->getLevel()->win()  ) {
            if ( !my_context->isInBreak() )
                pause.Reset();
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
            my_model->getLevel()->resetTime();
            my_context->setInBreak( false );
            my_context->setTimeOver( false );
            pause.Reset();
            if ( my_model->gameOver() ) {
                my_context->setPlaying( false );
                my_context->setEnterABestScore( true );
                my_context->setOver( false );
                my_context->setMusic( false );
            }
        }
    }
}
