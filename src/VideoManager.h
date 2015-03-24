/*
 * VideoManager.h
 *
 *  Created on: Mar 23, 2015
 *      Author: Keviinn
 */

#ifndef VIDEOMANAGER_H_
#define VIDEOMANAGER_H_

namespace Abstract {

	class VideoManager {
	public:
		VideoManager(){}
		virtual ~VideoManager(){}

		virtual bool loadIMG(std::string fileName,std::string id);
		virtual bool loadText();
		virtual void frame(std::string id, int x, int y, int w, int h, int cW, int cH);
		virtual void clean(std::string id);

	protected:
		std::map <std::string, SDL_Texture*> _textureMap;

	};

}

#endif /* VIDEOMANAGER_H_ */
