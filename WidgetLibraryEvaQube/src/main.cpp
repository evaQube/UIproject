#include <cassert>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <string>


#include "Core/AssetManager.h"

#include "Button/ButtonModel.h"
#include "Button/ButtonViewModel.h"
#include "Button/ButtonView.h"
#include "Image/ImageModel.h"
#include "Image/ImageViewModel.h"
#include "Image/ImageView.h"
#include "Text/TextModel.h"
#include "Text/TextViewModel.h"
#include "Text/TextView.h"

namespace sf
{
    class RenderWindow;
}

int main()
{
    //Game init
    sf::RenderWindow* window{ nullptr };

    window = new sf::RenderWindow({ 800, 600 }, "UI library");
    window->setFramerateLimit(60u);

    //TEXT
    TextModel model;
    TextViewModel viewModel(model);

    sf::Font font;
    if (!font.loadFromFile("../Data/Fonts/Roboto.ttf")) { throw std::runtime_error("Couldn't load font"); }
    TextView::TextFormat textFormat = { 
        font, 24, sf::Color::White, sf::Text::Bold, 
        TextView::CapsStyle::CapOnlyFirstLetter, TextView::TextAlignment::Left };
    TextView view(viewModel, { 500, 80 }, textFormat);
    viewModel.setText("i'm A teXt \nwIth some LETTERS");

    //BUTTONS
    ButtonView::ButtonColors buttonColors = {
        sf::Color::Blue, sf::Color::Magenta, sf::Color::Cyan, sf::Color(100,100,100)
    };

    ButtonModel bModel1;
    ButtonViewModel bViewModel1(bModel1);
    ButtonView bView1(bViewModel1, { 100, 70 }, { 200, 50 }, buttonColors);

    ButtonModel bModel2;
    ButtonViewModel bViewModel2(bModel2);
    ButtonView bView2(bViewModel2, { 100, 140 }, { 200, 50 }, buttonColors, textFormat, "Text button", true);

    ButtonModel bModel3;
    ButtonViewModel bViewModel3(bModel3);
    ButtonView bView3(bViewModel3, { 100, 210 }, { 200, 50 }, buttonColors, textFormat, "Button", false);

    
    bViewModel1.bindOnClick([]() { std::cout << "Click 1" << std::endl; });
    bViewModel1.bindOnHover([]() { std::cout << "Hover 1" << std::endl; });

    bViewModel2.bindOnClick([]() { std::cout << "Click 1" << std::endl; });
    bViewModel2.bindOnHover([]() { std::cout << "Hover 1" << std::endl; });

    bViewModel3.bindOnClick([]() { std::cout << "Click 1" << std::endl; });
    bViewModel3.bindOnHover([]() { std::cout << "Hover 1" << std::endl; });


    //IMAGE
    ImageModel iModel;
    ImageViewModel iViewModel(iModel);
    ImageView iView(iViewModel, { 300, 400 });

    AssetManager::getInstance()->loadTexture("../Data/Images/ImageTest.png");
    sf::Texture* imageTexture = AssetManager::getInstance()->getTexture("../Data/Images/ImageTest.png");
    if (imageTexture != nullptr) iViewModel.setTexture(imageTexture);
    iView.changeScale({ 2,2 });


    sf::Clock clock;

    while (window->isOpen())
    {
        const sf::Time elapsed = clock.restart();

        //Game update
        for (auto event = sf::Event(); window->pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
                    bView1.handleClick(mousePos);
                    bView2.handleClick(mousePos);
                    bView3.handleClick(mousePos);
                }
            }

            if (event.type == sf::Event::MouseMoved) {
                sf::Vector2f mousePos(event.mouseMove.x, event.mouseMove.y);
                bView1.handleHover(mousePos);
                bView2.handleHover(mousePos);
                bView3.handleHover(mousePos);
            }
        }

        //Game render
        window->clear();

        view.draw(*window);
        bView1.draw(*window);
        bView2.draw(*window);
        bView3.draw(*window);
        iView.draw(*window);

        window->display();
    }

    return 0;
}
