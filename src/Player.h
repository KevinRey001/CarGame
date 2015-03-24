/*
 * Player.h
 *
 *  Created on: Mar 20, 2015
 *      Author: Keviinn
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Object.h"

namespace Abstract{
	class Player : public Object{
		public:
			Player(){}
			virtual ~Player(){}

			virtual void points(int point)=0;
			virtual void incHealth()=0;
			virtual void decHealth()=0;
			virtual int* getHealth()=0;
	};
}

#endif /* PLAYER_H_ */
