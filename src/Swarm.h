#ifndef SWARM_H_
#define SWARM_H_

#include "config.h"
#include "Particle.h"

namespace eighteentwelve {

class Swarm {

private:
    Particle* particles;
    int lastUpdateTime;
    Uint8 red, green, blue;

public:
    Swarm();
    ~Swarm();
    void update(int elapsedTime);
    const Particle* const getParticles() { return this->particles; };
    void getColor(Uint8 &red, Uint8 &green, Uint8 &blue); 
};

} // namespace EighteenTwelve

#endif // SWARM_H_