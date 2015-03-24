/*
 * SDLPlayer.h
 *
 *  Created on: Mar 17, 2015
 *      Author: Keviinn
 */

#ifndef SDLPLAYER_H
#define SDLPLAYER_H

#include "../Player.h"
#include "SDLObject.h"

namespace SDL{
	class SDLPlayer : public SDLObject,Abstract::Player{
		public:
		SDLPlayer();
		~SDLPlayer();

		void points(int point);
		void incHealth();
		void decHealth();
		int* getHealth();
	};
}

#endif // SDLPLAYER_H
