
#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
#include "Screen.h"
#include "Swarm.h"

//#include <stdlib.h>     /* srand, rand */
//#include <time.h>       /* time */

using namespace std;
using namespace EighteenTwelve;

int main(int argc, char const *argv[]) {
    srand(time(NULL)); // random seed

    Screen screen;
    if (!screen.init()) cout << "Error initializing SDL." << endl;

    Swarm swarm;

    while(true) {
        // Update particles

        // Draw particles
        Uint32 elapsed = SDL_GetTicks();

        screen.clear();
        swarm.update();
        
        Uint8 red = (1 + sin(elapsed*0.0005)) * 128;
        Uint8 green = (1 + sin(elapsed*0.0006)) * 128;
        Uint8 blue = (1 + sin(elapsed*0.0007)) * 128;

        const Particle *const particles = swarm.getParticles();
        for (int i = 0; i < swarm.NUM_PARTICLES; i++) {
            Particle particle = particles[i];
            
            int x = (particle.getX() + 1) * screen.SCREEN_WIDTH/2;
            int y = (particle.getY() * screen.SCREEN_WIDTH/2) + screen.SCREEN_HEIGHT/2;
        
            screen.setPixel(x, y,red, green, blue);
        }

        // Draw the screen
        screen.update();

        // Check for messages/events
        if (!screen.processEvents()) break;
    }

    screen.close();

    return 0;
}
