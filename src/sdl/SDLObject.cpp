/*
 * SDLObject.cpp
 *
 *  Created on: Mar 17, 2015
 *      Author: Keviinn
 */
#include <iostream>

#include "SDLObject.h"

namespace SDL{

	SDLObject::SDLObject(){
		_cW=0;
		_cH=0;
		_x=0;
		_y=0;
		_w=0;
		_h=0;
	}

	SDLObject::~SDLObject(){

	}

	bool SDLObject::load(int width, int height, std::string name, std::string textureID, SDL_Renderer* pRenderer){
		_w = width;
		_h = height;
		_textureID = textureID;
		_cW = 1;
		_cH = 1;
		if(!RenderManager::Instance()->loadIMG(name, textureID, pRenderer))
		{
			return false;
		}
		return true;
	}

	void SDLObject::render(SDL_Renderer* _renderer){
		RenderManager::Instance()->frame(_textureID, _x, _y,_w, _h, _cW, _cH, _renderer);
	}

	void SDLObject::move(int x, int y){
		_x = x;
		_y = y;
	}

	void SDLObject::update(){
		_cW = int((SDL_GetTicks() / 10000));
		if(_cW>0){
			_cW=0;
		}
		std::cout<<"Update: "<<_cW<<std::endl;
	}

	void SDLObject::clean(){
		RenderManager::Instance()->clean(_textureID);
	}

}
