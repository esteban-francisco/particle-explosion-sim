#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
#include "Config.h"
#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace EighteenTwelve;

int main(int argc, char const *argv[]) {
    srand(time(NULL)); // random seed

    Screen screen;
    if (!screen.init()) cout << "Error initializing SDL." << endl;

    Swarm swarm;
    Uint8 red, green, blue;

    while(true) {
        // Update and Draw particles
        Uint32 elapsedTime = SDL_GetTicks();

        swarm.update(elapsedTime);
        swarm.getColor(red, green, blue);
        
        const Particle *const particles = swarm.getParticles();
        
        for (int i = 0; i < Config::NUM_PARTICLES; i++) {
            Particle particle = particles[i];
            
            screen.setPixel((particle.getX() + 1) * Config::SCREEN_WIDTH/2, 
                            (particle.getY() * Config::SCREEN_WIDTH/2) + Config::SCREEN_HEIGHT/2,
                            red, green, blue);
        }

        // Draw the screen
        screen.boxBlur();
        screen.update();

        // Check for messages/events
        if (!screen.processEvents()) break;
    }

    screen.close();

    return 0;
}
