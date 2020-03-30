#include "Swarm.h"

namespace EighteenTwelve {

Swarm::Swarm() {
    this->particles = new Particle[this->NUM_PARTICLES];
}

Swarm::~Swarm() {
    delete [] this->particles;
}

void Swarm::update() {
    for (int i = 0; i < this->NUM_PARTICLES; i++)
        this->particles[i].update();
}

} // namespace EighteenTwelve