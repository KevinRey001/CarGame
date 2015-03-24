/*
 * SDLManager.cpp
 *
 *  Created on: Mar 23, 2015
 *      Author: Keviinn
 */

#include "SDLManager.h"

namespace SDL {

	SDLManager::SDLManager(SDLFact *_fact) {
		this->_fact = _fact;
		_surface = new SDL_Surface();
		_src = new SDL_Rect();
		_dest = new SDL_Rect();
	}

	SDLManager::~SDLManager() {

	}

	bool SDLManager::loadIMG(std::string fileName, std::string id){
		_surface = IMG_Load(fileName.c_str());
		if(_surface == 0)			//if surface isnt made, end
			return false;
		else {						//else create texture and add to surface
			SDL_Texture* _texture=SDL_CreateTextureFromSurface(_fact->getRenderer(), _surface);
			SDL_FreeSurface(_surface);
			if(_texture == 0)		//if the texture isnt made
				return false;
			else
				_textureMap[id] = _texture;
		}
		return true;
	}

	bool SDLManager::loadText(){
		return false;
	}

	void SDLManager::frame(std::string id, int x, int y, int w, int h, int cW, int cH){
		_src->x = w * cW;
		_src->y = h * (cH - 1);
		_src->w = _dest->w = w;
		_src->h = _dest->h = h;
		_dest->x = x;
		_dest->y = y;
		SDL_RenderCopy(_fact->getRenderer(), _textureMap[id], _src, _dest);
	}

	void SDLManager::clean(std::string id){
		SDL_Texture* _texture = _textureMap[id];
		SDL_FreeSurface(_surface);
		SDL_DestroyTexture(_texture);
	}

}
