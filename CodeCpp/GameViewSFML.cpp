//
//  GameViewSFML.cpp
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 12/03/2014.
//
//

#include "GameViewSFML.h"
#include "Constantes.h"

using namespace std;
using namespace sf;

//Building in progress
int convertIndiceXToPixel( int i ) {
    return CASEWITDH * i + MARGINLEFT + PADDINGRIGHT * i ;
}

int convertIndiceYToPixel ( int j ) {
    return CASEHEIGHT * j + MARGINTOP + PADDINGBOTTOM * j ;
}


//Début de l'écriture des fonctions pour la SFML
 GameView::GameView(): {
     //Le style de la fenêtres
     my_window = new RenderWindow( VideoMode(WINDOWWITDH, WINDOWHEIGHT, BPP), "PuruPuruDigger", sf::Style::Close );
 
     //La font pour les scores
     my_fontScore=  new Font();
     my_fontTitle = new Font();
     
     my_valueString = new String();
     my_scoreString = new String();
     my_titleString = new String();
 
     my_backgroundImage = new Image();
 
     my_caseImage = new Image();
     
     my_caseImage->CreateMaskFromColor( Color(r, g, b ) );
     
     //On set les sprites
     my_DiggerSprite = new Sprite();
     my_ValueSprite = new Sprite();
     my_GoldSprite = new Sprite();
     my_BombSprite = new Sprite();
     my_backgroundSprite = new Sprite();
 
     //Si les deux images ou les sprites n'ont pas encore réussies à charger
     if (!my_backgroundImage->LoadFromFile("Image/background.png") || !my_caseImage->LoadFromFile("Image/case.png" || !my_fontScore->LoadFromFile( "Font/scoreFont.ttf" ) || my_fontTitle->LoadFromFile( "Font/titleFont.ttf" ) || my_fontValue->LoadFromFile( "Font/valueFont.ttf" ) ) {
        cout << "Error when loading image or font" << endl;
         RETURN EXIT_SUCCESS;
     } else {
         //On set les sprites de nos images
         my_backgroundSprite->SetImage( *my_backgroundImage );
         my_backgroundSprite->Resize( WINDOWWITDH, WINDOWHEIGHT );
         
         my_diggerSprite->SetImage( *my_caseImage );
         my_diggerSprite->SetSubRect( IntRect( DIGGERSX, 0, DIGGEREX, SPRITECASEHEIGHT ) );
         my_diggerSprite->Resize( CASEWITDH, CASEHEIGHT );
         
         my_valueSprite->SetImage( *my_caseImage );
         my_valueSprite->SetSubRect( IntRect(VALUESX, 0, VALUEEX, SPRITECASEHEIGHT ) );
         my_valueSprite->Resize( CASEWITDH, CASEHEIGHT );
         
         
         my_goldSprite->SetImage( *my_caseImage );
         my_goldSprite->SetSubRect( IntRect(GOLDSX, 0, GOLDEX, SPRITECASEHEIGHT ) );
         my_goldSprite->Resize( CASEWITDH, CASEHEIGHT );
         
         my_bombSprite->SetImage( *my_caseImage );
         my_bombSprite->SetSubRect( IntRect( BOMBSX, 0, BOMBEX, SPRITECASEHEIGHT ) )
         my_bombSprite->Resize( CASEWITDH, CASEHEIGHT );
         
         my_emptySprite->SetImage( *my_caseImage );
         my_emptySprite->SetSubRect( IntRect( EMPTYSX, 0, EMPTYEX, SPRITECASEHEIGHT ) )
         my_emptySprite->Resize( CASEWITDH, CASEHEIGHT );
         
         //Les affichages de valeurs seront toujours identiques, du coup on les set direct
         my_valueString->SetFont( *my_fontValue );
         my_valueString->SetColor(Color(255,255,255) );
         my_valueString->SetSize(20);
         
         my_scoreString->SetFont( *my_fontScore );
         my_titleString->SetFont( *my_titleString );
     }
}
  
void
GameView::showGrid() {
    my_window->Clear();
    for ( int i = 0; i < LIGNE ; i++ ) {
        for ( int j = 0; j < COLONNE; j++ ) {
            if ( *my_model->getLevel()->getGrid()[i][j]->getType() == "Digger" ) {
                my_diggerSprite->SetPosition( convertIndiceXToPixel( i ), convertIndiceYToPixel( j ) );
                my_window->Draw(my_diggerSprite);
            } else if ( *my_model->getLevel()->getGrid()[i][j]->getType() == "Bomb" ) {
                my_bombSprite->SetPosition( convertIndiceXToPixel( i ), convertIndiceYToPixel( j ) );
                my_window->Draw( my_bombSprite );
            } else if ( *my_model->getLevel()->getGrid()[i][j]->getType() == "EmptyCell") {
                my_emptySprite->SetPosition( convertIndiceXToPixel( i ), convertIndiceYToPixel( j ) );
                my_window->Draw( my_emptySprite );
            } else if ( *my_model->getLevel()->getGrid()[i][j]->getType() == "ValueCell" ) {
                my_valueSprite->SetPosition( convertIndiceXToPixel( i ), convertIndiceYToPixel( j ) );
                my_window->Draw( my_valueSprite );
               
                my_valueString->SetText( *my_model->getLevel()->getGrid()[i][j]->getStringValue() );
                my_valueString->SetPosition( ( convertIndiceXToPixel( i ) + CASEWITDH / 2 ), ( convertIndiceYToPixel( j ) + CASEHEIGHT / 4 ) );
                my_window->Draw( my_valueString );
            } else if ( *my_model->getLevel()->getGrid()[i][j]->getType() == "GoldCell" ) {
                my_goldSprite->SetPosition( convertIndiceXToPixel( i ), convertIndiceYToPixel( j ) );
                my_window->Draw( my_goldSprite );
                
                my_valueString->SetText( *my_model->getLevel()->getGrid()[i][j]->getStringValue() );
                my_valueString->SetPosition( ( convertIndiceXToPixel( i ) + CASEWIDTH / 2  ),  ( convertIndiceYToPixel( j ) + CASEHEIGHT / 4 ) );
                my_window->Draw( my_valueString );
            }
        }
    }
}
                              
void
GameView::treatGame() {
    while ( my_window->IsOpened ) {
        showGrid();
        app.Display;
    }
}