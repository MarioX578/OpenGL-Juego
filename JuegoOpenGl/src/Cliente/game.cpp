#include "game.hpp"
#include <glad/glad.h>
#include <glm/glm.hpp>


void Game::Run()
{
	m_Window = std::make_unique<GL::Window>(Nombre, Ancho, Alto);

	glViewport(0, 0, Ancho, Alto);


	while (m_Window->corriendo())
	{
		//Manejar entrada de ususario
		ManejarEntradaDeUsuario();

		Actualizar();

		Renderizar();

		

	}

}

void Game::ManejarEntradaDeUsuario()
{
	m_Window->RecibirEvento();
	

}

void Game::Actualizar()
{
}

void Game::Renderizar()
{
	static float an = 0.0f;

	float r = glm::sin(glm::radians(an));
	float g = glm::sin(2 * glm::radians(an));
	float b = glm::cos(glm::radians(an));

	glClearColor(r, g, b, 0.1f);
	glClear(GL_COLOR_BUFFER_BIT);

	m_Window->cambiar();

	an += 2.0f / 360.0f;



}
