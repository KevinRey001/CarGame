/*
 * SDLManager.h
 *
 *  Created on: Mar 23, 2015
 *      Author: Keviinn
 */

#ifndef SDL_SDLMANAGER_H_
#define SDL_SDLMANAGER_H_

#include "SDLFact.h"
#include "../VideoManager.h"

namespace SDL {

	class SDLManager : public Abstract::VideoManager {
		public:
			SDLManager(SDLFact *_fact);
			~SDLManager();

			bool loadIMG(std::string fileName,std::string id);
			bool loadText();
			void frame(std::string id, int x, int y, int w, int h, int cW, int cH);
			void clean(std::string id);

		private:
			SDLFact *_fact;
			SDL_Surface *_surface;
			SDL_Rect *_src, *_dest;

	};

}

#endif /* SDL_SDLMANAGER_H_ */
