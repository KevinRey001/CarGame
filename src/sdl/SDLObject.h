/*
 * SDLObject.h
 *
 *  Created on: Mar 17, 2015
 *      Author: Keviinn
 */

#ifndef SDLOBJECT_H
#define SDLOBJECT_H

#include <string>
#include <iostream>
#include "SDL2/SDL_image.h"
#include "SDLRenderer.h"
#include "../Object.h"

namespace SDL{
	class SDLObject : public Abstract::Object{
		public:
			SDLObject();
			~SDLObject();

			bool load(int width, int height, std::string name, std::string _textureID, SDL_Renderer* _renderer);
			void render(SDL_Renderer* _renderer);
			void move(int x, int y);
			void update();
			void clean();
		protected:
			std::string _textureID;
			int _cW;
			int _cH;
			int _x;
			int _y;
			int _w;
			int _h;
	};
}

#endif // SDLOBJECT_H
