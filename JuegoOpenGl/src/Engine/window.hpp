#include <cstdint>
#include "Renderizador.hpp"
#include <memory>


namespace GL 
{
    class Window {
    public:
        Window(const char* nombre, uint32_t width, uint32_t height);
        virtual ~Window();

        Window(const Window& other) = delete;
        Window& operator=(const Window& other) = delete;

        inline bool corriendo() const { return m_corriendo; }
        inline void cerrar() { m_corriendo = false; }


        void RecibirEvento();
        void cambiar();


        std::unique_ptr<Rederizador> CrearRenderizador();


    private:
        bool m_corriendo = true;
        void* m_windowHandle = nullptr;
        void* m_OpenGLContext = nullptr;

    };
}
