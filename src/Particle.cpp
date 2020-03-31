#include "Particle.h"

namespace EighteenTwelve {

const double Particle::SPEED_MULTIPLIER = 0.01;

Particle::Particle() {
    this->x = this->getRand();
    this->y = this->getRand();

    this->xSpeed = this->SPEED_MULTIPLIER * getRand();
    this->ySpeed = this->SPEED_MULTIPLIER * getRand();
} 

Particle::~Particle() {}

void Particle::update() {
    this->x += this->xSpeed;
    this->y += this->ySpeed;

    // wall "bounce" effect
	if (this->x <= -1.0 || this->x >= 1.0)
		this->xSpeed = -this->xSpeed;

	if (this->y <= -1.0 || this->y >= 1.0)
		this->ySpeed = -this->ySpeed;
}

double Particle::getRand() { return ((2.0 * rand())/RAND_MAX) - 1; }
double Particle::getX() { return this->x; }
double Particle::getY() { return this->y; }
double Particle::getXSpeed() { return this->xSpeed; }
double Particle::getYSpeed() { return this->ySpeed; }

} // namespace EighteenTwelve