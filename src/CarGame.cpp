#include <iostream>
#include "sdl/SDLFact.h"
#include "Game.h"

using namespace SDL;
using namespace Abstract;

int main(int argc, char *argv[]){

	Game* highway = new Game(new SDLFact());		//new always to pointer!!!

	//Game* highway = new Game(new txtFact());
	highway->init();
	highway->start();
	highway->quit();

	return 0;
}

/*
 * Test SDL not abstract
#include <iostream>

#include "sdl/SDLFact.h"

int main(int argc, char* argv[])
{
	SDLFact* g_game = new SDLFact();
    g_game->init("Highway trough hell", 600, 599);
    while(g_game->running())
    {
        g_game->render();
        g_game->handleEvents();
        g_game->update();
        SDL_Delay(10); // add the delay
    }
    g_game->clean();
    return 0;
}
*/
