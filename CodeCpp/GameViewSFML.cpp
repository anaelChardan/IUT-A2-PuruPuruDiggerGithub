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
     my_window = new RenderWindow( VideoMode(WINDOWWITDH, WINDOWHEIGHT, BPP), "PuruPuruDigger", sf::Style::Close  );
     my_window->SetFramerateLimit(60);
 
     my_language = francais;
     //La font pour les scores
     my_fontScore = new Font();
     my_fontTitle = new Font();
     my_fontValue = new Font();
     
     my_valueString = new String();
     my_scoreString = new String();
     my_titleString = new String();
 
     my_backgroundImage = new Image();
 
     my_caseImage = new Image();
     
     my_caseImage->CreateMaskFromColor( Color(196, 115, 116 ) );
     
     //On set les sprites
     my_diggerSprite = new Sprite();
     my_valueSprite = new Sprite();
     my_goldSprite = new Sprite();
     my_bombSprite = new Sprite();
     my_backgroundSprite = new Sprite();
     my_emptySprite = new Sprite();
 
     //Si les deux images ou les sprites n'ont pas encore réussies à charger
     if (!my_backgroundImage->LoadFromFile("wallpapper.png") || !my_caseImage->LoadFromFile("case.png") || !my_fontScore->LoadFromFile("scoreFont.ttf") || !my_fontTitle->LoadFromFile("titleFont.ttf") || !my_fontValue->LoadFromFile("valueFont.ttf") ) {
         cout << "Error when loading image or font" << endl;
     } else {
         //On set les sprites de nos images
         my_backgroundSprite->SetImage( *my_backgroundImage );
         my_backgroundSprite->Resize( WINDOWWITDH, WINDOWHEIGHT );
         
         my_diggerSprite->SetImage( *my_caseImage );
         my_diggerSprite->SetSubRect( IntRect( DIGGERSX, 6, DIGGEREX, SPRITECASEHEIGHT ) );
         my_diggerSprite->Resize( CASEWITDH, CASEHEIGHT );
         
         my_valueSprite->SetImage( *my_caseImage );
         my_valueSprite->SetSubRect( IntRect(VALUESX, 6, VALUEEX, SPRITECASEHEIGHT ) );
         my_valueSprite->Resize( CASEWITDH, CASEHEIGHT );
         
         
         my_goldSprite->SetImage( *my_caseImage );
         my_goldSprite->SetSubRect( IntRect(GOLDSX, 6, GOLDEX, SPRITECASEHEIGHT ) );
         my_goldSprite->Resize( CASEWITDH, CASEHEIGHT );
         
         my_bombSprite->SetImage( *my_caseImage );
         my_bombSprite->SetSubRect( IntRect( BOMBSX, 6, BOMBEX, SPRITECASEHEIGHT ) );
         my_bombSprite->Resize( CASEWITDH, CASEHEIGHT );
         
         my_emptySprite->SetImage( *my_caseImage );
         my_emptySprite->SetSubRect( IntRect( EMPTYSX, 6, EMPTYEX, SPRITECASEHEIGHT ) );
         my_emptySprite->Resize( CASEWITDH, CASEHEIGHT );
         
         //Les affichages de valeurs seront toujours identiques, du coup on les set direct
         my_valueString->SetFont( *my_fontValue );
         my_valueString->SetColor(Color(255,255,255) );
         my_valueString->SetSize(20);
         
         my_scoreString->SetFont( *my_fontScore );
         my_titleString->SetFont( *my_fontTitle );
     }
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

void
GameView::showGrid() {
    my_window->Clear();
    my_window->Draw(*my_backgroundSprite);
    for ( int i = 0; i < LIGNE ; i++ ) {
        for ( int j = 0; j < COLONNE; j++ ) {
            if ( my_model->getLevel()->getGrid()[i][j]->getType() == "Digger" ) {
                my_diggerSprite->SetPosition( convertIndiceXToPixel( j ), convertIndiceYToPixel( i ) );
                my_window->Draw( *my_diggerSprite);
            } else if ( my_model->getLevel()->getGrid()[i][j]->getType() == "Bomb" ) {
                my_bombSprite->SetPosition( convertIndiceXToPixel( j ), convertIndiceYToPixel( i ) );
                my_window->Draw( *my_bombSprite );
            } else if ( my_model->getLevel()->getGrid()[i][j]->getType() == "EmptyCell") {
                my_emptySprite->SetPosition( convertIndiceXToPixel( j ), convertIndiceYToPixel( i ) );
                my_window->Draw( *my_emptySprite );
            } else if ( my_model->getLevel()->getGrid()[i][j]->getType() == "ValueCell" ) {
                my_valueSprite->SetPosition( convertIndiceXToPixel( j ), convertIndiceYToPixel( i ) );
                my_window->Draw( *my_valueSprite );
               
                my_valueString->SetText( my_model->getLevel()->getGrid()[i][j]->getStringValue() );
                my_valueString->SetPosition( ( convertIndiceXToPixel( j ) + CASEWITDH / 3 ), ( convertIndiceYToPixel( i ) + CASEHEIGHT / 6 ) );
               my_window->Draw( *my_valueString );
            } else if ( my_model->getLevel()->getGrid()[i][j]->getType() == "GoldCell" ) {
                my_goldSprite->SetPosition( convertIndiceXToPixel( j ), convertIndiceYToPixel( i ) );
                my_window->Draw( *my_goldSprite );
                
                my_valueString->SetText( my_model->getLevel()->getGrid()[i][j]->getStringValue() );
                my_valueString->SetPosition( ( convertIndiceXToPixel( j ) + CASEWITDH / 3 ),  ( convertIndiceYToPixel( i ) + CASEHEIGHT / 6 ) );
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
    my_model->getLevel()->resetLose();
    my_window->Display(); //Provisoirement
    Sleep(5);
    my_model->getLevel()->resetTime();
}
void
GameView::showScore() {
    my_scoreString->SetSize(40);
    my_scoreString->SetStyle(String::Underlined | String::Bold | String::Italic );
    my_scoreString->SetColor(Color(50,50,150));
    my_scoreString->SetPosition(100, 80);
    my_scoreString->SetText(  my_messages[my_language][score] + " : " );
    my_window->Draw( *my_scoreString );
    
    //Level et son num
    my_scoreString->SetColor(Color(251,210,98));
    my_scoreString->SetSize(30);
    my_scoreString->SetStyle(String::Regular);
    my_scoreString->SetText(  my_messages[my_language][level] );
    my_scoreString->SetPosition( 20, 140 );
    my_window->Draw( *my_scoreString );
    
    my_scoreString->SetColor(Color(251,100,100));
    my_scoreString->SetPosition( my_scoreString->GetRect().GetWidth() + 40, 140 );
    my_scoreString->SetText( intToString(my_model->getScore()->getCurrentStep() ) );
    my_window->Draw( *my_scoreString);
    
    //Score Total
    my_scoreString->SetColor(Color(251,210,98));
    my_scoreString->SetText(  my_messages[my_language][global] );
    my_scoreString->SetPosition( 20, 180 );
    my_window->Draw( *my_scoreString );
    
    my_scoreString->SetPosition( my_scoreString->GetRect().GetWidth() + 40, 180 );
    my_scoreString->SetText( intToString(my_model->getScore()->getGlobale() ) );
    my_window->Draw( *my_scoreString);
    
    //Score en cours
    my_scoreString->SetColor(Color(251,210,98));
    my_scoreString->SetText(  my_messages[my_language][current] );
    my_scoreString->SetPosition( 20, 220 );
    my_window->Draw( *my_scoreString );
    
    my_scoreString->SetPosition( my_scoreString->GetRect().GetWidth() + 40, 220 );
    my_scoreString->SetText( intToString(my_model->getScore()->getCurrent() ) );
    my_window->Draw( *my_scoreString);
    
    //Objectif
    my_scoreString->SetColor(Color(251,210,98));
    my_scoreString->SetText(  my_messages[my_language][goal] );
    my_scoreString->SetPosition( 20, 260 );
    my_window->Draw( *my_scoreString );
    
    my_scoreString->SetPosition( my_scoreString->GetRect().GetWidth() + 40, 260 );
    my_scoreString->SetText( intToString( my_model->getLevel()->getGoal() ) );
    my_window->Draw( *my_scoreString);
    
    //En cours
    my_scoreString->SetColor(Color(251,210,98));
    my_scoreString->SetText(  my_messages[my_language][step] );
    my_scoreString->SetPosition( 20, 300 );
    my_window->Draw( *my_scoreString );
    
    my_scoreString->SetPosition( my_scoreString->GetRect().GetWidth() + 40, 300 );
    my_scoreString->SetText( intToString( my_model->getLevel()->getCurrentMove() ) );
    my_window->Draw( *my_scoreString);
    
    //La vie
    my_scoreString->SetColor(Color(251,210,98));
    my_scoreString->SetText(  my_messages[my_language][life] );
    my_scoreString->SetPosition( 20, 340 );
    my_window->Draw( *my_scoreString );
    
    my_scoreString->SetPosition( my_scoreString->GetRect().GetWidth() + 40, 340 );
    my_scoreString->SetText( intToString( my_model->getLevel()->getDigger()->getLife() ) );
    my_window->Draw( *my_scoreString);
    
    //Le temps
    my_scoreString->SetColor(Color(251,210,98));
    my_scoreString->SetText(  my_messages[my_language][ltime] );
    my_scoreString->SetPosition( 20, 380 );
    my_window->Draw( *my_scoreString );
    
    my_scoreString->SetPosition( my_scoreString->GetRect().GetWidth() + 40, 380 );
    my_scoreString->SetText( intToString( my_model->getLevel()->leftTime() ) );
    my_window->Draw( *my_scoreString);
    
    //La position
    my_scoreString->SetColor(Color(251,210,98));
    my_scoreString->SetText(  my_messages[my_language][position] );
    my_scoreString->SetPosition( 20, 420 );
    my_window->Draw( *my_scoreString );
    
    my_scoreString->SetPosition( my_scoreString->GetRect().GetWidth() + 40, 420 );
    my_scoreString->SetText( "[ " + intToString( my_model->getLevel()->getDigger()->getX() ) + " ] [ " +  intToString( my_model->getLevel()->getDigger()->getY() )  + " ] " );
    my_window->Draw( *my_scoreString);
    
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

    cout << my_model->getLevel()->getDigger()->getX() << endl;
    showCGrid();

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
                case Event::KeyPressed : // Appui sur une touche du clavier
                {
                    switch (event.Key.Code) // La touche qui a été appuyée
                    {
                        case Key::Escape : // Echap
                            my_window->Close();
                            break;
                        case Key::Right :
                            my_model->orderMovement(6);
                            
                            break;
                        case Key::Up:
                            my_model->orderMovement(8);
                            showCGrid();
                            break;
                        case Key::Left :
                            my_model->orderMovement(4);
                            showCGrid();
                            break;
                        case Key::Down:
                            my_model->orderMovement(2);
                            showCGrid();
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
            showLoseLevel();
        } else {
            showGrid();
            showScore();
        }
        // Affichage du contenu de la fenêtre à l'écran
        my_window->Display();
    }
}