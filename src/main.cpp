#include <SDL.h>

#ifdef EMSCRIPTEN
#include <emscripten/emscripten.h>
#endif



bool done = false;

SDL_Window *win = NULL;
SDL_Renderer *renderer = NULL;

float angle = 0.0f;
Uint32 last_time = 0;

const int width = 400;
const int height = 400;
const int half_w = width / 2;
const int half_h = height / 2;
const int radius = half_w * .45;

void setup()
{
#ifndef EMSCRIPTEN
    SDL_GL_SetSwapInterval(1);
#endif
    SDL_RenderSetLogicalSize(renderer, width, height);
    angle = 0;
    last_time = SDL_GetTicks();
}

void render()
{
    Uint32 cur_time = SDL_GetTicks();
    float delta = float(cur_time - last_time) / 1000.0f;
    last_time = cur_time;

    float rad = angle / 180.0f * M_PI;
    float x = radius * SDL_cos(rad);
    float y = radius * SDL_sin(rad);

    SDL_Rect r = {int(x) + half_w / 2, int(y) + half_h / 2, half_w, half_h};

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &r);

    SDL_RenderPresent(renderer);

    angle += 90.0f * delta;
    if (angle > 350.0f) angle -= 360.0f;
}

void loop_iteration()
{
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_QUIT:
                done = true;
                return;
                break;
                
            default:
                break;
        }
    }
    render();
}


int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_OPENGL, &win, &renderer);
    setup();

#ifdef EMSCRIPTEN
    emscripten_set_main_loop(loop_iteration, 0, 1);
#else
    while (!done) {
        loop_iteration();
    }
#endif

    SDL_Quit();

    return 0;
}