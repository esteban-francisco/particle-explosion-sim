#include "Screen.h"
#include "Config.h"

namespace EighteenTwelve {

Screen::Screen(): 
    window(NULL), renderer(NULL), texture(NULL), pixelBuffer1(NULL), pixelBuffer2(NULL) {}

Screen::~Screen() {}

bool Screen::init() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) return false;

    this->window = SDL_CreateWindow(
        Config::APPLICATION_NAME(), 
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
        Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    this->renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_PRESENTVSYNC);

    this->texture = SDL_CreateTexture(
        renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, 
        Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT);

    if (this->window == NULL) {
        SDL_Quit();
        return false;
    }

    if (this->renderer == NULL) {
        SDL_DestroyWindow(this->window);
        SDL_Quit();
        return false;
    }

    if (this->texture == NULL) {
        SDL_DestroyRenderer(this->renderer);
        SDL_DestroyWindow(this->window);
        SDL_Quit();
        return false;
    }

    this->pixelBuffer1 = new Uint32[Config::SCREEN_AREA];
    this->pixelBuffer2 = new Uint32[Config::SCREEN_AREA];
    this->clear();

    return true;
}

bool Screen::processEvents() {
    SDL_Event event;

    while(SDL_PollEvent(&event))
        if(event.type == SDL_QUIT) return false;

    return true;
}

void Screen::close() {
    delete [] this->pixelBuffer1;
    delete [] this->pixelBuffer2;
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyTexture(this->texture);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void Screen::update() {
    SDL_UpdateTexture(this->texture, NULL, this->pixelBuffer1, Config::SCREEN_WIDTH*sizeof(Uint32));
    SDL_RenderClear(this->renderer);
    SDL_RenderCopy(this->renderer, this->texture, NULL, NULL);
    SDL_RenderPresent(this->renderer);
}

void Screen::clear() {
    memset(this->pixelBuffer1, Config::CLR_BG_DEFAULT, Config::MEMSIZE_PIXELBUFFER);
    memset(this->pixelBuffer2, Config::CLR_BG_DEFAULT, Config::MEMSIZE_PIXELBUFFER);
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
    if (x < 0 || x >= Config::SCREEN_WIDTH || y < 0 || y >= Config::SCREEN_HEIGHT)
        return;

    Uint32 color = Config::CLR_BG_DEFAULT;

    color <<= 8;
    color += red;
    color <<= 8;
    color += green;
    color <<= 8;
    color += blue;
    color <<= 8;
    color += 0xFF; // alpha value as opaque

    this->pixelBuffer1[(y * Config::SCREEN_WIDTH) + x] = color;
}

void Screen::boxBlur() {
    Uint32* tmp = this->pixelBuffer1;
    this->pixelBuffer1 = this->pixelBuffer2;
    this->pixelBuffer2 = tmp;

    Uint32 color, redTotal, greenTotal, blueTotal;
    Uint8 red, green, blue;
    int currentX, currentY;

    // Cycle through every pixel
    for(int y=0; y < Config::SCREEN_HEIGHT; y++) {
        for (int x=0; x < Config::SCREEN_WIDTH; x++) {

			//  0 0 0
			//  0 1 0
			//  0 0 0
            
            redTotal = greenTotal = blueTotal = 0;

            // cycle through current location and immediate surrounding
            for (int row=-1; row<=1; row++) {
                for (int col=-1; col<=1; col++) {
                    currentX = x + col;
                    currentY = y + row;

                    // validate index
                    if (currentX >= 0 && currentX < Config::SCREEN_WIDTH &&
                        currentY >= 0 && currentY < Config::SCREEN_HEIGHT) {
                        
                        // get pixel color
                        color = this->pixelBuffer2[currentY * Config::SCREEN_WIDTH + currentX];
                    
                        // get individual colors
						red = color >> 24;
						green = color >> 16;
						blue = color >> 8;
                    
                        redTotal += red;
                        greenTotal += green;
                        blueTotal += blue;
                    }
                }
            }

            // get color averages
            red = redTotal/9;
            green = greenTotal/9;
            blue = blueTotal/9;

            // set the "blurred" color!
            this->setPixel(x, y, red, green, blue);
        }
    }

}



} // namespace EighteenTwelve