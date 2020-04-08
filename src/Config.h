#ifndef CONFIG_H_
#define CONFIG_H_

// multimedia and hardware compent lib
#include <SDL2/SDL.h>

namespace config {

// Application Management
const static char* APPLICATION_NAME = "Particle Explosion Simulator";


// Screen Management
const static int SCREEN_WIDTH = 800;
const static int SCREEN_HEIGHT = 600;
const static int CLR_BG_DEFAULT = 0x00;

const static int SCREEN_AREA = SCREEN_WIDTH * SCREEN_HEIGHT;
const static int MEMSIZE_PIXELBUFFER = SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32);


// Particle Management
const static int NUM_PARTICLES = 2500;
const static int CLR_PARTICLE_SEED = 0xC70039FF; // red default planned for future version

const static double SPEED_MULTIPLIER = 0.02;
const static double CURL_MULTIPLIER = 0.0003;

} // namespace config

#endif // CONFIG_H_
