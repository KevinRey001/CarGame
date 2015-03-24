/*
 * SDLFact.cpp
 *
 *  Created on: Mar 17, 2015
 *      Author: Keviinn
 */

#include "SDLFact.h"

namespace SDL{

	typedef RenderManager rendererManager; // Singleton

	SDLFact::SDLFact(){
		_cFrame=0;
		_SUCCES=false;
	}

	SDLFact::~SDLFact(){

	}


	bool SDLFact::init(const char* title, int width,int height){
		if(SDL_Init(SDL_INIT_EVERYTHING)>0){
			_SUCCES = false;
			screen_event->type = SDL_QUIT;
			//when init has failed close
		}
		else{
			std::cout << "SDL init success\n";
			// init the window
			_window = SDL_CreateWindow(
					title,
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					width,
					height,
					SDL_WINDOW_SHOWN
				);
			if(_window != 0){
				_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
				if(_renderer != 0){
					std::cout << "renderer creation success\n";
					_background = new SDLObject();
					_background->load(600, 599, "img/background.bmp", "background",_renderer);
					_background->move(0,0);
					_objectVector.push_back(_background);
				}
				else{
					_SUCCES = false;
					screen_event->type = SDL_QUIT;
					//when render creating has failed close
				}
			}
			else{
				_SUCCES = false;
				screen_event->type = SDL_QUIT;
				//when window creating has failed close
			}
		}

		_SUCCES=true;
		std::cout << "init success\n";

		return true;

	}

	void SDLFact::render(){
		for(std::vector<SDLObject*>::size_type i = 0; i != _objectVector.size(); i++)
			_objectVector[i]->render(_renderer);
		SDL_RenderPresent(_renderer); // draw to the screen
	}

	void SDLFact::handleEvents(){
		if(SDL_PollEvent(screen_event))
		{
			switch (screen_event->type){
				case SDL_QUIT:
					_SUCCES = false;
					break;
				default:
					break;
			}
		}
	}

	void SDLFact::update(){
		for(std::vector<SDLObject*>::size_type i = 0; i != _objectVector.size(); i++)
			_objectVector[i]->update();
		SDL_RenderPresent(_renderer);
	}

	void SDLFact::close(){
		for(std::vector<SDLObject*>::size_type i = 0; i != _objectVector.size(); i++)
			_objectVector[i]->clean();

		SDL_DestroyWindow(_window);
		SDL_DestroyRenderer(_renderer);
		SDL_Quit();
	}

	void SDLFact::delay(int time){
		SDL_Delay(time);
	}

	Abstract::Object* SDLFact::createNewObject(int width, int height, std::string name, std::string textureID){
		_object = new SDLObject();
		_object->load(width,height,name,textureID,_renderer);
		_objectVector.push_back(_object);
		return _object;
	}
}
