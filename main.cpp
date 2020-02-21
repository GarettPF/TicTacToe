#include "ttt.h"

int main() {
    srand(time(NULL));

    int done = 0;
    while (!done) {
        
        switch (display_menu()) {
            case __PLAY_GAME_: 
                game_loop();
                break;
            case __EXIT_:
                done = 1;
                __CLS_;
                break;
        }
    }

    cout << "Goodbye :)" << endl;

    return 0;
}