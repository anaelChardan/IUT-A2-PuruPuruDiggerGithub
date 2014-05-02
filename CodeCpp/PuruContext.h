

#ifndef __PuruPuruDigger__PuruContext__
#define __PuruPuruDigger__PuruContext__

#include <iostream>
#include "Constantes.h"

class PuruContext {
    private :
        bool my_isInBreak;
        bool my_isInPresentation;
        bool my_isChoosingOption;
        bool my_isEnterABestScore;
        bool my_isPlaying;
        bool my_isInAnimation;
        bool my_isOver;
        bool my_isTimeOver;
        bool my_isViewingBestScore;
        bool my_isEnableSound;
        bool my_isEnableMusic;
        Language my_language;
    
    public :
        PuruContext();
        void setInBreak( bool set );
        void setInPresentation( bool set );
        void setChoosingOption( bool set );
        void setEnterABestScore( bool set );
        void setPlaying( bool set );
        void setAnimation( bool set );
        void setOver( bool set );
        void setTimeOver( bool set );
        void setViewingBestScore( bool set );
        void setSound( bool set );
        void setMusic( bool set );
        void setLanguage( Language language );
    
        bool isChoosingOption() const;
        bool isInBreak() const;
        bool isInPresentation() const;
        bool isEnterABestScore() const;
        bool isPlaying() const;
        bool isInAnimation() const;
        bool isOver() const ;
        bool isTimeOver() const;
        bool isViewingBestScore() const;
        bool isEnableSound() const;
        bool isEnableMusic() const;
        Language getLanguage() const;
};

#endif /* defined(__PuruPuruDigger__PuruContext__) */
