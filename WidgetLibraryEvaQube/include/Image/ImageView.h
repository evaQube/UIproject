#pragma once

#include <SFML/Graphics.hpp>

#include "Image/ImageViewModel.h"

class ImageView
{

public:

	ImageView(ImageViewModel& vm, const sf::Vector2f& pos, const sf::Vector2f& scale = sf::Vector2f{1,1}, const float& rot = 0);

	void changePos(const sf::Vector2f& pos){ image.setPosition(pos); }
	void changeScale(const sf::Vector2f& scale){ image.setScale(scale); }
	void changeRot(const float& rot) { image.setRotation(rot); }

	void draw(sf::RenderWindow& window);
	void update();


private:

	ImageViewModel& viewModel;
	sf::Sprite image;

	sf::RectangleShape placeholder;
};