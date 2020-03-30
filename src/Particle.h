#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <SDL2/SDL.h>

namespace EighteenTwelve {

class Particle {
public:
    static double getRand();
    double xSpeed;
    double ySpeed;

private:
    double x;
    double y;

public:
    Particle();
    ~Particle();
    double getX();
    double getY();
    void update();
};

} // namespace EighteenTwelve

#endif // PARTICLE_H_