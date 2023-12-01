#include "Renderizador.hpp"
#include <glad/glad.h>

namespace GL
{
	void GL::Rederizador::Viewport(uint32_t x, uint32_t y, uint32_t ancho, uint32_t alto)
	{
		glViewport(x, y, ancho, alto);
	}

	void GL::Rederizador::LimpiarPantalla(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
		glClear(GL_COLOR_BUFFER_BIT);

	}



}
