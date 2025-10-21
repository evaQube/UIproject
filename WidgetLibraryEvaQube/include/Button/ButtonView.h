#pragma once

#include <SFML/Graphics.hpp>

#include "Button/ButtonViewModel.h"
#include "Text/TextModel.h"
#include "Text/TextViewModel.h"
#include "Text/TextView.h"


class ButtonView
{

public:

    struct ButtonColors 
    {
        sf::Color baseColor { sf::Color::Blue };
        sf::Color selectedColor { sf::Color::Magenta };
        sf::Color hoverColor { sf::Color::Cyan };
        sf::Color disabledColor { sf::Color(100,100,100)};
    };

    //Only shape
    ButtonView(ButtonViewModel& vm, const sf::Vector2f& pos, 
        const sf::Vector2f& size, const ButtonColors colors);
    //Shape and text
    ButtonView(ButtonViewModel& vm, const sf::Vector2f& pos, 
        const sf::Vector2f& size, const ButtonColors colors,
        TextView::TextFormat& textFormat, const sf::String& text,
        const bool transparentButton);

    void changePos(const sf::Vector2f& pos) { shape.setPosition(pos); if (textView) textView->changePos(pos); }
    void changeSize(const sf::Vector2f& size) { shape.setSize(size); }
    void changeColors(const ButtonColors colors);
    void changeText(const sf::String& text) { if (textViewModel) textViewModel->setText(text); }
    void changeText(const sf::String& text, TextView::TextFormat& textFormat) { if (textView) textView->changeFormat(textFormat); changeText(text); }

    void draw(sf::RenderWindow& window);
    void handleClick(const sf::Vector2f& mousePos);
    void handleHover(const sf::Vector2f& mousePos);
    

private:

    ButtonViewModel& viewModel;
    sf::RectangleShape shape;

    ButtonColors buttonColors;

    //TEMP
    std::unique_ptr<TextModel> textModel;
    std::unique_ptr<TextViewModel> textViewModel;
    std::unique_ptr<TextView> textView;
};