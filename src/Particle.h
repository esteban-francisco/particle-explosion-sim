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
    double xSpeed;
    double ySpeed;

public:
    Particle();
    ~Particle();
    double getX();
    double getY();
    double getXSpeed();
    double getYSpeed();
    void update();
};

} // namespace EighteenTwelve

#endif // PARTICLE_H_