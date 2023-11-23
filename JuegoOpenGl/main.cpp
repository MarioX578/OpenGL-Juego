#include <SDL/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
    // Inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Error al inicializar SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Crear una ventana
    SDL_Window* window = SDL_CreateWindow("SDL Basic Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Error al crear la ventana: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Mantener la ventana abierta durante 3 segundos
    SDL_Delay(3000);

    // Liberar recursos
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
