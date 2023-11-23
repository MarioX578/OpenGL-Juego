#include <stdio.h>
#include <SDL/SDL.h>
#include <assert.h>

int main(int argc, char** argv)
{
	assert(SDL_Init(SDL_INIT_EVERYTHING) == 0 && "No se pudo iniciar SDL");
	SDL_Window* Window = SDL_CreateWindow("OpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	assert(Window && "No se creó la ventana SDL");

	bool Funciona = true;
	while (Funciona)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
			case SDL_QUIT:
				Funciona = false;
				break;
			}
		}
	}

	SDL_DestroyWindow(Window);
	SDL_Quit();

	return 0;
}