#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include "Rendering/AnimatedSprite.h"
#include <string>
#include <unordered_map>
#include "rapidxml.hpp"
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Rendering/TextureManager.h"
#include <stdexcept>

class SpriteManager {
public:
	/** Default constructor */
	SpriteManager();
	/** Default destructor */
	~SpriteManager();
	int loadFile(std::string input);
	AnimatedSprite getSprite(std::string input);
	void addSprite(std::string name, AnimatedSprite sprite);
protected:
private:
	static std::unordered_map<std::string, AnimatedSprite> spriteMap;
	static TextureManager texMan;
};

#endif // SPRITEMANAGER_H