#include "Swarm.h"

namespace EighteenTwelve {

Swarm::Swarm(): lastUpdateTime(0) {
    this->particles = new Particle[this->NUM_PARTICLES];
}

Swarm::~Swarm() {
    delete [] this->particles;
}

void Swarm::update(int elapsedTime) {

    int intervalTime = elapsedTime - this->lastUpdateTime;

    for (int i = 0; i < this->NUM_PARTICLES; i++)
        this->particles[i].update(intervalTime);

    lastUpdateTime = elapsedTime;
}

} // namespace EighteenTwelve