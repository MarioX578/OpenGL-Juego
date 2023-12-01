#pragma once
#include <glm/glm.hpp>

namespace GL
{
	class Rederizador
	{
		public:
		Rederizador() = default;
		virtual ~Rederizador()= default;


		Rederizador(const Rederizador& other) = delete;
		Rederizador& operator==(const Rederizador& other) = delete;


		void Viewport(uint32_t x, uint32_t y, uint32_t ancho, uint32_t alto);
		void LimpiarPantalla(const glm::vec4& color);

	};
}