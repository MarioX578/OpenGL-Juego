namespace GL
{
	class Window
	{
	public:
		Window(const char* nombre, uint32_t height, uint32_t width);
		virtual ~Window();

		Window(const Window& other) = delete;
		Window& operator=(const Window& other) = delete;

		inline bool corriendo() const { return m_corriendo; }
		inline void cerrar() { m_corriendo = false; }
		void RecibirEvento();

	private:
		bool m_corriendo = true;
		void* m_windowHandle = nullptr;
	};

}

