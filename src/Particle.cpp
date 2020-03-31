#include "Particle.h"
#include <math.h>

namespace EighteenTwelve {

const double Particle::SPEED_MULTIPLIER = 0.01;

Particle::Particle(): x(0), y(0) {
    this->direction = (2 * M_PI * rand())/RAND_MAX;
    this->speed = (0.009 * rand())/RAND_MAX;
} 

Particle::~Particle() {}

void Particle::update() {
    double xSpeed = this->speed * cos(this->direction);
    double ySpeed = this->speed * sin(this->direction);

    this->x += xSpeed;
    this->y += ySpeed;
/*
    // wall "bounce" effect
	if (this->x <= -1.0 || this->x >= 1.0)
		this->xSpeed = -this->xSpeed;

	if (this->y <= -1.0 || this->y >= 1.0)
		this->ySpeed = -this->ySpeed;
*/
}

double Particle::getX() { return this->x; }
double Particle::getY() { return this->y; }

} // namespace EighteenTwelve