#pragma once

#include "Core/WidgetViewModel.h"

namespace sf
{
	class RenderWindow;
}

class WidgetView
{

public:

	WidgetView(WidgetViewModel& vm) : viewModel(vm) {};

	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void update() = 0;


protected:

	WidgetViewModel& viewModel;

};

