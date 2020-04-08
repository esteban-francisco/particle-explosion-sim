#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "config.h"

namespace eighteentwelve {

class Particle {
private:
    double x;
    double y;
    double speed;
    double direction;

private:
    void init();

public:
    Particle();
    ~Particle();
    void update(int intervalTime);
    double getX();
    double getY();
};

} // namespace EighteenTwelve

#endif // PARTICLE_H_