//
//  GameViewSFML.cpp
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 12/03/2014.
//
//

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
     
     //On set les sprites
     my_diggerSprite = new Sprite();
     my_valueSprite = new Sprite();
     my_goldSprite = new Sprite();
     my_bombSprite = new Sprite();
     my_backgroundSprite = new Sprite();
     my_emptySprite = new Sprite();
 
     setTeacherMode();
     
     //On set les sprites de nos images
     my_backgroundSprite->SetImage( *my_backgroundImage );
     my_backgroundSprite->Resize( WINDOWWITDH, WINDOWHEIGHT );
     
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
     
     my_stringToSprite["Digger"] = *my_diggerSprite;
     my_stringToSprite["EmptyCell"] = *my_emptySprite;
     my_stringToSprite["GoldCell"] = *my_goldSprite;
     my_stringToSprite["Bomb"] = *my_bombSprite;
     my_stringToSprite["ValueCell" ] = *my_valueSprite;
          
        /*
          
          my_frenchSprite->setImage( *my_languageImage );
          my_frenchSprite->setSubRect( IntRect( FRENCHSX, ..., FRENCHEX, SPRITELANGUAGEHEIGHT );
         
          my_deutschSprite->setImage( *my_languageImage );
          my_frenchSprite->setSubRect( IntRect( FRENCHSX, ..., FRENCHEX, SPRITELANGUAGEHEIGHT );
         
          my_spanishSprite->setImage( *my_languageImage );
          my_frenchSprite->setSubRect( IntRect( FRENCHSX, ..., FRENCHEX, SPRITELANGUAGEHEIGHT );
         
          my_italianoSprite->setImage( *my_languageImage );
          my_frenchSprite->setSubRect( IntRect( FRENCHSX, ..., FRENCHEX, SPRITELANGUAGEHEIGHT );
         
          my_englishSprite->setImage( *my_languageImage );
          my_frenchSprite->setSubRect( IntRect( FRENCHSX, ..., FRENCHEX, SPRITELANGUAGEHEIGHT );
          
          
          */
         
         
         
        //my_languageSprite->SetImage(*my_languageImage);
     

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

void GameView::setAnanasMode() {
    //Si les deux images ou les sprites n'ont pas encore réussies à charger
    if (!my_backgroundImage->LoadFromFile("wallpapper.png") || !my_caseImage->LoadFromFile("case.png") || !my_fontScore->LoadFromFile("scoreFont.ttf") || !my_fontTitle->LoadFromFile("titleFont.ttf") || !my_fontValue->LoadFromFile("valueFont.ttf") ) {
        cout << "Error when loading image or font" << endl;
    } else {
    
        //Les affichages de valeurs seront toujours identiques, du coup on les set direct
        my_valueString->SetFont( *my_fontValue );
        my_valueString->SetColor(Color(255,255,255) );
        my_valueString->SetSize(20);
        
        my_titleScoreString->SetFont( *my_fontScore );
        my_titleScoreString->SetSize(40);
        my_titleScoreString->SetStyle(String::Underlined | String::Bold | String::Italic );
        my_titleScoreString->SetColor(Color(50,50,150));
        
        my_scoreString->SetFont( *my_fontScore );
        my_scoreString->SetColor(Color(251,210,98));
        my_scoreString->SetStyle(String::Underlined);
        
        my_scoreNum->SetFont( * my_fontScore );
        my_scoreNum->SetColor(Color(255,100,100));
        
        my_titleScoreString->SetFont( *my_fontScore );
        my_scoreString->SetSize(30);
        my_titleString->SetFont( *my_fontTitle );
        
        my_languageImage->CreateMaskFromColor(Color(234,20,140));
        my_caseImage->CreateMaskFromColor( Color(0, 55, 97) );
    }
}

void
GameView::setTeacherMode() {
    //Si les deux images ou les sprites n'ont pas encore réussies à charger
    if (!my_backgroundImage->LoadFromFile("wallpapperTeach.png") || !my_caseImage->LoadFromFile("caseTeach.png") || !my_fontScore->LoadFromFile("arial.ttf") || !my_fontTitle->LoadFromFile("arial.ttf") || !my_fontValue->LoadFromFile("arial.ttf") ) {
        cout << "Error when loading image or font" << endl;
    } else {
        
        //Les affichages de valeurs seront toujours identiques, du coup on les set direct
        my_titleString->SetFont( *my_fontTitle );
        
        my_valueString->SetFont( *my_fontValue );
        my_valueString->SetColor(Color(0,0,0) );
        my_valueString->SetSize(20);
        my_valueString->SetStyle( String::Bold );
        
        my_titleScoreString->SetFont( *my_fontScore );
        my_titleScoreString->SetSize(40);
        my_titleScoreString->SetStyle(String::Underlined | String::Bold | String::Italic );
        my_titleScoreString->SetColor(Color(255,255,255));
        
        my_scoreString->SetSize(30);
        my_scoreString->SetFont( *my_fontScore );
        my_scoreString->SetColor(Color(255, 255,255));
        my_scoreString->SetStyle(String::Underlined);
        
        my_scoreNum->SetFont( * my_fontScore );
        my_scoreNum->SetColor(Color(255,255,255));
        
        my_languageImage->CreateMaskFromColor(Color(234,20,140));
        my_caseImage->CreateMaskFromColor( Color(0, 55, 97) );
    }
}

void
GameView::showPresentation() {
    my_window->Clear();
    my_window->Draw(*my_backgroundSprite);
    showButton();
}

void
GameView::showButton() {
    
}


void
GameView::showOption() {
    my_window->Clear();
    showSpriteChoice();
    showLanguage();
}


void
GameView::showLanguage() {

}


void
GameView::showSpriteChoice() {
}



void
GameView::showGrid() {
    my_window->Clear();
    my_window->Draw(*my_backgroundSprite);
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
    showGrid();
    showScore();
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

    //bool isInPresentation = true;
    //bool isPlaying = false;
    //bool isChoosingOption = false;
    //bool isInBestScore = false;
    sf::Clock pause;
    bool isInBreak = false;
    
    // Boucle principale
    while (my_window->IsOpened())
    {
        Event event;
        while (my_window->GetEvent(event)) // Boucle des évènements en attente
        {
            switch (event.Type) // Type de l'évènement
            {
                case Event::Closed : // Bouton de fermeture
                    my_window->Close();
                    break;
                case Event::MouseMoved :
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
                    cout << " Souris case : " << convertYPixel(event.MouseButton.Y) << " " << convertXPixel(event.MouseButton.X) <<  " "  << endl;
                    break;
                    
                default :
                    break;
            }
        }
        
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