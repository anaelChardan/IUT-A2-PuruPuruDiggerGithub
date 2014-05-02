

#ifndef __PuruPuruDigger__Contexts__
#define __PuruPuruDigger__Contexts__

#include <iostream>

class Context {
    private :
        bool my_isInBreak;
        bool my_isInPresentation;
        bool my_isChoosingOption;
        bool my_isEnterABestScore;
        bool my_isPlaying;
        bool my_isInAnimation;
        bool my_isOver;
        bool my_isTimeOver;
    
    public :
        Context();
        void setInBreak( bool set );
        void setInPresentation( bool set );
        void setChoosingOption( bool set );
        void setEnterABestScore( bool set );
        void setPlaying( bool set );
        void setAnimation( bool set );
        void setOver( bool set );
        void setTimeOver( bool set );
    
        bool isChoosingOption() const;
        bool isInBreak() const;
        bool isInPresentation() const;
        bool isEnterABestScore() const;
        bool isPlaying() const;
        bool isInAnimation() const;
        bool isOver() const ;
        bool isTimeOver() const;
};

#endif /* defined(__PuruPuruDigger__Contexts__) */
