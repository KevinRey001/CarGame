/*
 * Fact.h
 *
 *  Created on: Mar 20, 2015
 *      Author: Keviinn
 */

#ifndef FACT_H_
#define FACT_H_

#include <string>
#include "Object.h"

namespace Abstract{
	class Fact{
		public:
			Fact(){}
			virtual ~Fact(){}

			virtual bool init(const char* title, int width, int height)=0;
			virtual void render()=0;
			virtual void update()=0;
			virtual void close()=0;
			virtual void handleEvents()=0;
			virtual void delay(int time)=0;
			virtual bool running()=0;

			virtual Object* createNewObject(int width, int height, std::string name, std::string textureID)=0;
	};
}

#endif /* FACT_H_ */
