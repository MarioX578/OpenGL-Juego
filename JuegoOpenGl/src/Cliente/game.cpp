#include "game.hpp"
#include "Renderizador.hpp"
#include <glm/glm.hpp>


void Game::Run()
{
	m_Window = std::make_unique<GL::Window>(Nombre, Ancho, Alto);
	m_Renderizador = m_Window->CrearRenderizador();

	m_Renderizador->Viewport(0, 0, Ancho, Alto);

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

	float r = glm::sin(glm::radians(an)) * 0.5f + 0.5f;
	float g = glm::sin(2 * glm::radians(an)) * 0.5f + 0.5f;
	float b = glm::cos(glm::radians(an)) * 0.5f + 0.5f;

	m_Renderizador->LimpiarPantalla(glm::vec4( r, g, b, 1.0f ));

	m_Window->cambiar();

	an += 180.0f / 360.0f;



}
