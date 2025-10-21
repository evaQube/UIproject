#pragma once

#include <functional>
#include <SFML/Graphics/Sprite.hpp>

class ImageModel
{

public:

	std::function<void()> onTextureChanged;

	void setTexture(sf::Texture* newTexture);
	sf::Texture* getTexture() { return texture; }


private:

	sf::Texture* texture{ nullptr };

};