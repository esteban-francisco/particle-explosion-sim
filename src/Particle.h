#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <SDL2/SDL.h>

namespace EighteenTwelve {

class Particle {
public:
    static const double SPEED_MULTIPLIER;
    static double getRand();

private:
    double x;
    double y;
    double speed;
    double direction;

public:
    Particle();
    ~Particle();
    double getX();
    double getY();
    void update();
};

} // namespace EighteenTwelve

#endif // PARTICLE_H_