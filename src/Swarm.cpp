#include "Swarm.h"

namespace EighteenTwelve {

Swarm::Swarm(): lastUpdateTime(0) {
    this->particles = new Particle[Config::NUM_PARTICLES];
}

Swarm::~Swarm() {
    delete [] this->particles;
}

void Swarm::getColor(Uint8 &red, Uint8 &green, Uint8 &blue) {
    red = this->red;
    green = this->green;
    blue = this->blue;
}

void Swarm::update(int elapsedTime) {

    // positioning
    int intervalTime = elapsedTime - this->lastUpdateTime;

    for (int i = 0; i < Config::NUM_PARTICLES; i++)
        this->particles[i].update(intervalTime);

    this->lastUpdateTime = elapsedTime;

    // coloring
    this->red = (1 + sin(this->lastUpdateTime * 0.0002)) * 128;
    this->green = (1 + sin(this->lastUpdateTime * 0.0001)) * 128;
    this->blue = (1 + sin(this->lastUpdateTime * 0.0003)) * 128;
}

} // namespace EighteenTwelve