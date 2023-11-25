#include "window.h"
#include <SDL/SDL.h>
#include <assert.h>

namespace GL
{
	Window::Window(const char* nombre, uint32_t width, uint32_t height)
	{
		assert(SDL_Init(SDL_INIT_EVERYTHING) == 0 && "No se pudo iniciar SDL");

		m_windowHandle = SDL_CreateWindow("OpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
		assert(m_windowHandle && "No se creó la ventana SDL");


	}
	Window::~Window()
	{
		SDL_DestroyWindow((SDL_Window*)m_windowHandle);
		SDL_Quit();

	}

	void Window::RecibirEvento()
	{
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
				case SDL_QUIT:
					m_corriendo = false;
					break;
			}
		}
	}
	
}
