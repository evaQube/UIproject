#pragma once

#include <SFML/Graphics.hpp>

#include "Text/TextViewModel.h"

class TextView
{

public:

    enum CapsStyle
    {
        Regular,
        AllCaps,
        AllLower,
        CapOnlyFirstLetter,
        SmallCaps
    };

    enum TextAlignment 
    {
        Left,
        Center,
        Right
    };

    struct TextFormat
    {
        sf::Font font;
        int charSize = 30;
        sf::Color color = sf::Color::White;
        sf::Uint32 style = sf::Text::Regular;
        CapsStyle capsStyle = CapsStyle::Regular;
        TextAlignment textAlignment = TextAlignment::Left;
    };

    TextView(TextViewModel& vm, const sf::Vector2f& pos, TextFormat& format);

    //Maybe these should be private?
    void changeCapsStyle(std::vector<sf::Text>& text, CapsStyle& capsStyle);
    std::vector<sf::Text> createAlignedText(const sf::String& textString, TextAlignment align);

    sf::Color getColor() { return text[0].getColor(); }
    void changeColor(sf::Color& newColor) { for (sf::Text& t : text) t.setFillColor(newColor); textFormat.color = newColor; };
    void changeFormat(TextFormat& newFormat) { for (sf::Text& t : text) setTextFormat(t, newFormat); textFormat = newFormat; };
    void changePos(const sf::Vector2f& pos) { textPosition = pos; update(); }

    void draw(sf::RenderWindow& window);
    void update();


private:

    TextViewModel& viewModel;
    sf::String textContent{ "Empty text" };
    std::vector<sf::Text> text;

    sf::Vector2f textPosition{0,0};
    TextFormat textFormat;

    void setTextFormat(sf::Text& text, TextFormat& format);
    std::vector<std::string> splitTextLines(const std::string& text);

};