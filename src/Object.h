/*
 * Object.h
 *
 *  Created on: Mar 20, 2015
 *      Author: Keviinn
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include <string>

namespace Abstract{
	class Object{
		public:
			Object(){}
			virtual ~Object(){}

			virtual void move(int x,int y)=0;
			virtual void update()=0;
			virtual void clean()=0;
	};
}

#endif /* OBJECT_H_ */
