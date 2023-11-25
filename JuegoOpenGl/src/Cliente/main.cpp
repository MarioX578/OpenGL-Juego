#include <stdio.h>
#include "window.h"

int main(int argc, char** argv)
{

	GL::Window window("OpenGl", 800, 600);

	while (window.corriendo())
	{
	
		window.RecibirEvento();
	}
	return 0;
}