#include <CoreFoundation/CFBundle.h>

#include "Game.hpp"

int main(__unused int argc, __unused char *args[]) {
    Game game = Game();
    
    int result = game.run();
    
    return result;
}
