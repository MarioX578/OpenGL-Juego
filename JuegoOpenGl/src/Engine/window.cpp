#include "window.hpp"
#include <glad/glad.h>
#include <SDL/SDL.h>
#include <assert.h>
#include "window.hpp"

namespace GL
{
	Window::Window(const char* nombre, uint32_t width, uint32_t height)
	{
		
		assert(SDL_Init(SDL_INIT_EVERYTHING) == 0 && "No se pudo iniciar SDL");

		m_windowHandle = SDL_CreateWindow("OpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
		assert(m_windowHandle && "No se creó la ventana SDL");

		m_OpenGLContext = SDL_GL_CreateContext((SDL_Window*)m_windowHandle);
		assert(m_OpenGLContext && "No se creó el contexto de OpenGL");

		SDL_GL_SetSwapInterval(1);


		SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		//SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	
		assert(gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress) != 0 && "No fue posible inicializar GLAD");


	}
	Window::~Window()
	{

		SDL_GL_DeleteContext(m_OpenGLContext);

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

	void Window::cambiar()
	{
		SDL_GL_SwapWindow((SDL_Window*)m_windowHandle);



	}

	std::unique_ptr<Rederizador> Window::CrearRenderizador()
	{
		return std::make_unique<Rederizador>();
	}
	
}
