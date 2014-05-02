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
InterfaceObserver::InterfaceObserver( sf::RenderWindow* window, GameModel* model, ButtonGraphic *play, ButtonGraphic *setting, ButtonGraphic *best, ButtonGraphic *quit ) : my_window( window ), my_model( model ), my_playButton(play), my_settingButton(setting), my_bestButton(best), my_quitButton(quit) {
    
    
    isInPresentation = true;
    isChoosingOption = false;
    isViewingBestScore = false;
    isEnterABestScore = false;
    isPlaying = false;
    
    my_languageToSprite[english]  = new EnglishGraphic();
    my_languageToSprite[francais] = new FrenchGraphic();
    my_languageToSprite[italiano] = new ItalianoGraphic();
    my_languageToSprite[espanol]  = new SpanishGraphic();
    my_languageToSprite[deutsch]  = new DeutschGraphic();
    
    
    my_fontScore = new Font();
    my_fontTitle = new Font();
    my_bestScoreFont = new Font();
    
    my_scoreString = new String();
    my_titleScoreString = new String();
    my_scoreNum = new String();
    my_titleString = new String();
    my_bestScoreString = new String();
    
    my_musicLevel = new Music();
    
    my_buttonBuffer = new SoundBuffer();
    my_buttonSound = new Sound();
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
    

    my_language = francais;

    
    animation = false;
    player = "";
    over = false;
    time = false;
    isInBreak = false;
    
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
    delete my_musicLevel;
    
    
    for ( std::map<Language, LanguageGraphic*>::const_iterator it = my_languageToSprite.begin() ; it!=my_languageToSprite.end(); ++it) {
        delete my_languageToSprite[ it->first ];
    }
    
    for ( map<string, CellBaseGraphic*>::const_iterator it = my_stringToSprite.begin() ; it!=my_stringToSprite.end(); ++it) {
        delete my_stringToSprite[ it->first ];
    }
    
}


void InterfaceObserver::resetLanguageNorm() {
    for ( std::map<Language, LanguageGraphic*>::const_iterator it = my_languageToSprite.begin() ; it!=my_languageToSprite.end(); ++it) {
        my_languageToSprite[ it->first ]->reset();
    }
    
}


void InterfaceObserver::setAnanasMode() {
#ifdef __linux__
    if (!my_fontScore->LoadFromFile("../Ressources/Font/scoreFont.ttf") || !my_fontTitle->LoadFromFile("../Ressources/Font/titleFont.ttf") || !my_musicLevel->OpenFromFile("../Ressources/Music/gridMusic.wav") || !my_bestScoreFont->LoadFromFile("../Ressources/Font/BestFont.ttf") || !my_buttonBuffer->LoadFromFile("../Ressources/Music/soundButton.wav") || !my_textBuffer->LoadFromFile("../Ressources/Music/soundEnterText.wav") || !my_gameOverBuffer->LoadFromFile("../Ressources/Music/soundGameOver.wav") || !my_clickableBuffer->LoadFromFile("../Ressources/Music/soundIsClickable.wav") || !my_isNotClickableBuffer->LoadFromFile("../Ressources/Music/soundIsNotClickable.wav") || !my_loseLevelBuffer->LoadFromFile("../Ressources/Music/soundLoseLevel.wav") ) {
        cout << "Error when loading font" << endl;
    }
#else
    if (!my_fontScore->LoadFromFile("scoreFont.ttf") || !my_fontTitle->LoadFromFile("titleFont.ttf") || !my_musicLevel->OpenFromFile("gridMusic.wav") || !my_bestScoreFont->LoadFromFile("BestFont.ttf") || !my_buttonBuffer->LoadFromFile("soundButton.wav") || !my_textBuffer->LoadFromFile("soundEnterText.wav") || !my_gameOverBuffer->LoadFromFile("soundGameOver.wav") || !my_clickableBuffer->LoadFromFile("soundIsClickable.wav") || !my_isNotClickableBuffer->LoadFromFile("soundIsNotClickable.wav") || !my_loseLevelBuffer->LoadFromFile("soundLoseLevel.wav") ) {
        cout << "Error when loading font" << endl;
    }
#endif
    else {
        
        //Les affichages de valeurs seront toujours identiques, du coup on les set dir
        my_playButton->setAnanasMode();
        my_settingButton->setAnanasMode();
        my_bestButton->setAnanasMode();
        my_quitButton->setAnanasMode();
        
        for ( std::map<Language, LanguageGraphic*>::const_iterator it = my_languageToSprite.begin() ; it!=my_languageToSprite.end(); ++it) {
            my_languageToSprite[ it->first ]->setAnanasMode();
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
        
        
        my_musicIcon.setAnanasMode();
        my_soundIcon.setAnanasMode();
        my_ananasSprite.setAnanasMode();
        my_teacherSprite.setAnanasMode();
        my_background.setAnanasMode();
    
        
        //Pour la musique
        my_musicLevel->SetLoop(true);
        my_buttonSound->SetBuffer(*my_buttonBuffer);
        my_textSound->SetBuffer(*my_textBuffer);
        my_gameOverSound->SetBuffer(*my_gameOverBuffer);
        my_clickableSoundCell->SetBuffer(*my_clickableBuffer);
        my_isNotClickableSound->SetBuffer(*my_isNotClickableBuffer);
        my_loseLevelSound->SetBuffer(*my_loseLevelBuffer);
    }

    
}

void InterfaceObserver::setTeacherMode() {
#ifdef __linux__
    if ( !my_fontScore->LoadFromFile("../Ressources/Font/arial.ttf") || !my_bestScoreFont->LoadFromFile("../Ressources/Font/arial.ttf") || !my_fontTitle->LoadFromFile("../Ressources/Font/arial.ttf") ||!my_musicLevel->OpenFromFile("Music/gridMusic.wav") || !my_textBuffer->LoadFromFile("../Ressources/Music/soundEnterText.wav") || !my_gameOverBuffer->LoadFromFile("../Ressources/Music/soundGameOver.wav") || !my_clickableBuffer->LoadFromFile("../Ressources/Music/soundIsClickable.wav") || !my_isNotClickableBuffer->LoadFromFile("../Ressources/Music/soundIsNotClickable.wav") || !my_loseLevelBuffer->LoadFromFile("../Ressources/Music/soundLoseLevel.wav")) {
        cout << "Error when loading font" << endl;
    }
#else
    if ( !my_fontScore->LoadFromFile("arial.ttf") || !my_bestScoreFont->LoadFromFile("arial.ttf") || !my_fontTitle->LoadFromFile("arial.ttf") ||!my_musicLevel->OpenFromFile("gridMusic.wav") || !my_textBuffer->LoadFromFile("soundEnterText.wav") || !my_gameOverBuffer->LoadFromFile("soundGameOver.wav") || !my_clickableBuffer->LoadFromFile("soundIsClickable.wav") || !my_isNotClickableBuffer->LoadFromFile("soundIsNotClickable.wav") || !my_loseLevelBuffer->LoadFromFile("soundLoseLevel.wav")) {
        cout << "Error when loading font" << endl;
    }
#endif
    
    else {
        
        my_playButton->setTeacherMode();
        my_settingButton->setTeacherMode();
        my_bestButton->setTeacherMode();
        my_quitButton->setTeacherMode();
        
        for ( std::map<Language, LanguageGraphic*>::const_iterator it = my_languageToSprite.begin() ; it!=my_languageToSprite.end(); ++it) {
            my_languageToSprite[ it->first ]->setTeacherMode();
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
        
        
        my_musicIcon.setTeacherMode();
        my_soundIcon.setTeacherMode();
        my_ananasSprite.setTeacherMode();
        my_teacherSprite.setTeacherMode();
        my_background.setTeacherMode();
        
        my_musicLevel->SetLoop(true);
        my_buttonSound->SetBuffer(*my_buttonBuffer);
        my_textSound->SetBuffer(*my_textBuffer);
        my_gameOverSound->SetBuffer(*my_gameOverBuffer);
        my_clickableSoundCell->SetBuffer(*my_clickableBuffer);
        my_isNotClickableSound->SetBuffer(*my_isNotClickableBuffer);
        my_loseLevelSound->SetBuffer(*my_loseLevelBuffer);
        //Pour la musique
        my_musicLevel->SetLoop(true);
        
                
        
    }
}


void InterfaceObserver::newScreen() {
    my_window->Clear();
    my_background.draw(my_window);
    my_musicIcon.draw(my_window);
    my_soundIcon.draw(my_window);
}

void InterfaceObserver::showPresentation() {
    newScreen();
    
    my_titleString->SetColor(Color(255,255,255));
    my_titleString->SetSize(60);
    
    setTextAndDraw( my_titleString, "PURU PURU DIGGER ", ( WINDOWWITDH / 2 ), 100, true );
    
    my_playButton->setSpriteAndDraw(PLAYX, PLAYY, my_window, my_messages[my_language][play]);
    
    my_settingButton->setSpriteAndDraw(OPTIONX, OPTIONY, my_window, my_messages[my_language][setting]);
    
    my_bestButton->setSpriteAndDraw(BESTX, BESTY, my_window, my_messages[my_language][best]);
    
    my_quitButton->setSpriteAndDraw(QUITX, QUITY, my_window, my_messages[my_language][stop]);
    
}

void InterfaceObserver::showOption() {
    newScreen();
    
    //Le titre de la page
    setTextAndDraw( my_titleString, my_messages[my_language][setting], ( WINDOWWITDH / 2 ), 10, true);
    
    //L'énoncé langue
    setTextAndDraw( my_scoreString, my_messages[my_language][language], QUITONX + 50, CHOICELANGUEHIGH, false);
    
    setTextAndDraw( my_scoreString, my_messages[my_language][actual], QUITONX + 50, MYLANGUEY, false );
    
    setTextAndDraw( my_scoreString, my_messages[my_language][theme], QUITONX + 50, CHOICESPRITEY, false );
    
    
    showLanguage();
    
    //On place notre langue en cours
    
    my_languageToSprite[my_language]->setSpriteAndDraw(MYLANGUEX, MYLANGUEY, my_window);
    
    showSpriteChoice();
    
    my_quitButton->setSpriteAndDraw(QUITONX, QUITONY, my_window, my_messages[my_language][stop]);
    
}

void InterfaceObserver::showLanguage() {
    my_languageToSprite[english]->setSpriteAndDraw(ENGLISHX, CHOICELANGUEHIGH, my_window);
    my_languageToSprite[francais]->setSpriteAndDraw(FRENCHX, CHOICELANGUEHIGH, my_window);
    my_languageToSprite[espanol]->setSpriteAndDraw(SPANISHX, CHOICELANGUEHIGH, my_window);
    my_languageToSprite[deutsch]->setSpriteAndDraw(DEUTSCHX, CHOICELANGUEHIGH, my_window);
    my_languageToSprite[italiano]->setSpriteAndDraw(ITALIANOX, CHOICELANGUEHIGH, my_window);
    
}

void InterfaceObserver::showSpriteChoice() {
    my_ananasSprite.setSpriteAndDraw(CHOICEANANASX, CHOICESPRITEY, my_window);
    my_teacherSprite.setSpriteAndDraw(CHOICETEACHERX, CHOICESPRITEY, my_window);
}

void InterfaceObserver::showBestScore() {
    newScreen();
    
    ifstream scoreLect(FILEBESTSCORE.c_str(), ios::in );
    if ( scoreLect ) {
        string line;
        
        my_titleString->SetColor(Color(255,255,255));
        my_titleString->SetSize(60);
        
        //Le titre de la page
        setTextAndDraw( my_titleString, my_messages[my_language][score], ( WINDOWWITDH / 2 ), 10, true ) ;
        
        int i = 200;
        
        //Le contenu de notre fichier
        while ( getline(scoreLect, line) ) {
            //Pour garantir la plus grand taille
            setTextAndDraw(my_bestScoreString, line, ( WINDOWWITDH / 2 ) , i, true );
            i += 100;
        }
        
        //On affiche le bouton quitter avec son string
        my_quitButton->setSpriteAndDraw(QUITONX, QUITONY, my_window, my_messages[my_language][stop]);
        
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
    setTextAndDraw( my_bestScoreString, my_messages[my_language][by], ( WINDOWWITDH / 2 ), 10, true );
    setTextAndDraw( my_bestScoreString, my_messages[my_language][name], ( WINDOWWITDH / 2 ), 100, true );
    
    setTextAndDraw( my_bestScoreString, player, ( WINDOWWITDH / 2 ) , WINDOWHEIGHT / 2, true ) ;
}



void InterfaceObserver::showGrid() {
    if ( animation )
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
    
    if ( !time && !over ) {
        setTextAndDraw( my_titleString, my_messages[my_language][looselevel],( WINDOWWITDH / 2 ), WINDOWHEIGHT / 2, true ) ;
    } else if ( time ) {
        setTextAndDraw( my_titleString, my_messages[my_language][timeup], ( WINDOWWITDH / 2 ), WINDOWHEIGHT / 2, true );
    } else if ( over ) {
        setTextAndDraw( my_titleString, my_messages[my_language][loosegame], ( WINDOWWITDH / 2 ), WINDOWHEIGHT / 2, true );
    } else if ( time && over ) {
        setTextAndDraw( my_titleString, my_messages[my_language][loosegame], ( WINDOWWITDH / 2 ), WINDOWHEIGHT / 2, true );
    }
}

void InterfaceObserver::showWinLevel() {
    newScreen();
    
    my_titleString->SetSize(40);
    my_titleString->SetColor(Color(0,0,0));
    
    setTextAndDraw( my_titleString, my_messages[my_language][winlevel], ( WINDOWWITDH / 2 ), WINDOWHEIGHT / 2, true ) ;
}

void InterfaceObserver::showScore() {
    //Le titre
    setTextAndDraw( my_titleScoreString, my_messages[my_language][score] + " : ", 100, 80, false);
    
    //Level et son num
    setTextAndDraw( my_scoreString, my_messages[my_language][level] + " : ", 20, 140, false);
    
    
    setTextAndDraw( my_scoreNum, intToString(my_model->getScore()->getCurrentStep() ), my_scoreString->GetRect().GetWidth() + 40, 140, false );
    
    //Score Total
    setTextAndDraw( my_scoreString, my_messages[my_language][global] + " : ", 20, 180, false);
    
    
    setTextAndDraw( my_scoreNum, intToString(my_model->getScore()->getGlobale() ), my_scoreString->GetRect().GetWidth() + 40, 180, false );
    
    //Score en cours
    setTextAndDraw( my_scoreString, my_messages[my_language][current] + " : ", 20, 220, false);
    
    
    setTextAndDraw( my_scoreNum, intToString(my_model->getScore()->getCurrent() ), my_scoreString->GetRect().GetWidth() + 40, 220, false );
    
    
    //Objectif
    setTextAndDraw( my_scoreString, my_messages[my_language][goal] + " : ", 20, 260, false);
    
    
    setTextAndDraw( my_scoreNum, intToString(my_model->getLevel()->getGoal() ), my_scoreString->GetRect().GetWidth() + 40, 260, false );
    
    
    //En cours
    setTextAndDraw( my_scoreString, my_messages[my_language][step] + " : ", 20, 300, false);
    
    
    setTextAndDraw( my_scoreNum, intToString(my_model->getLevel()->getCurrentMove() ), my_scoreString->GetRect().GetWidth() + 40, 300 , false);
    
    //La vie
    setTextAndDraw( my_scoreString, my_messages[my_language][life] + " : ", 20, 340, false);
    
    
    setTextAndDraw( my_scoreNum, intToString(my_model->getLevel()->getDigger()->getLife()), my_scoreString->GetRect().GetWidth() + 40, 340, false );
    
    //Le temps
    setTextAndDraw( my_scoreString, my_messages[my_language][ltime] + " : ", 20, 380, false);
    
    
    setTextAndDraw( my_scoreNum, intToString( my_model->getLevel()->leftTime() ) , my_scoreString->GetRect().GetWidth() + 40, 380 , false);
    
    //La position
    setTextAndDraw( my_scoreString, my_messages[my_language][position] + " : ", 20, 420, false);
    
    
    setTextAndDraw( my_scoreNum, "[ " + intToString( my_model->getLevel()->getDigger()->getX() ) + " ] [ " +  intToString( my_model->getLevel()->getDigger()->getY() )  + " ] " , my_scoreString->GetRect().GetWidth() + 40, 420, false );
    
}

void InterfaceObserver::showLevel() {
    if ( !animation ) {
        newScreen();
        
        my_titleString->SetColor(Color(255,255,255));
        my_titleString->SetSize(60);
        
        setTextAndDraw( my_titleString, " PURU PURU DIGGER " , ( WINDOWWITDH / 2 ), 10, true ) ;
        
        //On dessine le score
        showScore();
        
        my_quitButton->setSpriteAndDraw(QUITONX, QUITONY, my_window, my_messages[my_language][stop]);
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
        animation = false;
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
    
    if ( isPlaying ) {
        // La touche qui a été appuyée
        switch (event.Key.Code) {
            case Key::Escape : // Echap
                my_window->Close();
                break;
                
            case Key::Right :
                if ( !isInBreak && isPlaying )
                    my_model->orderMovement(6);
                break;
                
            case Key::Up:
                if ( !isInBreak && isPlaying )
                    my_model->orderMovement(8);
                break;
                
            case Key::Left :
                if ( !isInBreak  && isPlaying)
                    my_model->orderMovement(4);
                break;
                
            case Key::Down:
                if ( !isInBreak && isPlaying )
                    my_model->orderMovement(2);
                break;
                
            case Key::Return:
                cout << my_window->GetWidth() << endl;
                break;
            default :
                break;
        }
        
    } else if ( isEnterABestScore ) {
        switch (event.Key.Code) {
            case Key::Return :
                if ( player.length() > 0 ) {
                    isEnterABestScore = false;
                    isViewingBestScore = true;
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
    if ( isEnterABestScore ) {
        if ( event.Text.Unicode >= 48 && event.Text.Unicode <127 && player.length() < 25 ) {
            player += static_cast<char>(event.Text.Unicode);
            if ( my_soundIcon.getOnOff() )
                my_textSound->Play();
        }
    }
}

void InterfaceObserver::mouseButtonPressed(sf::Event event) {
    if ( isInPresentation ) {
        if ( my_playButton->isInZone(event.MouseButton.X, event.MouseButton.Y) ) {
            isInPresentation = false;
            isPlaying = true;
            my_model->reset();
            if ( my_soundIcon.getOnOff())
                my_buttonSound->Play();
            
            if ( my_musicIcon.getOnOff() )
                my_musicLevel->Play();
            
        } else if ( my_quitButton->isInZone(event.MouseButton.X, event.MouseButton.Y) ) {
            if ( my_soundIcon.getOnOff())
                my_buttonSound->Play();
            my_window->Close();
            
        } else if ( my_settingButton->isInZone(event.MouseButton.X, event.MouseButton.Y) ) {
            isInPresentation = false;
            isChoosingOption = true;
            if ( my_soundIcon.getOnOff())
                my_buttonSound->Play();
            
        } else if ( my_bestButton->isInZone(event.MouseButton.X, event.MouseButton.Y) ) {
            isInPresentation = false;
            isViewingBestScore = true;
            if ( my_soundIcon.getOnOff())
                my_buttonSound->Play();
            
        } else if ( my_musicIcon.isInZone(event.MouseButton.X, event.MouseButton.Y) ) {
            my_musicIcon.reverse();
            
        } else if ( my_soundIcon.isInZone(event.MouseButton.X, event.MouseButton.Y) ) {
            my_soundIcon.reverse();
        }
        
    } else if ( isChoosingOption ) {
        
        if ( my_languageToSprite[english]->isInZone ( event.MouseButton.X, event.MouseButton.Y ) ) {
            my_language = english;
            resetLanguageNorm();
            
        } else if ( my_languageToSprite[francais]->isInZone ( event.MouseButton.X, event.MouseButton.Y )  ) {
            my_language = francais;
            resetLanguageNorm();
            
        } else if ( my_languageToSprite[italiano]->isInZone ( event.MouseButton.X, event.MouseButton.Y )  ) {
            my_language = italiano;
            resetLanguageNorm();
            
        } else if ( my_languageToSprite[espanol]->isInZone ( event.MouseButton.X, event.MouseButton.Y )  ) {
            my_language = espanol;
            resetLanguageNorm();
            
        } else if ( my_languageToSprite[deutsch]->isInZone ( event.MouseButton.X, event.MouseButton.Y )  ) {
            my_language = deutsch;
            resetLanguageNorm();
            
        } else if ( my_ananasSprite.isInZone( event.MouseButton.X, event.MouseButton.Y ) ) {
            setAnanasMode();
            
        } else if ( my_teacherSprite.isInZone( event.MouseButton.X, event.MouseButton.Y) ) {
            setTeacherMode();
            
        }else if ( my_quitButton->isInZone(event.MouseButton.X, event.MouseButton.Y) ) {
            if ( my_soundIcon.getOnOff())
                my_buttonSound->Play();
            isChoosingOption = false;
            isInPresentation = true;
            
        } else if ( my_musicIcon.isInZone( event.MouseButton.X, event.MouseButton.Y) ) {
            my_musicIcon.reverse();
            
        } else if ( my_soundIcon.isInZone( event.MouseButton.X, event.MouseButton.Y ) ) {
            my_soundIcon.reverse();
        }
        
    } else if ( isViewingBestScore ) {
        
        if ( my_quitButton->isInZone(event.MouseButton.X, event.MouseButton.Y ) ) {
            if ( my_soundIcon.getOnOff())
                my_buttonSound->Play();
            isViewingBestScore = false;
            isInPresentation = true;
            
        } else if ( my_musicIcon.isInZone( event.MouseButton.X, event.MouseButton.Y) ) {
            my_musicIcon.reverse();
            
        } else if ( my_soundIcon.isInZone( event.MouseButton.X, event.MouseButton.Y ) ) {
            my_soundIcon.reverse();
        }
        
    } else if ( isPlaying ) {
        if ( convertYPixel( event.MouseButton.Y ) != -1 && convertXPixel( event.MouseButton.X ) != -1 && !animation) {
            if ( my_soundIcon.getOnOff() )
                my_clickableSoundCell->Play();
            my_model->orderMovement( convertYPixel( event.MouseButton.Y ), convertXPixel( event.MouseButton.X ) );
            animation = true;
            
        }
        if ( my_quitButton->isInZone(event.MouseButton.X, event.MouseButton.Y) ) {
            if ( my_soundIcon.getOnOff())
                my_buttonSound->Play();
            isPlaying = false;
            isEnterABestScore = true;
            my_musicLevel->Stop();
            animation = false;
            
        } else if ( my_musicIcon.isInZone( event.MouseButton.X, event.MouseButton.Y) ) {
            my_musicIcon.reverse();
            
            if ( my_musicIcon.getOnOff() )
                my_musicLevel->Play();
            else
                my_musicLevel->Pause();
            
        } else if ( my_soundIcon.isInZone(event.MouseButton.X, event.MouseButton.Y) ) {
            my_soundIcon.reverse();
        }
    }
}

void InterfaceObserver::preDisplay() {
    
    if ( isInPresentation ) {
        showPresentation();
        
    } else if ( isChoosingOption ) {
        showOption();
        
    } else if ( isViewingBestScore ) {
        showBestScore();
        
    } else if ( isPlaying ) {
        
        //On check le temps, et l'on peut perdre à cause de lui.
        if ( my_model->getLevel()->timeIsUp() ) {
            my_model->getLevel()->lostLevel();
            time = true;
        }
        
        if ( my_model->gameOver() ) {
            if ( !isInBreak ) {
                pause.Reset();
                if ( my_soundIcon.getOnOff() )
                    my_gameOverSound->Play();
            }
            over = true;
            isInBreak = true;
            animation = false;
            
        }
        
        if ( my_model->getLevel()->lose() ) {
            if ( !isInBreak ) {
                pause.Reset();
                if ( !over && my_soundIcon.getOnOff() )
                    my_loseLevelSound->Play();
            }
            showLoseLevel();
            isInBreak = true;
            animation = false;
            
        } else if ( my_model->getLevel()->win()  ) {
            if ( !isInBreak )
                pause.Reset();
            showWinLevel();
            isInBreak = true;
            animation = false;
            
        } else {
            showLevel();
        }
    } else if ( isEnterABestScore ) {
        showIsEnteringABestScore( player );
    }

}

void InterfaceObserver::postDisplay() {
    if ( isInBreak ) {
        
        if ( pause.GetElapsedTime() > 1.5 ) {
            
            my_model->getLevel()->resetLose();
            my_model->getLevel()->resetWin();
            my_model->getLevel()->resetTime();
            isInBreak = false;
            time = false;
            pause.Reset();
            if ( my_model->gameOver() ) {
                isPlaying = false;
                isEnterABestScore = true;
                over = false;
                my_musicLevel->Stop();
            }
        }
    }
}
