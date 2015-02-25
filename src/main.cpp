#include <SDL.h>

#ifdef EMSCRIPTEN
#include <emscripten/emscripten.h>
#endif

#include <memory>

#include "Game.h"
#include "Renderer_SDL2.h"

bool done = false;

static SDL_Window *win = NULL;
static SDL_Renderer *renderer = NULL;

static Uint32 last_time = 0;

void loop_iteration(Game* game)
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

    Uint32 cur_time = SDL_GetTicks();
    float delta = float(cur_time - last_time) / 1000.0f;
    last_time = cur_time;

    game->update(delta);
    game->render();
}


int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_OPENGL, &win, &renderer);

    int w,h;
    SDL_GetWindowSize(win, &w, &h);

    std::auto_ptr<Renderer> game_renderer(new Renderer_SDL2(win, renderer));

    std::auto_ptr<Game> game(new Game(*game_renderer));

    last_time = SDL_GetTicks();

#ifdef EMSCRIPTEN
    emscripten_set_main_loop_arg((em_arg_callback_func)loop_iteration, game.get(), 0, 1);
#else
    while (!done) {
        loop_iteration(game.get());
    }
#endif

    game.reset();
    game_renderer.reset();

    SDL_Quit();

    return 0;
}