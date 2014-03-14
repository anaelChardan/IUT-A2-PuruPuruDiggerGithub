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
 GameView::GameView(int w, int h, int bpp): _w(w), _h(h) {
     //Le style de la fenêtres
     my_window = new RenderWindow(sf::VideoMode(w, h, bpp), "PuruPuruDigger", sf::Style::Close);
 
     //La font pour les scores
     my_fontScore=  new Font();
     my_fontTitle = new Font();
     
     my_valueString = new String();
     my_scoreString = new String();
     my_titleString = new String();
 
     my_backgroundImage = new Image();
 
     my_caseImage = new Image();
     
     my_caseImage->CreateMaskFromColor(Color(r, g, b ) );
     
     //On affecte les sprite, je décide de ne pas faire de classe GraphicElement, que je n'ai pas forcément bien compris...
 
     my_DiggerSprite = new Sprite();
     my_ValueSprite = new Sprite();
     my_GoldSprite = new Sprite();
     my_BombSprite = new Sprite();
     
     //On affecte les sprites de fond
     my_backgroundSprite = new Sprite();
 
     //On charge la font pour les scores
     my_fontScore->LoadFromFile("Font/scoreFont.ttf");
 
 
     //On charge la font pour le titre du jeu
     my_fontTitle->LoadFromFile( "Font/titleFont.ttf" );
     my_fontValue->LoadFromFile("Font/valueFont.ttf" );
 
     //Si les deux images n'ont pas encore réussies à charger
     if (!my_backgroundImage->LoadFromFile("Image/background.png") || !my_caseImage->LoadFromFile("Image/case.png") {
        cout << "Error when loading image" << endl;
         RETURN EXIT_SUCCESS;
     } else {
         //On set les sprites de nos images
         my_diggerSprite->SetImage(my_caseImage);
         my_valueSprite->SetImage(my_caseImage);
         my_goldSprite->SetImage(my_caseImage);
         my_bombSprite->SetImage(my_caseImage);
         my_emptySprite->SetImage(my_caseImage)
     }
 
    //On set les font pour pouvoir afficher plus facilement ensuite
    my_valueString->SetFont(*my_fontValue);
    my_scoreString->SetFont(*my_fontScore);
    my_titleString->SetFont(*my_titleString);
    //On set les rectangles de lecture de chacune de nos cases !
    my_DiggerSprite->SetSubRect(IntRect(DIGGERSX,0,DIGGEREX,SPRITECASEHEIGHT);
    my_ValueSprite->SetSubRect(IntRect(VALUESX, 0, VALUEEX, SPRITECASEHEIGHT);
    my_GoldSprite->SetSubRect(IntRect(GOLDSX, 0, GOLDEX, SPRITECASEHEIGHT);
    my_

                            
}
  
void showGrid() {
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
                my_valueString->SetPosition( convertIndiceXToPixel( i ) , convertIndiceYToPixel( j ) / 2 );
                my_window->Draw( my_valueString );
            }
        }
    }
}
                              
void
GameView::treatGame() {
    while ( my_window->IsOpened ) {
        Event event;
        while ( my_window->GetEvent( event ) ) {
            
        }
        app.Display;
    }
}