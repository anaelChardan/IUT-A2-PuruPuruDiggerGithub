#include "GameViewSFML.h"
#include "Constantes.h"
#include <sstream>
#include "Utils.h"

using namespace std;
using namespace sf;


//Début de l'écriture des fonctions pour la SFML
 GameView::GameView() {
     //Le style de la fenêtres
     my_window = new RenderWindow( VideoMode(WINDOWWITDH, WINDOWHEIGHT, BPP), "PuruPuruDigger", Style::Close);
     
     //On bloque le rafraichissement à 60 par seconde
     my_window->SetFramerateLimit(60);
 
     my_language = francais;
     
     //La font pour les scores
     my_fontScore = new Font();
     my_fontTitle = new Font();
     my_fontValue = new Font();
     my_fontButton = new Font();
     
     my_valueString = new String();
     my_scoreString = new String();
     my_titleScoreString = new String();
     my_scoreNum = new String();
     my_titleString = new String();
     my_buttonString = new String();
 
     my_backgroundImage = new Image();
     my_languageImage = new Image();
     my_caseImage = new Image();
     my_buttonImage = new Image();
     my_spriteImage = new Image();
     
     //On set les sprites
     my_diggerSprite = new Sprite();
     my_valueSprite = new Sprite();
     my_goldSprite = new Sprite();
     my_bombSprite = new Sprite();
     my_backgroundSprite = new Sprite();
     my_emptySprite = new Sprite();
     my_frenchSprite = new Sprite();
     my_englishSprite = new Sprite();
     my_deutschSprite = new Sprite();
     my_italianoSprite = new Sprite();
     my_spanishSprite = new Sprite();
     my_ananasSprite = new Sprite();
     my_teacherSprite = new Sprite();
     
     //Les boutons
     my_buttonQuitSprite = new Sprite();
     my_optionButtonSprite = new Sprite();
     my_playButtonSprite = new Sprite();
     my_bestButtonSprite = new Sprite();
     my_quitButtonSprite = new Sprite();
     
     my_musicLevel = new Music();
 
     //Chargement des images selon le mode
     setTeacherMode();
}

GameView::~GameView() {
    delete my_window;
    delete my_diggerSprite;
    delete my_valueSprite;
    delete my_goldSprite;
    delete my_bombSprite;
    delete my_backgroundSprite;
    delete my_emptySprite;
    delete my_fontScore;
    delete my_fontTitle;
    delete my_fontValue;
    
    delete my_valueString;
    delete my_scoreString;
    delete my_titleString;
    
    delete my_backgroundImage;
    
    delete my_caseImage;
}

void GameView::setImageToSprite() {
    my_languageImage->CreateMaskFromColor(Color(0, 55, 97));
    my_caseImage->CreateMaskFromColor( Color(0, 55, 97) );
    my_buttonImage->CreateMaskFromColor( Color(0, 55, 97) );
    my_spriteImage->CreateMaskFromColor( Color(0, 55, 97) );
    
    //On set les sprites de nos images
    my_backgroundSprite->SetImage( *my_backgroundImage );
    my_backgroundSprite->Resize( WINDOWWITDH, WINDOWHEIGHT );
    
    //On set les choix des sprites
    my_ananasSprite->SetImage( *my_spriteImage );
    my_ananasSprite->SetSubRect( IntRect ( SPRITEANANASSX, SPRITECHOICEBEGIN, SPRITEANANASEX, SPRITECHOICEHEIGHT));
    my_ananasSprite->Resize( SPRITECHOICEWIDTH, SPRITECHOICEHEIGHT );
    
    my_teacherSprite->SetImage( *my_spriteImage );
    my_teacherSprite->SetSubRect( IntRect ( SPRITETEACHERSX, SPRITECHOICEBEGIN, SPRITETEACHEREX, SPRITECHOICEHEIGHT ) );
    my_teacherSprite->Resize( SPRITECHOICEWIDTH, SPRITECHOICEHEIGHT );
    
    
    //Mise en places des sprites case
    my_diggerSprite->SetImage( *my_caseImage );
    my_diggerSprite->SetSubRect( IntRect( DIGGERSX, SPRITECASEBEGIN, DIGGEREX, SPRITECASEHEIGHT ) );
    my_diggerSprite->Resize( CASEWITDH, CASEHEIGHT );
    
    my_valueSprite->SetImage( *my_caseImage );
    my_valueSprite->SetSubRect( IntRect(VALUESX, SPRITECASEBEGIN, VALUEEX, SPRITECASEHEIGHT ) );
    my_valueSprite->Resize( CASEWITDH, CASEHEIGHT );
    
    
    my_goldSprite->SetImage( *my_caseImage );
    my_goldSprite->SetSubRect( IntRect(GOLDSX, SPRITECASEBEGIN, GOLDEX, SPRITECASEHEIGHT ) );
    my_goldSprite->Resize( CASEWITDH, CASEHEIGHT );
    
    my_bombSprite->SetImage( *my_caseImage );
    my_bombSprite->SetSubRect( IntRect( BOMBSX, SPRITECASEBEGIN, BOMBEX, SPRITECASEHEIGHT ) );
    my_bombSprite->Resize( CASEWITDH, CASEHEIGHT );
    
    my_emptySprite->SetImage( *my_caseImage );
    my_emptySprite->SetSubRect( IntRect( EMPTYSX, SPRITECASEBEGIN, EMPTYEX, SPRITECASEHEIGHT ) );
    my_emptySprite->Resize( CASEWITDH, CASEHEIGHT );
    
    //On set les boutons
    my_buttonQuitSprite->SetImage( *my_buttonImage );
    my_buttonQuitSprite->SetSubRect( IntRect( BUTTONNORMSX, BUTTONCASEBEGIN, BUTTONNORMEX, BUTTONCASEHEIGHT ) );
    my_buttonQuitSprite->Resize(BUTTONWIDTH, BUTTONHEIGHT);
    
    my_playButtonSprite->SetImage( *my_buttonImage );
    my_playButtonSprite->SetSubRect( IntRect( BUTTONNORMSX, BUTTONCASEBEGIN, BUTTONNORMEX, BUTTONCASEHEIGHT ) );
    my_playButtonSprite->Resize( BUTTONWIDTH, BUTTONHEIGHT );
    
    my_optionButtonSprite->SetImage( *my_buttonImage );
    my_optionButtonSprite->SetSubRect( IntRect( BUTTONNORMSX, BUTTONCASEBEGIN, BUTTONNORMEX, BUTTONCASEHEIGHT ) );
    my_optionButtonSprite->Resize( BUTTONWIDTH, BUTTONHEIGHT );
    
    my_bestButtonSprite->SetImage( *my_buttonImage );
    my_bestButtonSprite->SetSubRect( IntRect( BUTTONNORMSX, BUTTONCASEBEGIN, BUTTONNORMEX, BUTTONCASEHEIGHT ) );
    my_bestButtonSprite->Resize( BUTTONWIDTH, BUTTONHEIGHT );
    
    my_quitButtonSprite->SetImage( *my_buttonImage );
    my_quitButtonSprite->SetSubRect( IntRect( BUTTONNORMSX, BUTTONCASEBEGIN, BUTTONNORMEX, BUTTONCASEHEIGHT ) );
    my_quitButtonSprite->Resize( BUTTONWIDTH, BUTTONHEIGHT );
    
    
    my_stringToSprite["Digger"] = *my_diggerSprite;
    my_stringToSprite["EmptyCell"] = *my_emptySprite;
    my_stringToSprite["GoldCell"] = *my_goldSprite;
    my_stringToSprite["Bomb"] = *my_bombSprite;
    my_stringToSprite["ValueCell" ] = *my_valueSprite;
    
    my_englishSprite->SetImage( *my_languageImage );
    my_englishSprite->SetSubRect( IntRect( ENGLISHSX, SPRITELANGUEBEGIN, ENGLISHEX, SPRITELANGUEHEIGHT ) );
    my_englishSprite->Resize( LANGUEWIDTH, LANGUEHEIGHT );
    
    my_frenchSprite->SetImage( *my_languageImage );
    my_frenchSprite->SetSubRect( IntRect( FRENCHSX, SPRITELANGUEBEGIN, FRENCHEX, SPRITELANGUEHEIGHT ) );
    my_frenchSprite->Resize( LANGUEWIDTH, LANGUEHEIGHT );
    
    my_italianoSprite->SetImage( *my_languageImage );
    my_italianoSprite->SetSubRect( IntRect( ITALIANOSX, SPRITELANGUEBEGIN, ITALIANOEX, SPRITELANGUEHEIGHT ) );
    my_italianoSprite->Resize( LANGUEWIDTH, LANGUEHEIGHT );
    
    my_spanishSprite->SetImage( *my_languageImage );
    my_spanishSprite->SetSubRect( IntRect( SPANISHSX, SPRITELANGUEBEGIN, SPANISHEX, SPRITELANGUEHEIGHT ) );
    my_spanishSprite->Resize( LANGUEWIDTH, LANGUEHEIGHT );
    
    my_deutschSprite->SetImage( *my_languageImage );
    my_deutschSprite->SetSubRect( IntRect( DEUTSCHSX, SPRITELANGUEBEGIN, DEUTSCHEX, SPRITELANGUEHEIGHT ) );
    my_deutschSprite->Resize( LANGUEWIDTH, LANGUEHEIGHT );
    
    my_languageToSprite[english] = *my_englishSprite;
    my_languageToSprite[francais] = *my_frenchSprite;
    my_languageToSprite[italiano] = *my_italianoSprite;
    my_languageToSprite[deutsch] = *my_deutschSprite;
    my_languageToSprite[espanol] = *my_spanishSprite;
}

void GameView::setAnanasMode() {
#ifdef __linux__
    if (!my_backgroundImage->LoadFromFile("Pictures/wallpapper.png") || !my_caseImage->LoadFromFile("Pictures/case.png") || !my_buttonImage->LoadFromFile("Pictures/buttonAnanas.png") || !my_languageImage->LoadFromFile("Pictures/languages.png") || !my_spriteImage->LoadFromFile("Pictures/choiceSprite.png") || !my_fontScore->LoadFromFile("Font/scoreFont.ttf") || !my_fontTitle->LoadFromFile("Font/titleFont.ttf") || !my_fontValue->LoadFromFile("Font/valueFont.ttf") || !my_fontButton->LoadFromFile("Font/buttonFont.ttf") || !my_musicLevel->OpenFromFile("Music/gridMusic.wav")) {
        cout << "Error when loading image or font" << endl;
    }
#else
    if (!my_backgroundImage->LoadFromFile("wallpapper.png") || !my_caseImage->LoadFromFile("case.png") || !my_buttonImage->LoadFromFile("buttonAnanas.png") || !my_languageImage->LoadFromFile("languages.png") || !my_spriteImage->LoadFromFile("choiceSprite.png") || !my_fontScore->LoadFromFile("scoreFont.ttf") || !my_fontTitle->LoadFromFile("titleFont.ttf") || !my_fontValue->LoadFromFile("valueFont.ttf") || !my_fontButton->LoadFromFile("buttonFont.ttf") || !my_musicLevel->OpenFromFile("gridMusic.wav") ) {
        cout << "Error when loading image or font" << endl;
    }
#endif
    else {
        
        //Les affichages de valeurs seront toujours identiques, du coup on les set direct
        my_valueString->SetFont( *my_fontValue );
        my_valueString->SetColor(Color(255,255,255) );
        my_valueString->SetSize(23);
        
        my_titleScoreString->SetFont( *my_fontScore );
        my_titleScoreString->SetSize(40);
        my_titleScoreString->SetStyle(String::Underlined | String::Bold | String::Italic );
        my_titleScoreString->SetColor(Color(50,50,150));
        
        my_scoreString->SetFont( *my_fontScore );
        my_scoreString->SetColor(Color(251,210,98));
        my_scoreString->SetStyle(String::Underlined);
        
        my_scoreNum->SetFont( * my_fontScore );
        my_scoreNum->SetColor(Color(255,100,100));
        
        my_scoreString->SetSize(30);
        
        my_titleString->SetFont( *my_fontTitle );
        
        my_buttonString->SetFont( *my_fontButton );
        my_buttonString->SetSize(30);
        my_buttonString->SetColor(Color(251,210,98));
        
        my_musicLevel->SetLoop(true);
        
        
        
    }
    
    setImageToSprite();
}


void
GameView::setTeacherMode() {
#ifdef __linux__
    if (!my_backgroundImage->LoadFromFile("Pictures/wallpapperTeach.png") || !my_caseImage->LoadFromFile("Pictures/caseTeach.png") || !my_buttonImage->LoadFromFile("Pictures/buttonTeach.png") || !my_languageImage->LoadFromFile("Pictures/languages.png") || !my_spriteImage->LoadFromFile("Pictures/choiceSprite.png") ||!my_fontScore->LoadFromFile("Font/arial.ttf") || !my_fontTitle->LoadFromFile("Font/arial.ttf") || !my_fontValue->LoadFromFile("Font/arial.ttf") || !my_fontButton->LoadFromFile("Font/arial.ttf") || !my_musicLevel->OpenFromFile("Music/gridMusic.wav")) {
        cout << "Error when loading image or font" << endl;
    }
#else
    if (!my_backgroundImage->LoadFromFile("wallpapperTeach.png") || !my_caseImage->LoadFromFile("caseTeach.png") || !my_buttonImage->LoadFromFile("buttonTeach.png") || !my_languageImage->LoadFromFile("languages.png") || !my_spriteImage->LoadFromFile("choiceSprite.png") ||!my_fontScore->LoadFromFile("arial.ttf") || !my_fontTitle->LoadFromFile("arial.ttf") || !my_fontValue->LoadFromFile("arial.ttf") || !my_fontButton->LoadFromFile("arial.ttf") || !my_musicLevel->OpenFromFile("gridMusic.wav")) {
        cout << "Error when loading image or font" << endl;
    }
#endif
    
    else {
        
        //Le string pour la page de présentation
        my_titleString->SetFont( *my_fontTitle );
        
        //Le string pour les cases numérotées
        my_valueString->SetFont( *my_fontValue );
        my_valueString->SetColor(Color(0,0,0) );
        my_valueString->SetSize(20);
        my_valueString->SetStyle( String::Bold );
        
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
    
        my_buttonString->SetFont( *my_fontButton );
        my_buttonString->SetSize(30);
        my_buttonString->SetColor(Color(0,0,0));

    }
    
    setImageToSprite();
}

void
GameView::setButtonHover( sf::Sprite* buttonToHover ) {
    buttonToHover->SetSubRect( IntRect( BUTTONHOVESX, BUTTONCASEBEGIN, BUTTONHOVEEX, BUTTONCASEHEIGHT ) );
}

void
GameView::resetButtonNorm() {
    my_playButtonSprite->SetSubRect( IntRect( BUTTONNORMSX, BUTTONCASEBEGIN, BUTTONNORMEX, BUTTONCASEHEIGHT ) );
    my_quitButtonSprite->SetSubRect( IntRect( BUTTONNORMSX, BUTTONCASEBEGIN, BUTTONNORMEX, BUTTONCASEHEIGHT ) );
    my_optionButtonSprite->SetSubRect( IntRect( BUTTONNORMSX, BUTTONCASEBEGIN, BUTTONNORMEX, BUTTONCASEHEIGHT ) );
    my_bestButtonSprite->SetSubRect( IntRect( BUTTONNORMSX, BUTTONCASEBEGIN, BUTTONNORMEX, BUTTONCASEHEIGHT ) );
    my_buttonQuitSprite->SetSubRect( IntRect( BUTTONNORMSX, BUTTONCASEBEGIN, BUTTONNORMEX, BUTTONCASEHEIGHT ) );
}

void
GameView::showPresentation() {
    my_window->Clear();
    my_window->Draw(*my_backgroundSprite);
    my_titleString->SetText("PURU PURU DIGGER");
    my_titleString->SetColor(Color(255,255,255));
    my_titleString->SetSize(60);
    my_titleString->SetPosition( ( WINDOWWITDH / 2 ) - ( my_titleString->GetRect().GetWidth() / 2 ) , 100 );
    my_window->Draw( *my_titleString );
    
    my_quitButtonSprite->SetPosition(QUITX, QUITY);
    my_playButtonSprite->SetPosition( PLAYX, PLAYY );
    my_optionButtonSprite->SetPosition(OPTIONX, OPTIONY);
    my_bestButtonSprite->SetPosition(BESTX, BESTY);
    

    my_window->Draw( *my_playButtonSprite );
    
    
    my_window->Draw( *my_optionButtonSprite );
    
    
    my_window->Draw( *my_bestButtonSprite);
    

    my_window->Draw( *my_quitButtonSprite);
    
    my_buttonString->SetText( my_messages[my_language][best] ) ;
    my_buttonString->SetPosition( BESTX + 40, (BESTY + (BUTTONHEIGHT / 5)) );
    my_window->Draw( *my_buttonString );
    
    my_buttonString->SetText( my_messages[my_language][play] ) ;
    my_buttonString->SetPosition(  PLAYX  + 40, PLAYY + (BUTTONHEIGHT / 5) );
    my_window->Draw( *my_buttonString );
    
    my_buttonString->SetText( my_messages[my_language][stop] ) ;
    my_buttonString->SetPosition(  QUITX + 40, (QUITY + (BUTTONHEIGHT * 0.2 )) );
    my_window->Draw( *my_buttonString );
    
    my_buttonString->SetText( my_messages[my_language][setting] ) ;
    my_buttonString->SetPosition(  OPTIONX + 40   , OPTIONY + (BUTTONHEIGHT * 0.2) );
    my_window->Draw( *my_buttonString );
    
}


void
GameView::showOption() {
    my_window->Clear();
    my_window->Draw(*my_backgroundSprite);
    
    my_titleString->SetText(my_messages[my_language][setting]);
    my_titleString->SetPosition( ( WINDOWWITDH / 2 ) - ( my_titleString->GetRect().GetWidth() / 2 ) , 10 );
    my_window->Draw( *my_titleString );
    
    my_scoreString->SetText( my_messages[my_language][language]);
    my_scoreString->SetPosition( QUITONX + 50, CHOICELANGUEHIGH );
    my_window->Draw( * my_scoreString );
    
    my_scoreString->SetText( my_messages[my_language][actual]);
    my_scoreString->SetPosition( QUITONX + 50, MYLANGUEY );
    my_window->Draw( * my_scoreString );
    
    my_scoreString->SetText( my_messages[my_language][theme] );
    my_scoreString->SetPosition( QUITONX + 50, CHOICESPRITEY );
    my_window->Draw( *my_scoreString );
    
    
    showLanguage();
    
    my_languageToSprite[my_language].SetPosition(MYLANGUEX, MYLANGUEY);
    my_window->Draw(my_languageToSprite[my_language]);
    
    showSpriteChoice();
    
    
    my_buttonQuitSprite->SetPosition( QUITONX, QUITONY);
    my_window->Draw( *my_buttonQuitSprite );
    
    my_buttonString->SetText( my_messages[my_language][stop] );
    my_buttonString->SetPosition( ( ( ( QUITONX + BUTTONWIDTH ) / 2.5 )  ), (QUITONY + (BUTTONHEIGHT / 5)) );
    my_window->Draw( *my_buttonString );
}

void
GameView::setHoverLanguage( Language hover ) {
    my_languageToSprite[hover].SetColor(Color(255,255,255,128));
}

void GameView::resetLanguageNorm() {
    for ( map<Language, Sprite>::const_iterator it = my_languageToSprite.begin() ; it!=my_languageToSprite.end(); ++it) {
        my_languageToSprite[ it->first ].SetColor(Color(255,255,255,255));
    }
    
}
void
GameView::showLanguage() {
    my_languageToSprite[english].SetPosition(ENGLISHX, CHOICELANGUEHIGH);
    my_languageToSprite[francais].SetPosition(FRENCHX, CHOICELANGUEHIGH);
    my_languageToSprite[italiano].SetPosition(ITALIANOX, CHOICELANGUEHIGH);
    my_languageToSprite[deutsch].SetPosition(DEUTSCHX, CHOICELANGUEHIGH);
    my_languageToSprite[espanol].SetPosition(SPANISHX, CHOICELANGUEHIGH);
    
    my_window->Draw(my_languageToSprite[english]);
    my_window->Draw(my_languageToSprite[francais]);
    my_window->Draw(my_languageToSprite[italiano]);
    my_window->Draw(my_languageToSprite[deutsch]);
    my_window->Draw(my_languageToSprite[espanol]);
}


void
GameView::showSpriteChoice() {
    my_ananasSprite->SetPosition( CHOICEANANASX, CHOICESPRITEY);
    my_teacherSprite->SetPosition( CHOICETEACHERX, CHOICESPRITEY);
    my_window->Draw(*my_ananasSprite);
    my_window->Draw(*my_teacherSprite);
}



void
GameView::showGrid() {
    for ( int i = 0; i < LIGNE ; i++ ) {
        for ( int j = 0; j < COLONNE; j++ ) {
            my_stringToSprite[ my_model->getLevel()->getGrid()[i][j]->getType() ].SetPosition( convertIndiceXToPixel( j ), convertIndiceYToPixel( i ) );
            my_window->Draw( my_stringToSprite[ my_model->getLevel()->getGrid()[i][j]->getType() ] );
            
            if ( my_model->getLevel()->getGrid()[i][j]->getType() == "ValueCell" || my_model->getLevel()->getGrid()[i][j]->getType() == "GoldCell") {
                my_valueString->SetText( intToString( my_model->getLevel()->getGrid()[i][j]->getValue() ) );
                my_valueString->SetPosition( ( convertIndiceXToPixel( j ) + CASEWITDH / 3 ), ( convertIndiceYToPixel( i ) + CASEHEIGHT / 6 ) );
                my_window->Draw( *my_valueString );
            }
        }
    }
}
void
GameView::showLoseLevel() {
    my_window->Clear();
    my_window->Draw( *my_backgroundSprite );
    my_titleString->SetSize(40);
    my_titleString->SetColor(Color(0,0,0));
    my_titleString->SetText( my_messages[my_language][looselevel] );
    my_titleString->SetPosition(  ( ( WINDOWWITDH / 2 ) - ( my_titleString->GetRect().GetWidth() / 2 ) ), WINDOWHEIGHT / 2 );
    my_window->Draw(*my_titleString);
}

void
GameView::showWinLevel() {
    my_window->Clear();
    my_window->Draw( *my_backgroundSprite );
    my_titleString->SetSize(40);
    my_titleString->SetColor(Color(0,0,0));
    my_titleString->SetText( my_messages[my_language][winlevel] );
    my_titleString->SetPosition(  ( ( WINDOWWITDH / 2 ) - ( my_titleString->GetRect().GetWidth() / 2 ) ), WINDOWHEIGHT / 2 );
    my_window->Draw(*my_titleString);
}

void
GameView::showScore() {
    //Le titre
    my_titleScoreString->SetPosition(100, 80);
    my_titleScoreString->SetText(  my_messages[my_language][score] + " : " );
    my_window->Draw( *my_titleScoreString );
    
    //Level et son num
    my_scoreString->SetText(  my_messages[my_language][level] );
    my_scoreString->SetPosition( 20, 140 );
    my_window->Draw( *my_scoreString );
    
    my_scoreNum->SetPosition( my_scoreString->GetRect().GetWidth() + 40, 140 );
    my_scoreNum->SetText( intToString(my_model->getScore()->getCurrentStep() ) );
    my_window->Draw( *my_scoreNum);
    
    //Score Total
    my_scoreString->SetText(  my_messages[my_language][global] );
    my_scoreString->SetPosition( 20, 180 );
    my_window->Draw( *my_scoreString );
    
    my_scoreNum->SetPosition( my_scoreString->GetRect().GetWidth() + 40, 180 );
    my_scoreNum->SetText( intToString(my_model->getScore()->getGlobale() ) );
    my_window->Draw( *my_scoreNum);
    
    //Score en cours
    my_scoreString->SetText(  my_messages[my_language][current] );
    my_scoreString->SetPosition( 20, 220 );
    my_window->Draw( *my_scoreString );
    
    my_scoreNum->SetPosition( my_scoreString->GetRect().GetWidth() + 40, 220 );
    my_scoreNum->SetText( intToString(my_model->getScore()->getCurrent() ) );
    my_window->Draw( *my_scoreNum);
    
    //Objectif
    my_scoreString->SetText(  my_messages[my_language][goal] );
    my_scoreString->SetPosition( 20, 260 );
    my_window->Draw( *my_scoreString );
    
    my_scoreNum->SetPosition( my_scoreString->GetRect().GetWidth() + 40, 260 );
    my_scoreNum->SetText( intToString( my_model->getLevel()->getGoal() ) );
    my_window->Draw( *my_scoreNum);
    
    //En cours
    my_scoreString->SetText(  my_messages[my_language][step] );
    my_scoreString->SetPosition( 20, 300 );
    my_window->Draw( *my_scoreString );
    
    my_scoreNum->SetPosition( my_scoreString->GetRect().GetWidth() + 40, 300 );
    my_scoreNum->SetText( intToString( my_model->getLevel()->getCurrentMove() ) );
    my_window->Draw( *my_scoreNum);
    
    //La vie
    my_scoreString->SetText(  my_messages[my_language][life] );
    my_scoreString->SetPosition( 20, 340 );
    my_window->Draw( *my_scoreString );
    
    my_scoreNum->SetPosition( my_scoreString->GetRect().GetWidth() + 40, 340 );
    my_scoreNum->SetText( intToString( my_model->getLevel()->getDigger()->getLife() ) );
    my_window->Draw( *my_scoreNum);
    
    //Le temps
    my_scoreString->SetText(  my_messages[my_language][ltime] );
    my_scoreString->SetPosition( 20, 380 );
    my_window->Draw( *my_scoreString );
    
    my_scoreNum->SetPosition( my_scoreString->GetRect().GetWidth() + 40, 380 );
    my_scoreNum->SetText( intToString( my_model->getLevel()->leftTime() ) );
    my_window->Draw( *my_scoreNum);
    
    //La position
    my_scoreString->SetText(  my_messages[my_language][position] );
    my_scoreString->SetPosition( 20, 420 );
    my_window->Draw( *my_scoreString );
    
    my_scoreNum->SetPosition( my_scoreString->GetRect().GetWidth() + 40, 420 );
    my_scoreNum->SetText( "[ " + intToString( my_model->getLevel()->getDigger()->getX() ) + " ] [ " +  intToString( my_model->getLevel()->getDigger()->getY() )  + " ] " );
    my_window->Draw( *my_scoreNum);
    
}

void
GameView::showLevel() {
    my_window->Clear();
    my_window->Draw( *my_backgroundSprite );
    my_titleString->SetColor(Color(255,255,255));
    my_titleString->SetSize(60);
    my_titleString->SetText( " PURU PURU DIGGER " );
    my_titleString->SetPosition( ( WINDOWWITDH / 2 ) - ( my_titleString->GetRect().GetWidth() / 2 ) , 10 );
    my_window->Draw( *my_titleString );
    showGrid();
    showScore();

    
    my_buttonQuitSprite->SetPosition( QUITONX, QUITONY);
    my_window->Draw( *my_buttonQuitSprite );
    
    my_buttonString->SetText( my_messages[my_language][stop] );
    my_buttonString->SetPosition( ( ( ( QUITONX + BUTTONWIDTH ) / 2.5 )  ), (QUITONY + (BUTTONHEIGHT / 5)) );
    my_window->Draw( *my_buttonString );
}

void
GameView::showCGrid() {
#ifdef __linux__
    for ( int z = 0; z < (COLONNE * 6 + 3); z++ )
        cout << colorMessage( "-", YELLOW );
#elif __APPLE__
    for ( int z = 0; z < (COLONNE * 5 + 3); z++ )
        cout << colorMessage( "-", YELLOW );
#endif
    
    cout << endl;
    
    for ( int i = 0; i < LIGNE; i++ ) {
        cout << colorMessage( " | ", YELLOW );
        for ( int j = 0; j < COLONNE; j++ ) {
            cout << *my_model->getLevel()->getGrid()[i][j] << colorMessage( " | ", YELLOW );
        }
        cout << endl;
        
#ifdef __linux
        for ( int z = 0; z < (COLONNE * 6 + 3); z++ )
            cout << colorMessage( "-", YELLOW );
        cout << endl;
#else
        for ( int z = 0; z < (COLONNE * 5 + 3); z++ )
            cout << colorMessage( "-", YELLOW );
        cout << endl;
#endif
    }
}

void GameView::setModel(GameModel *model) {
    my_model = model;
}
                              
void
GameView::treatGame() {

    bool isInPresentation = true; //Pour savoir si il est sur le menu de départ
    bool isPlaying = false; // Pour savoir si il est sur le jeu
    bool isChoosingOption = false; //Pour savoir si il est le menu du choix des options
    //bool isInBestScore = false; //Pour savoir si il est sur le menu des meilleurs scores
    
    sf::Clock pause;        //La clock pour la pause
    bool isInBreak = false; //Pour savoir quand on est en pause
    
    // Boucle principale
    while (my_window->IsOpened())
    {
        //Gestion de tous les événements
        Event event;
        while (my_window->GetEvent(event)) // Boucle des évènements en attente
        {
            switch (event.Type) // Type de l'évènement
            {
                case Event::Closed : // Bouton de fermeture
                    my_window->Close();
                    break;
                case Event::MouseMoved :
                    if ( isInPresentation ) {
                        if ( event.MouseMove.X > PLAYX && event.MouseMove.X < PLAYX + BUTTONWIDTH && event.MouseMove.Y > PLAYY && event.MouseMove.Y < PLAYY + BUTTONHEIGHT )
                            
                            setButtonHover( my_playButtonSprite );
                        else if ( event.MouseMove.X > OPTIONX && event.MouseMove.X < OPTIONX + BUTTONWIDTH && event.MouseMove.Y > OPTIONY && event.MouseMove.Y < OPTIONY + BUTTONHEIGHT)
                            setButtonHover( my_optionButtonSprite );

                        else if (event.MouseMove.X > BESTX && event.MouseMove.X < BESTX + BUTTONWIDTH && event.MouseMove.Y > BESTY && event.MouseMove.Y < BESTY + BUTTONHEIGHT)
                            setButtonHover( my_bestButtonSprite );

                        else if (event.MouseMove.X > QUITX && event.MouseMove.X < QUITX + BUTTONWIDTH && event.MouseMove.Y > QUITY && event.MouseMove.Y < QUITY + BUTTONHEIGHT)
                            setButtonHover( my_quitButtonSprite );

                        else
                            resetButtonNorm();
                        
                    } else if ( isChoosingOption ) {
                        if ( event.MouseMove.X > ENGLISHX && event.MouseMove.X < ENGLISHX + LANGUEWIDTH && event.MouseMove.Y > CHOICELANGUEHIGH && event.MouseMove.Y < CHOICELANGUEHIGH + LANGUEHEIGHT )
                            setHoverLanguage( english );
                        else if ( event.MouseMove.X > FRENCHX && event.MouseMove.X < FRENCHX + LANGUEWIDTH && event.MouseMove.Y > CHOICELANGUEHIGH && event.MouseMove.Y < CHOICELANGUEHIGH + LANGUEHEIGHT )
                            setHoverLanguage( francais );
                        else if ( event.MouseMove.X > SPANISHX && event.MouseMove.X < SPANISHX + LANGUEWIDTH && event.MouseMove.Y > CHOICELANGUEHIGH && event.MouseMove.Y < CHOICELANGUEHIGH + LANGUEHEIGHT )
                            setHoverLanguage( espanol );
                        else if ( event.MouseMove.X > DEUTSCHX && event.MouseMove.X < DEUTSCHX + LANGUEWIDTH && event.MouseMove.Y > CHOICELANGUEHIGH && event.MouseMove.Y < CHOICELANGUEHIGH + LANGUEHEIGHT )
                            setHoverLanguage( deutsch );
                        else if ( event.MouseMove.X > ITALIANOX && event.MouseMove.X < ITALIANOX + LANGUEWIDTH && event.MouseMove.Y > CHOICELANGUEHIGH && event.MouseMove.Y < CHOICELANGUEHIGH + LANGUEHEIGHT )
                            setHoverLanguage( italiano );
                        else if ( event.MouseMove.X > QUITONX && event.MouseMove.X < QUITONX + BUTTONWIDTH && event.MouseMove.Y > QUITONY && event.MouseMove.Y < QUITONY + BUTTONHEIGHT )
                            setButtonHover(my_buttonQuitSprite);
                        else {
                            resetButtonNorm();
                            resetLanguageNorm();
                        }
                    } else if ( isPlaying  ) {
                        if ( event.MouseMove.X > QUITONX && event.MouseMove.X < QUITONX + BUTTONWIDTH && event.MouseMove.Y > QUITONY && event.MouseMove.Y < QUITONY + BUTTONHEIGHT )
                            
                            setButtonHover(my_buttonQuitSprite);
                        else
                            resetButtonNorm();
                    }
                    break;
                case Event::KeyPressed : // Appui sur une touche du clavier
                {
                    switch (event.Key.Code) // La touche qui a été appuyée
                    {
                        case Key::Escape : // Echap
                            my_window->Close();
                            break;
                        case Key::Right :
                            if ( !isInBreak )
                                my_model->orderMovement(6);
                            break;
                        case Key::Up:
                            if ( !isInBreak )
                                my_model->orderMovement(8);
                            break;
                        case Key::Left :
                            if ( !isInBreak )
                                my_model->orderMovement(4);
                            break;
                        case Key::Down:
                            if ( !isInBreak )
                                my_model->orderMovement(2);
                            break;
                        default :
                            break;
                    }
                }
                    break;
                case Event::MouseButtonPressed :
                    if ( isInPresentation ) {
                        if ( event.MouseButton.X > PLAYX && event.MouseButton.X < PLAYX + BUTTONWIDTH && event.MouseButton.Y > PLAYY && event.MouseButton.Y < PLAYY + BUTTONHEIGHT ) {
                            my_model->getLevel()->reset();
                            my_model->getLevel()->getDigger()->resetLife();
                            isInPresentation = false;
                            isPlaying = true;
                            my_musicLevel->Play();
                            
                        } else if ( event.MouseButton.X > QUITX && event.MouseButton.X < QUITX + BUTTONWIDTH && event.MouseButton.Y > QUITY && event.MouseButton.Y < QUITY + BUTTONHEIGHT ) {
                            my_window->Close();
                            
                        } else if ( event.MouseButton.X > OPTIONX && event.MouseButton.X < OPTIONX + BUTTONWIDTH && event.MouseButton.Y > OPTIONY && event.MouseButton.Y < OPTIONY + BUTTONHEIGHT ) {
                            isInPresentation = false;
                            isChoosingOption = true;
                        }
                    } else if ( isChoosingOption ) {
                        
                        if ( event.MouseButton.X > ENGLISHX && event.MouseButton.X < ENGLISHX + LANGUEWIDTH && event.MouseButton.Y > CHOICELANGUEHIGH && event.MouseButton.Y < CHOICELANGUEHIGH+ LANGUEHEIGHT )
                            my_language = english;
                        if ( event.MouseButton.X > FRENCHX && event.MouseButton.X < FRENCHX + LANGUEWIDTH && event.MouseButton.Y > CHOICELANGUEHIGH && event.MouseButton.Y < CHOICELANGUEHIGH + LANGUEHEIGHT )
                            my_language = francais;
                        if ( event.MouseButton.X > ITALIANOX && event.MouseButton.X < ITALIANOX + LANGUEWIDTH && event.MouseButton.Y > CHOICELANGUEHIGH && event.MouseButton.Y < CHOICELANGUEHIGH + LANGUEHEIGHT )
                            my_language = italiano;
                        if ( event.MouseButton.X > SPANISHX && event.MouseButton.X < SPANISHX + LANGUEWIDTH && event.MouseButton.Y > CHOICELANGUEHIGH && event.MouseButton.Y < CHOICELANGUEHIGH + LANGUEHEIGHT )
                            my_language = espanol;
                        if ( event.MouseButton.X > DEUTSCHX && event.MouseButton.X < DEUTSCHX + LANGUEWIDTH && event.MouseButton.Y > CHOICELANGUEHIGH && event.MouseButton.Y < CHOICELANGUEHIGH + LANGUEHEIGHT )
                            my_language = deutsch;
                        if ( event.MouseButton.X > CHOICEANANASX && event.MouseButton.X < CHOICEANANASX + SPRITECHOICEWIDTH && event.MouseButton.Y > CHOICESPRITEY && event.MouseButton.Y < CHOICESPRITEY + SPRITECHOICEHEIGHT )
                            setAnanasMode();
                        if ( event.MouseButton.X > CHOICETEACHERX && event.MouseButton.X < CHOICETEACHERX + SPRITECHOICEWIDTH && event.MouseButton.Y > CHOICESPRITEY && event.MouseButton.Y < CHOICESPRITEY + SPRITECHOICEHEIGHT )
                            setTeacherMode();
                        if ( event.MouseButton.X > QUITONX && event.MouseButton.X < QUITONX + BUTTONWIDTH && event.MouseButton.Y > QUITONY && event.MouseButton.Y < QUITONY + BUTTONHEIGHT ) {
                            isChoosingOption = false;
                            isInPresentation = true;
                        }
                        
                    } else if ( isPlaying ) {
                        cout << " Souris case : " << convertYPixel(event.MouseButton.Y) << " " << convertXPixel(event.MouseButton.X) <<  " "  << endl;
                        if ( event.MouseButton.X > QUITONX && event.MouseButton.X < QUITONX + BUTTONWIDTH && event.MouseButton.Y > QUITONY && event.MouseButton.Y < QUITONY + BUTTONHEIGHT ) {
                            isPlaying = false;
                            isInPresentation = true;
                            my_musicLevel->Stop();
                        }
                    }
                    break;
                    
                default :
                    break;
            }
        }
        
        
        //Gestion de tout l'affichage
        if ( isInPresentation ) {
            showPresentation();
        } else if ( isChoosingOption ) {
            showOption();
        } else if ( isPlaying ) {
            if ( my_model->getLevel()->lose() ) {
                if ( !isInBreak )
                    pause.Reset();
                showLoseLevel();
                isInBreak = true;
                
            } else if ( my_model->getLevel()->win()  ) {
                if ( !isInBreak )
                    pause.Reset();
                showWinLevel();
                isInBreak = true;
            } else {
                showLevel();
            }
        }
        
        // Affichage du contenu de la fenêtre à l'écran
        my_window->Display();
        
        //Pour gérer l'affichage durant quelque seconde
        if ( my_model->getLevel()->lose() || my_model->getLevel()->win() ) {
            if ( pause.GetElapsedTime() > 1.5 ) {
                my_model->getLevel()->resetLose();
                my_model->getLevel()->resetWin();
                my_model->getLevel()->resetTime();
                isInBreak = false;
                pause.Reset();
            }
        }
    }
}