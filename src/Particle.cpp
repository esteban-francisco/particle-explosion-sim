#include "Particle.h"

namespace EighteenTwelve {

double Particle::getRand() {
    return ((2.0 * rand())/RAND_MAX) - 1;
}

Particle::Particle() {
    this->x = this->getRand();
    this->y = this->getRand();

    this->xSpeed = 0.005 * getRand();
    this->ySpeed = 0.005 * getRand();
} 

Particle::~Particle() {}

double Particle::getX() { return this->x; }
double Particle::getY() { return this->y; }

void Particle::update() {
    this->x += this->xSpeed;
    this->y += this->ySpeed;

    // wall "bounce" effect
	if (this->x <= -1.0 || this->x >= 1.0)
		this->xSpeed = -this->xSpeed;

	if (this->y <= -1.0 || this->y >= 1.0)
		this->ySpeed = -this->ySpeed;
}

} // namespace EighteenTwelve