#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace EighteenTwelve {

class Swarm {

private:
    Particle* particles;
    int lastUpdateTime;

public:
    Swarm();
    ~Swarm();
    void update(int elapsedTime);
    const Particle* const getParticles() { return this->particles; };

    
};

} // namespace EighteenTwelve

#endif // SWARM_H_