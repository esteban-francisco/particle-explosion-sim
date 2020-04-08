#include "Particle.h"

namespace eighteentwelve {

Particle::Particle(): x(0), y(0) {
    this->init();
}

Particle::~Particle() {}

void Particle::init() {
    this->x = 0;
    this->y = 0;

    this->direction = (2 * M_PI * rand())/RAND_MAX;
    this->speed = (config::SPEED_MULTIPLIER * rand())/RAND_MAX;
    
    // exaggerate distance between particles
    this->speed *= this->speed; 
}

void Particle::update(int intervalTime) {

    // add a curl to the particle paths
    this->direction += intervalTime * config::CURL_MULTIPLIER;

    double xSpeed = this->speed * cos(this->direction);
    double ySpeed = this->speed * sin(this->direction);

    this->x += xSpeed * intervalTime;
    this->y += ySpeed * intervalTime;

    // replace off screen particles to center
	if (this->x <= -1.0 || this->x >= 1.0 ||
        this->y <= -1.0 || this->y >= 1.0) {
        this->init();
    }

    // every hundredth run resets
    if (rand() < RAND_MAX/100) this->init();

}

double Particle::getX() { return this->x; }
double Particle::getY() { return this->y; }

} // namespace EighteenTwelve