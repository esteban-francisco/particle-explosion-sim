#include "Particle.h"
#include <math.h>

namespace EighteenTwelve {

const double Particle::SPEED_MULTIPLIER = 0.0001;

Particle::Particle(): x(0), y(0) {
    this->direction = (2 * M_PI * rand())/RAND_MAX;
    this->speed = (this->SPEED_MULTIPLIER * rand())/RAND_MAX;
} 

Particle::~Particle() {}

void Particle::update(int intervalTime) {
    double xSpeed = this->speed * cos(this->direction);
    double ySpeed = this->speed * sin(this->direction);

    this->x += xSpeed * intervalTime;
    this->y += ySpeed * intervalTime;
}

double Particle::getX() { return this->x; }
double Particle::getY() { return this->y; }

} // namespace EighteenTwelve