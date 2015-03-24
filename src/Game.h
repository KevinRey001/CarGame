/*
 * Game.h
 *
 *  Created on: Mar 9, 2015
 *      Author: Keviinn
 */

#ifndef GAME_H_
#define GAME_H_

#include "Fact.h"
#include "Object.h"
#include "Player.h"

namespace Abstract{
	class Game{
		public:
			Game(Fact* fact);
			~Game();

			void init();
			void start();
			void pauze();
			void quit();
		private:
			Fact* thisFact;
	};
}

#endif /* GAME_H_ */
