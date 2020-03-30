#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL2/SDL.h>

namespace EighteenTwelve {

class Screen {
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;
    const static int MEMSIZE_PIXELBUFFER = SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32);
    const static int COLOR_DEFAULT = 0x00;

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    Uint32 *pixelBuffer;

public:
    Screen();
    ~Screen();
    bool init();
    void update();
    void clear();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    bool processEvents();
    void close();

    
};

} // namespace EighteenTwelve

#endif // SCREEN_H_