#include <iostream>
#include "config.h"
#include "Window.h"
#include "Swarm.h"

using namespace std;
using namespace eighteentwelve;

int main(int argc, char const *argv[]) {
    srand(time(NULL)); // random seed

    Window screen;
    if (!screen.init()) cout << "Error initializing SDL." << endl;

    Swarm swarm;
    Uint8 red, green, blue;

    while(true) {
        // Update and Draw particles
        Uint32 elapsedTime = SDL_GetTicks();

        swarm.update(elapsedTime);
        swarm.getColor(red, green, blue);
        
        const Particle *const particles = swarm.getParticles();
        
        for (int i = 0; i < config::NUM_PARTICLES; i++) {
            Particle particle = particles[i];
            
            screen.setPixel((particle.getX() + 1) * config::SCREEN_WIDTH/2, 
                            (particle.getY() * config::SCREEN_WIDTH/2) + config::SCREEN_HEIGHT/2,
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
