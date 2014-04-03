#include "GameViewSFML.h"
#include "Constantes.h"
#include "IntDecFunctor.h"
#include <sstream>
#include <fstream>
#include "Utils.h"

using namespace std;
using namespace sf;


//Constructeur
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

    //Les images
     my_backgroundImage = new Image();
     my_languageImage = new Image();
     my_caseImage = new Image();
     my_buttonImage = new Image();
     my_spriteImage = new Image();
     my_iconImage = new Image();

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

     //Les icones
     my_musicIcon = new Sprite();
     my_soundIcon = new Sprite();

     my_musicLevel = new Music();

     //Chargement des images selon le mode
     setAnanasMode();
}

//Destructeur
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

//Attribut une image à un sprite, avec rectangle de lecture et redimensionnement
void
GameView::setSprite( sf::Sprite* s, sf::Image* i, int subsX, int subsY, int subeX, int subeY, int w, int h ) {
    s->SetImage( *i );
    s->SetSubRect( IntRect ( subsX, subsY, subeX, subeY ) );
    s->Resize( w, h);
}

//Attribut chaque image à un sprite
void
GameView::setImageToSprite() {

    my_languageImage->CreateMaskFromColor(Color(0, 55, 97));
    my_caseImage->CreateMaskFromColor( Color(0, 55, 97) );
    my_buttonImage->CreateMaskFromColor( Color(0, 55, 97) );
    my_spriteImage->CreateMaskFromColor( Color(0, 55, 97) );

    my_iconImage->CreateMaskFromColor( Color(0, 55, 97) );
    //On set les sprites de nos images
    setSprite( my_backgroundSprite, my_backgroundImage, 0, 0, WINDOWWITDH, WINDOWHEIGHT, WINDOWWITDH, WINDOWHEIGHT );

    //On set les choix des sprites

    setSprite( my_ananasSprite, my_spriteImage, SPRITEANANASSX, SPRITECHOICEBEGIN, SPRITEANANASEX,SPRITECHOICEHEIGHT, SPRITECHOICEWIDTH,  SPRITECHOICEHEIGHT );
    my_ananasSprite->SetPosition( CHOICEANANASX, CHOICESPRITEY);

    setSprite( my_teacherSprite ,my_spriteImage , SPRITETEACHERSX, SPRITECHOICEBEGIN, SPRITETEACHEREX, SPRITECHOICEHEIGHT, SPRITECHOICEWIDTH, SPRITECHOICEHEIGHT );
    my_teacherSprite->SetPosition( CHOICETEACHERX, CHOICESPRITEY);

    //Mise en places des sprites case
    setSprite( my_diggerSprite, my_caseImage , DIGGERSX, SPRITECASEBEGIN, DIGGEREX, SPRITECASEHEIGHT, CASEWITDH, CASEHEIGHT );

    setSprite( my_valueSprite, my_caseImage, VALUESX, SPRITECASEBEGIN, VALUEEX, SPRITECASEHEIGHT,CASEWITDH, CASEHEIGHT );

    setSprite( my_goldSprite, my_caseImage, GOLDSX, SPRITECASEBEGIN, GOLDEX, SPRITECASEHEIGHT,CASEWITDH, CASEHEIGHT );

    setSprite( my_bombSprite, my_caseImage, BOMBSX, SPRITECASEBEGIN, BOMBEX, SPRITECASEHEIGHT,CASEWITDH, CASEHEIGHT );

    setSprite( my_emptySprite, my_caseImage, EMPTYSX, SPRITECASEBEGIN, EMPTYEX, SPRITECASEHEIGHT,CASEWITDH, CASEHEIGHT );

    my_stringToSprite["Digger"] = my_diggerSprite;
    my_stringToSprite["EmptyCell"] = my_emptySprite;
    my_stringToSprite["GoldCell"] = my_goldSprite;
    my_stringToSprite["Bomb"] = my_bombSprite;
    my_stringToSprite["ValueCell" ] = my_valueSprite;

    //On set les boutons
    setSprite( my_buttonQuitSprite, my_buttonImage, BUTTONNORMSX, BUTTONCASEBEGIN, BUTTONNORMEX, BUTTONCASEHEIGHT, BUTTONWIDTH, BUTTONHEIGHT);
    my_buttonQuitSprite->SetPosition( QUITONX, QUITONY);

    setSprite( my_playButtonSprite, my_buttonImage, BUTTONNORMSX, BUTTONCASEBEGIN, BUTTONNORMEX, BUTTONCASEHEIGHT, BUTTONWIDTH, BUTTONHEIGHT );
    my_playButtonSprite->SetPosition( PLAYX, PLAYY );

    setSprite( my_optionButtonSprite, my_buttonImage, BUTTONNORMSX, BUTTONCASEBEGIN, BUTTONNORMEX, BUTTONCASEHEIGHT, BUTTONWIDTH, BUTTONHEIGHT );
    my_optionButtonSprite->SetPosition(OPTIONX, OPTIONY);

    setSprite( my_bestButtonSprite, my_buttonImage, BUTTONNORMSX, BUTTONCASEBEGIN, BUTTONNORMEX, BUTTONCASEHEIGHT, BUTTONWIDTH, BUTTONHEIGHT );
    my_bestButtonSprite->SetPosition(BESTX, BESTY);

    setSprite( my_quitButtonSprite, my_buttonImage, BUTTONNORMSX, BUTTONCASEBEGIN, BUTTONNORMEX, BUTTONCASEHEIGHT, BUTTONWIDTH, BUTTONHEIGHT );
    my_quitButtonSprite->SetPosition(QUITX, QUITY);

    //Pour les langues.

    setSprite( my_englishSprite, my_languageImage, ENGLISHSX, SPRITELANGUEBEGIN, ENGLISHEX, SPRITELANGUEHEIGHT, LANGUEWIDTH, LANGUEHEIGHT );

    setSprite( my_frenchSprite, my_languageImage, FRENCHSX, SPRITELANGUEBEGIN, FRENCHEX, SPRITELANGUEHEIGHT, LANGUEWIDTH, LANGUEHEIGHT );

    setSprite( my_italianoSprite, my_languageImage, ITALIANOSX, SPRITELANGUEBEGIN, ITALIANOEX, SPRITELANGUEHEIGHT, LANGUEWIDTH, LANGUEHEIGHT );

    setSprite( my_spanishSprite, my_languageImage, SPANISHSX, SPRITELANGUEBEGIN, SPANISHEX, SPRITELANGUEHEIGHT, LANGUEWIDTH, LANGUEHEIGHT );

    setSprite( my_deutschSprite, my_languageImage, DEUTSCHSX, SPRITELANGUEBEGIN, DEUTSCHEX, SPRITELANGUEHEIGHT, LANGUEWIDTH, LANGUEHEIGHT );

    my_languageToSprite[english] = my_englishSprite;
    my_languageToSprite[francais] = my_frenchSprite;
    my_languageToSprite[italiano] = my_italianoSprite;
    my_languageToSprite[deutsch] = my_deutschSprite;
    my_languageToSprite[espanol] = my_spanishSprite;

    //Pour les icones
    //setSprite( my_musicIcon, my_iconImage,
    setSprite( my_musicIcon, my_iconImage, MUSICONSX, ICONSPRITEBEGIN, MUSICONEX, ICONSPRITEHEIGHT, ICONWIDTH, ICONHEIGHT );
    my_musicIcon->SetPosition( MUSICX, ICONY );

    setSprite( my_soundIcon, my_iconImage, SOUNDSX, ICONSPRITEBEGIN, SOUNDONEX, ICONSPRITEHEIGHT, ICONWIDTH, ICONHEIGHT );
    my_soundIcon->SetPosition( SOUNDX, ICONY );
}

//Pour mettre en place le thème ananas
void
GameView::setAnanasMode() {
#ifdef __linux__
    if (!my_backgroundImage->LoadFromFile("Pictures/wallpapper.png") || !my_caseImage->LoadFromFile("Pictures/case.png") || !my_buttonImage->LoadFromFile("Pictures/buttonAnanas.png") || !my_languageImage->LoadFromFile("Pictures/languages.png") || !my_spriteImage->LoadFromFile("Pictures/choiceSprite.png") || !my_iconImage->LoadFromFile("Pictures/icon.png") || !my_fontScore->LoadFromFile("Font/scoreFont.ttf") || !my_fontTitle->LoadFromFile("Font/titleFont.ttf") || !my_fontValue->LoadFromFile("Font/valueFont.ttf") || !my_fontButton->LoadFromFile("Font/buttonFont.ttf") || !my_musicLevel->OpenFromFile("Music/gridMusic.wav")) {
        cout << "Error when loading image or font" << endl;
    }
#else
    if (!my_backgroundImage->LoadFromFile("wallpapper.png") || !my_caseImage->LoadFromFile("case.png") || !my_buttonImage->LoadFromFile("buttonAnanas.png") || !my_languageImage->LoadFromFile("languages.png") || !my_spriteImage->LoadFromFile("choiceSprite.png") || !my_iconImage->LoadFromFile("icon.png")|| !my_fontScore->LoadFromFile("scoreFont.ttf") || !my_fontTitle->LoadFromFile("titleFont.ttf") || !my_fontValue->LoadFromFile("valueFont.ttf") || !my_fontButton->LoadFromFile("buttonFont.ttf") || !my_musicLevel->OpenFromFile("gridMusic.wav") ) {
        cout << "Error when loading image or font" << endl;
    }
#endif
    else {

        //Les affichages de valeurs seront toujours identiques, du coup on les set direct
        my_valueString->SetFont( *my_fontValue );
        my_valueString->SetSize(23);
        my_valueString->SetColor(Color(255,255,255) );


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

        my_buttonString->SetFont( *my_fontButton );
        my_buttonString->SetSize(30);
        my_buttonString->SetColor(Color(251,210,98));

        //Pour la musique
        my_musicLevel->SetLoop(true);
    }

    setImageToSprite();
}

//Cette méthode sert à mettre un text à un string, le positionner, et le dessiner
void
GameView::setTextAndDraw( sf::String* s, string text, int x, int y, bool useSizeRectX ) {
    bool sizeIsChanged = false;
  
    s->SetText(text);
    
    if ( s->GetRect().GetWidth() > WINDOWWITDH ) {
        while ( s->GetRect().GetWidth() > WINDOWWITDH )
            s->SetSize( s->GetSize() - 5 );
        sizeIsChanged = true;
    }
    
    if ( useSizeRectX )
        x -=  ( ( s->GetRect().GetWidth()  ) / 2 );
    
    s->SetPosition(x, y);
    
    
    
    my_window->Draw(*s);
}


//Cette méthode sert à configurer à positionner un sprite et la dessiner
void
GameView::configureSpriteAndDraw( sf::Sprite* s, int x, int y) {
    s->SetPosition(x, y);
    my_window->Draw(*s);
}

void
GameView::setTeacherMode() {
#ifdef __linux__
    if (!my_backgroundImage->LoadFromFile("Pictures/wallpapperTeach.png") || !my_caseImage->LoadFromFile("Pictures/caseTeach.png") || !my_buttonImage->LoadFromFile("Pictures/buttonTeach.png") || !my_languageImage->LoadFromFile("Pictures/languages.png") || !my_spriteImage->LoadFromFile("Pictures/choiceSprite.png") || !my_iconImage->LoadFromFile("Pictures/icon.png") ||!my_fontScore->LoadFromFile("Font/arial.ttf") || !my_fontTitle->LoadFromFile("Font/arial.ttf") || !my_fontValue->LoadFromFile("Font/arial.ttf") || !my_fontButton->LoadFromFile("Font/arial.ttf") || !my_musicLevel->OpenFromFile("Music/gridMusic.wav")) {
        cout << "Error when loading image or font" << endl;
    }
#else
    if (!my_backgroundImage->LoadFromFile("wallpapperTeach.png") || !my_caseImage->LoadFromFile("caseTeach.png") || !my_buttonImage->LoadFromFile("buttonTeach.png") || !my_languageImage->LoadFromFile("languages.png") || !my_spriteImage->LoadFromFile("choiceSprite.png") || !my_iconImage->LoadFromFile("icon.png") ||!my_fontScore->LoadFromFile("arial.ttf") || !my_fontTitle->LoadFromFile("arial.ttf") || !my_fontValue->LoadFromFile("arial.ttf") || !my_fontButton->LoadFromFile("arial.ttf") || !my_musicLevel->OpenFromFile("gridMusic.wav")) {
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
GameView::reverseMusic( bool music ) {
    if ( music )
        my_musicIcon->SetSubRect( IntRect( MUSICONSX, ICONSPRITEBEGIN, MUSICONEX, ICONSPRITEHEIGHT ) );
    else
        my_musicIcon->SetSubRect( IntRect( MUSICOFFSX, ICONSPRITEBEGIN, MUSICOFFEX, ICONSPRITEHEIGHT ) );
}

void
GameView::reverseSound( bool sound ) {
    if ( sound )
        my_soundIcon->SetSubRect( IntRect( SOUNDSX, ICONSPRITEBEGIN, SOUNDONEX, ICONSPRITEHEIGHT ) );
    else
        my_soundIcon->SetSubRect( IntRect( SOUNDSX, ICONSPRITEBEGIN, SOUNDOFFEX, ICONSPRITEHEIGHT ) );
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
GameView::newScreen() {
    my_window->Clear();
    my_window->Draw(*my_backgroundSprite);
    my_window->Draw(*my_musicIcon);
    my_window->Draw(*my_soundIcon);
}

void
GameView::showPresentation() {
    newScreen();

    my_titleString->SetColor(Color(255,255,255));
    my_titleString->SetSize(60);

    setTextAndDraw( my_titleString, "PURU PURU DIGGER ", ( WINDOWWITDH / 2 ), 100, true );

    my_window->Draw( *my_playButtonSprite );

    my_window->Draw( *my_optionButtonSprite );

    my_window->Draw( *my_bestButtonSprite);

    my_window->Draw( *my_quitButtonSprite);

    setTextAndDraw( my_buttonString, my_messages[my_language][best], BESTX + 40, (BESTY + (BUTTONHEIGHT / 5)), false );

    setTextAndDraw( my_buttonString, my_messages[my_language][play], PLAYX  + 40, PLAYY + (BUTTONHEIGHT / 5), false );

    setTextAndDraw( my_buttonString, my_messages[my_language][stop], QUITX + 40, (QUITY + (BUTTONHEIGHT * 0.2 )), false );

    setTextAndDraw( my_buttonString, my_messages[my_language][setting], OPTIONX + 40   , OPTIONY + (BUTTONHEIGHT * 0.2), false );
}

void
GameView::showOption() {
    newScreen();

    //Le titre de la page
    setTextAndDraw( my_titleString, my_messages[my_language][setting], ( WINDOWWITDH / 2 ), 10, true);

    //L'énoncé langue
    setTextAndDraw( my_scoreString, my_messages[my_language][language], QUITONX + 50, CHOICELANGUEHIGH, false);

    setTextAndDraw( my_scoreString, my_messages[my_language][actual], QUITONX + 50, MYLANGUEY, false );

    setTextAndDraw( my_scoreString, my_messages[my_language][theme], QUITONX + 50, CHOICESPRITEY, false );


    showLanguage();

    //On place notre langue en cours
    configureSpriteAndDraw( my_languageToSprite[my_language], MYLANGUEX, MYLANGUEY );

    showSpriteChoice();


    //Le bouton pour quitter et son text
    my_window->Draw( *my_buttonQuitSprite );

    setTextAndDraw( my_buttonString, my_messages[my_language][stop], ( ( ( QUITONX + BUTTONWIDTH ) / 2.5 )  ), (QUITONY + (BUTTONHEIGHT / 5)), false  );
}

void
GameView::setHoverLanguage( Language hover ) {
    my_languageToSprite[hover]->SetColor(Color(255,255,255,128));
}

void
GameView::resetLanguageNorm() {
    for ( map<Language, Sprite*>::const_iterator it = my_languageToSprite.begin() ; it!=my_languageToSprite.end(); ++it) {
        my_languageToSprite[ it->first ]->SetColor(Color(255,255,255,255));
    }

}

void
GameView::showLanguage() {
    configureSpriteAndDraw( my_languageToSprite[english], ENGLISHX, CHOICELANGUEHIGH );
    configureSpriteAndDraw( my_languageToSprite[francais], FRENCHX, CHOICELANGUEHIGH );
    configureSpriteAndDraw( my_languageToSprite[italiano], ITALIANOX, CHOICELANGUEHIGH );
    configureSpriteAndDraw( my_languageToSprite[deutsch], DEUTSCHX, CHOICELANGUEHIGH );
    configureSpriteAndDraw( my_languageToSprite[espanol], SPANISHX, CHOICELANGUEHIGH );
}

void
GameView::showSpriteChoice() {
    my_window->Draw(*my_ananasSprite);
    my_window->Draw(*my_teacherSprite);
}

void
GameView::showBestScore() {
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
            setTextAndDraw(my_valueString, line, ( WINDOWWITDH / 2 ) , i, true );
            i += 100;
        }

        //On affiche le bouton quitter avec son string
        my_window->Draw( *my_buttonQuitSprite );

        setTextAndDraw( my_buttonString, my_messages[my_language][stop], ( ( ( QUITONX + BUTTONWIDTH ) / 2.5 )  ), (QUITONY + (BUTTONHEIGHT / 5)), false  );

        scoreLect.close();


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
        
        //On ajoute notre joueur à la map
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
GameView::showIsEnteringABestScore( string player ) {
    newScreen();
    setTextAndDraw( my_scoreNum, my_messages[my_language][by], ( WINDOWWITDH / 2 ), 10, true );
    setTextAndDraw( my_scoreNum, my_messages[my_language][name], ( WINDOWWITDH / 2 ), 100, true );

    setTextAndDraw( my_valueString, player, ( WINDOWWITDH / 2 ) , WINDOWHEIGHT / 2, true ) ;
}

void
GameView::showGrid() {
    for ( int i = 0; i < LIGNE ; i++ ) {
        for ( int j = 0; j < COLONNE; j++ ) {
            //On dessine le contenu de la case
            configureSpriteAndDraw( my_stringToSprite[ my_model->getLevel()->getGrid()[i][j]->getType() ] ,  convertIndiceXToPixel( j ), convertIndiceYToPixel( i ) );
            //Si c'est une case numérotée, on met son numéro
            if ( my_model->getLevel()->getGrid()[i][j]->getType() == "ValueCell" || my_model->getLevel()->getGrid()[i][j]->getType() == "GoldCell") {

                setTextAndDraw( my_valueString, intToString( my_model->getLevel()->getGrid()[i][j]->getValue() ), ( convertIndiceXToPixel( j ) + CASEWITDH / 3 ), ( convertIndiceYToPixel( i ) + CASEHEIGHT / 6 ), false );
            }
        }
    }
}

void
GameView::showLoseLevel( bool time, bool over) {
    newScreen();
    my_titleString->SetSize(40);

    my_titleString->SetColor(Color(0,0,0));

    if ( !time && !over )
        setTextAndDraw( my_titleString, my_messages[my_language][looselevel],( WINDOWWITDH / 2 ), WINDOWHEIGHT / 2, true ) ;
    else if ( time )
        setTextAndDraw( my_titleString, my_messages[my_language][timeup], ( WINDOWWITDH / 2 ), WINDOWHEIGHT / 2, true );
    else if ( over )
        setTextAndDraw( my_titleString, my_messages[my_language][loosegame], ( WINDOWWITDH / 2 ), WINDOWHEIGHT / 2, true );
    else if ( time && over )
        setTextAndDraw( my_titleString, my_messages[my_language][loosegame], ( WINDOWWITDH / 2 ), WINDOWHEIGHT / 2, true );
    

}

void
GameView::showWinLevel() {
    newScreen();

    my_titleString->SetSize(40);
    my_titleString->SetColor(Color(0,0,0));

    setTextAndDraw( my_titleString, my_messages[my_language][winlevel], ( WINDOWWITDH / 2 ), WINDOWHEIGHT / 2, true ) ;
}

void
GameView::showScore() {
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

void
GameView::showLevel() {
    newScreen();

    my_titleString->SetColor(Color(255,255,255));
    my_titleString->SetSize(60);

    setTextAndDraw( my_titleString, " PURU PURU DIGGER " , ( WINDOWWITDH / 2 ), 10, true ) ;

    //On dessine la grille
    showGrid();

    //On dessine le score
    showScore();

    my_window->Draw( *my_buttonQuitSprite );

    setTextAndDraw( my_buttonString, my_messages[my_language][stop], ( ( ( QUITONX + BUTTONWIDTH ) / 2.5 )  ), (QUITONY + (BUTTONHEIGHT / 5) ), false );
}

//Injection de dépendance model
void
GameView::setModel(GameModel *model) {
    my_model = model;
}

//Pour savoir si c'est dans une zone
bool
GameView::isInZone( int x, int y, int px, int py, int w, int h ) {
    if ( x > px && x < px + w && y > py && y < py + h )
        return true;
    else
        return false;
}

//Boucle d'événement
void
GameView::treatGame( ) {

    bool isInPresentation = true;  // Pour savoir si il est sur le menu de départ
    bool isPlaying = false;        // Pour savoir si il est sur le jeu
    bool isChoosingOption = false; // Pour savoir si il est le menu du choix des options
    bool isViewingBestScore = false;
    bool isEnterABestScore = false;
    bool music = true;
    bool sound = true;
    bool time = false;
    bool over = false;
    
    string player = "";
    
    
    sf::Clock pause;        //La clock pour la pause
    bool isInBreak = false; //Pour savoir quand on est en pause

    while ( my_window->IsOpened( ) ) {

        Event event;

        while ( my_window->GetEvent( event ) ) {
            switch (event.Type) {

                case Event::Closed :
                    my_window->Close();
                    break;

                case Event::MouseMoved :

                    if ( isInPresentation ) {

                        if ( isInZone ( event.MouseMove.X, event.MouseMove.Y, PLAYX, PLAYY, BUTTONWIDTH, BUTTONHEIGHT ) )

                            setButtonHover( my_playButtonSprite );

                        else if ( isInZone ( event.MouseMove.X, event.MouseMove.Y, OPTIONX, OPTIONY, BUTTONWIDTH, BUTTONHEIGHT ) )
                            setButtonHover( my_optionButtonSprite );

                        else if ( isInZone ( event.MouseMove.X, event.MouseMove.Y, BESTX, BESTY, BUTTONWIDTH, BUTTONHEIGHT ) )
                            setButtonHover( my_bestButtonSprite );

                        else if ( isInZone ( event.MouseMove.X , event.MouseMove.Y, QUITX, QUITY, BUTTONWIDTH, BUTTONHEIGHT ) )
                            setButtonHover( my_quitButtonSprite );
                        else
                            resetButtonNorm();

                    } else if ( isChoosingOption ) {

                        if ( isInZone ( event.MouseMove.X, event.MouseMove.Y, ENGLISHX, CHOICELANGUEHIGH, LANGUEWIDTH, LANGUEHEIGHT ) )
                            setHoverLanguage( english );

                        else if ( isInZone ( event.MouseMove.X, event.MouseMove.Y, FRENCHX, CHOICELANGUEHIGH, LANGUEWIDTH, LANGUEHEIGHT ) )
                            setHoverLanguage( francais );

                        else if ( isInZone ( event.MouseMove.X, event.MouseMove.Y, SPANISHX, CHOICELANGUEHIGH, LANGUEWIDTH,LANGUEHEIGHT ) )
                            setHoverLanguage( espanol );

                        else if ( isInZone ( event.MouseMove.X, event.MouseMove.Y, DEUTSCHX, CHOICELANGUEHIGH, LANGUEWIDTH, LANGUEHEIGHT ) )
                            setHoverLanguage( deutsch );

                        else if ( isInZone ( event.MouseMove.X, event.MouseMove.Y, ITALIANOX, CHOICELANGUEHIGH, LANGUEWIDTH, LANGUEHEIGHT ) )
                            setHoverLanguage( italiano );

                        else if ( isInZone ( event.MouseMove.X, event.MouseMove.Y, QUITONX, QUITONY, BUTTONWIDTH, BUTTONHEIGHT )  )
                            setButtonHover(my_buttonQuitSprite);

                        else {
                            resetButtonNorm();
                            resetLanguageNorm();
                        }

                    } else if ( isPlaying  ) {
                        if ( isInZone ( event.MouseMove.X, event.MouseMove.Y, QUITONX, QUITONY, BUTTONWIDTH, BUTTONHEIGHT ) )

                            setButtonHover(my_buttonQuitSprite);
                        else
                            resetButtonNorm();
                    } else if ( isViewingBestScore ) {
                        if ( isInZone ( event.MouseMove.X, event.MouseMove.Y, QUITONX, QUITONY, BUTTONWIDTH, BUTTONHEIGHT ) )

                            setButtonHover(my_buttonQuitSprite);
                        else
                            resetButtonNorm();
                    }

                    break;

                case Event::KeyPressed : // Appui sur une touche du clavier
                {
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
                                    enterScore(player);
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
                    break;
                    
                case Event::TextEntered :
                {
                    if ( isEnterABestScore ) {
                        if ( event.Text.Unicode >= 48 && event.Text.Unicode <127 ) {
                            player += static_cast<char>(event.Text.Unicode);
                        }
                    }
                }
                    break;

                case Event::MouseButtonPressed :

                    if ( isInPresentation ) {
                        if ( isInZone ( event.MouseButton.X, event.MouseButton.Y, PLAYX, PLAYY, BUTTONWIDTH, BUTTONHEIGHT ) ) {
                            isInPresentation = false;
                            isPlaying = true;
                            my_model->reset();
                            if ( music )
                                my_musicLevel->Play();
                        } else if ( isInZone ( event.MouseButton.X, event.MouseButton.Y, QUITX, QUITY, BUTTONWIDTH, BUTTONHEIGHT ) ) {
                            my_window->Close();

                        } else if ( isInZone ( event.MouseButton.X, event.MouseButton.Y, OPTIONX, OPTIONY, BUTTONWIDTH, BUTTONHEIGHT ) ) {
                            isInPresentation = false;
                            isChoosingOption = true;

                        } else if ( isInZone ( event.MouseButton.X, event.MouseButton.Y, BESTX, BESTY, BUTTONWIDTH, BUTTONHEIGHT ) ) {
                            isInPresentation = false;
                            isViewingBestScore = true;
                        } else if ( isInZone( event.MouseButton.X, event.MouseButton.Y, MUSICX, ICONY, ICONWIDTH, ICONHEIGHT ) ) {
                            music = !(music);
                            reverseMusic( music );
                        } else if ( isInZone( event.MouseButton.X, event.MouseButton.Y, SOUNDX, ICONY, ICONWIDTH, ICONHEIGHT ) ) {
                            sound = !(sound);
                            reverseSound( sound );
                        }

                    } else if ( isChoosingOption ) {

                        if ( isInZone ( event.MouseButton.X, event.MouseButton.Y, ENGLISHX, CHOICELANGUEHIGH, LANGUEWIDTH, LANGUEHEIGHT ) )
                            my_language = english;

                        if ( isInZone ( event.MouseButton.X, event.MouseButton.Y, FRENCHX, CHOICELANGUEHIGH, LANGUEWIDTH, LANGUEHEIGHT ) )
                            my_language = francais;

                        if ( isInZone ( event.MouseButton.X, event.MouseButton.Y, ITALIANOX, CHOICELANGUEHIGH, LANGUEWIDTH, LANGUEHEIGHT ) )
                            my_language = italiano;

                        if ( isInZone ( event.MouseButton.X, event.MouseButton.Y, SPANISHX, CHOICELANGUEHIGH, LANGUEWIDTH,LANGUEHEIGHT ) )
                            my_language = espanol;

                        if ( isInZone ( event.MouseButton.X, event.MouseButton.Y, DEUTSCHX, CHOICELANGUEHIGH, LANGUEWIDTH, LANGUEHEIGHT ) )
                            my_language = deutsch;

                        if ( isInZone( event.MouseButton.X, event.MouseButton.Y, CHOICEANANASX, CHOICESPRITEY, SPRITECHOICEWIDTH, SPRITECHOICEHEIGHT ) )
                            setAnanasMode();

                        if ( isInZone( event.MouseButton.X, event.MouseButton.Y, CHOICETEACHERX, CHOICESPRITEY, SPRITECHOICEWIDTH, SPRITECHOICEHEIGHT ) )
                            setTeacherMode();

                        if ( isInZone ( event.MouseButton.X, event.MouseButton.Y, QUITONX, QUITONY, BUTTONWIDTH, BUTTONHEIGHT ) ) {
                            isChoosingOption = false;
                            isInPresentation = true;
                        } else if ( isInZone( event.MouseButton.X, event.MouseButton.Y, MUSICX, ICONY, ICONWIDTH, ICONHEIGHT ) ) {
                            music = !(music);
                            reverseMusic( music );
                        } else if ( isInZone( event.MouseButton.X, event.MouseButton.Y, SOUNDX, ICONY, ICONWIDTH, ICONHEIGHT ) ) {
                            sound = !(sound);
                            reverseSound( sound );
                        }

                    } else if ( isViewingBestScore ) {

                        if ( isInZone ( event.MouseButton.X, event.MouseButton.Y, QUITONX, QUITONY, BUTTONWIDTH, BUTTONHEIGHT ) ) {
                            isViewingBestScore = false;
                            isInPresentation = true;
                        } else if ( isInZone( event.MouseButton.X, event.MouseButton.Y, MUSICX, ICONY, ICONWIDTH, ICONHEIGHT ) ) {
                            music = !(music);
                            reverseMusic( music );
                        } else if ( isInZone( event.MouseButton.X, event.MouseButton.Y, SOUNDX, ICONY, ICONWIDTH, ICONHEIGHT ) ) {
                            sound = !(sound);
                            reverseSound( sound );
                        }

                    } else if ( isPlaying ) {
                        if ( convertYPixel( event.MouseButton.Y ) != -1 && convertXPixel( event.MouseButton.X ) != -1 ) {
                            my_model->orderMovement( convertYPixel( event.MouseButton.Y ), convertXPixel( event.MouseButton.X ) );
                        }
                        if ( isInZone ( event.MouseButton.X, event.MouseButton.Y, QUITONX, QUITONY, BUTTONWIDTH, BUTTONHEIGHT ) ) {
                            isPlaying = false;
                            isEnterABestScore = true;
                            my_musicLevel->Stop();
                            resetButtonNorm();
                        } else if ( isInZone( event.MouseButton.X, event.MouseButton.Y, MUSICX, ICONY, ICONWIDTH, ICONHEIGHT ) ) {
                            music = !(music);
                            reverseMusic( music );
                            if ( music )
                                my_musicLevel->Play();
                            else
                                my_musicLevel->Stop();
                        } else if ( isInZone( event.MouseButton.X, event.MouseButton.Y, SOUNDX, ICONY, ICONWIDTH, ICONHEIGHT ) ) {
                            sound = !(sound);
                            reverseSound( sound );
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
                }
                over = true;
                showLoseLevel(time, over);
                isInBreak = true;
            } else if ( my_model->getLevel()->lose() ) {
                if ( !isInBreak )
                    pause.Reset();
                showLoseLevel(time, over);
                isInBreak = true;

            } else if ( my_model->getLevel()->win()  ) {
                if ( !isInBreak )
                    pause.Reset();
                showWinLevel();
                isInBreak = true;
            } else {
                showLevel();
            }
        } else if ( isEnterABestScore ) {
            showIsEnteringABestScore( player );
        }

        // Affichage du contenu de la fenêtre à l'écran
        my_window->Display();

        //Pour gérer l'affichage durant quelque seconde
        if ( isInBreak  ) {

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
}
