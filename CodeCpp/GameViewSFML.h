#ifndef __PuruPuruDigger__GameViewSFML__
#define __PuruPuruDigger__GameViewSFML__

#include <iostream>
#include <SFML/Window.hpp>

#include "GameModel.h"
#include "Graphics/ButtonGraphic.h"
#include "Observers/EventDispatcher.h"
#include "Graphics/GraphicMusic.h"
#include "Graphics/GraphicSound.h"
#include "PuruContext.h"
#include "Graphics/LanguageGraphic.h"
#include "Graphics/AnanasSprite.h"
#include "Graphics/TeacherSprite.h"
#include "Manager/SoundManager.h"
#include "Graphics/BackgroundGraphic.h"

class GameView {
    private :
    
        sf::RenderWindow* my_window; /*!< La fenêtre */
        GameModel * my_model; /*!<  Le modèle */
        EventDispatcher* my_eventDispatcher; /*!<  Le dispatcher*/

        ButtonGraphic* my_playButton; /*!<  Le bouton play */
        ButtonGraphic* my_settingButton;/*!<  Le bouton des options */
        ButtonGraphic* my_bestButton;/*!<  Le bouton des best scores */
        ButtonGraphic* my_quitButton;/*!<  Le bouton quitter */
    
        GraphicMusic *my_musicIcon;/*!<  L'icône de musique */
        GraphicSound *my_soundIcon;/*!<  L'icône de son */
    
        AnanasSprite *my_ananasSprite;/*!<  La vue de notre sprite*/
        TeacherSprite *my_teacherSprite;/*!<  La vue du sprite du prof */
    
        BackgroundGraphic *my_background; /*!<  Le fond  */

        std::map< Language, LanguageGraphic* >* my_languageToSprite; /*!<  Associer une image à son sprite */

        PuruContext* my_context; /*!<  Le contexte de notre jeu de notre vue */
    
        void goToPresentation(); /*!<  Les transitions on va en mode Presentation */
        void goToSettings(); /*!<  La modèle de notre vue */
        void goToPlay();
        void goToScore();
        void goToEnterScore();
    
        void initView();
        void initPresentation();
        void initSettings();
        void initBestScore();
        void initEnterScore();
        void initPlay();

    
    
    public :

         GameView();
        ~GameView();
        /*!
         *  \brief Injection du modèle à la vue
         *
         * param[in] model : le modèle à interpréter  */
        void setModel(GameModel * model);

    /*!
     *  \brief La boucle de jeu
     */
        void treatGame();
};



#endif /* defined(__PuruPuruDigger__GameViewSFML__) */
