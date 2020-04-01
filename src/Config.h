#ifndef CONFIG_H_
#define CONFIG_H_

#include "Particle.h"

namespace EighteenTwelve {

class Config
{
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;
    const static int COLOR_DEFAULT = 0x00;
    
    const static int SCREEN_AREA = SCREEN_WIDTH * SCREEN_HEIGHT;
    const static int MEMSIZE_PIXELBUFFER = SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32);

    const static int NUM_PARTICLES = 5000;

    const static double SPEED_MULTIPLIER() { return 0.02; }
    const static double CURL_MULTIPLIER() { return 0.0003; }
};

} // namespace EighteenTwelve

#endif // CONFIG_H_
