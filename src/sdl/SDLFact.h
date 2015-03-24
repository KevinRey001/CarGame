/*
 * Game.h
 *
 *  Created on: Mar 17, 2015
 *      Author: Keviinn
 */

#ifndef SDLFACT_H
#define SDLFACT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string.h>
#include <iostream>
#include <vector>

#include "../Fact.h"
#include "../Object.h"

#include "SDLRenderer.h"
#include "SDLObject.h"

namespace SDL{
	class SDLFact : public Abstract::Fact{
		public:
			SDLFact();
			~SDLFact();

			bool init(const char* title, int width, int height);
			void render();
			void update();
			void close();
			void handleEvents();
			void delay(int time);
			bool running() { return _SUCCES; }

			Abstract::Object* createNewObject(int width, int height, std::string name, std::string textureID);
			SDL_Renderer *getRenderer(){
				return _renderer;
			}

		private:
			SDL_Window *_window;
			SDL_Renderer *_renderer;
			int _cFrame;
			bool _SUCCES;

			SDL_Event *screen_event;
			SDLObject *_background;
			SDLObject *_object;
			std::vector<SDLObject*> _objectVector;
	};
}
#endif // SDLFACT_H
