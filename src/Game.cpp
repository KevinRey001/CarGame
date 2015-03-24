/*
 * Game.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: Keviinn
 */

#include "Game.h"
#include <iostream>

namespace Abstract{

	Game::Game(Fact* fact){
		thisFact = fact;
	}

	Game::~Game(){
	}

	void Game::init(){
		thisFact->init("Highway trough hell", 600, 599);
	}

	void Game::start(){
		int x = 200;
		Object	*player = thisFact->createNewObject(47,112,"img/car_red.bmp","player");
		Object	*enemy = thisFact->createNewObject(52,132,"img/car_pickup.bmp","enemy_1");

		//Object* test = new Player();

		while(thisFact->running())
		{
			player->move(210,x);
			enemy->move(275,x+152);

			if(x > 0)
				x -= 1;
			else
				x=600;

			thisFact->render();
			thisFact->handleEvents();
			thisFact->update();
			thisFact->delay(10);

			//std::cout<<"position"<<x<<std::endl;

		}
	}

	void Game::pauze(){

	}

	void Game::quit(){
		thisFact->close();
	}

}


