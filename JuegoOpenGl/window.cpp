#include "Window.h"
#include <SDL/SDL.h>
#include <assert.h>

GL::Window::Window(const char* nombre, uint32_t width, uint32_t height)
{
	assert(SDL_Init(SDL_INIT_EVERYTHING) == 0 && "No se pudo iniciar SDL");
	m_windowHandle = SDL_CreateWindow(nombre, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	assert(m_windowHandle && "No se creó la ventana SDL");
}

GL::Window::~Window()
{
	if (m_windowHandle != nullptr) {
		SDL_DestroyWindow(static_cast<SDL_Window*>(m_windowHandle));
	}
	SDL_Quit();
}

void GL::Window::RecibirEvento()
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0) {
		switch (e.type) {
		case SDL_QUIT:
			cerrar();
			break;

		}
	}
}
