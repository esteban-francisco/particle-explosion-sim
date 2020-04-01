#include "Swarm.h"
#include "Config.h"

namespace EighteenTwelve {

Swarm::Swarm(): lastUpdateTime(0) {
    this->particles = new Particle[Config::NUM_PARTICLES];
}

Swarm::~Swarm() {
    delete [] this->particles;
}

void Swarm::update(int elapsedTime) {

    int intervalTime = elapsedTime - this->lastUpdateTime;

    for (int i = 0; i < Config::NUM_PARTICLES; i++)
        this->particles[i].update(intervalTime);

    lastUpdateTime = elapsedTime;
}

} // namespace EighteenTwelve