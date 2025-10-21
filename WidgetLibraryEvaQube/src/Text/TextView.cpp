#include <Text/TextView.h>

#include <iostream>
#include <sstream>
#include <vector>

TextView::TextView(TextViewModel& vm, const sf::Vector2f& pos, TextFormat& format) :  viewModel(vm)
{
    textPosition = pos;
    textFormat = format;
    for(sf::Text& t : text) setTextFormat(t, textFormat);

    update();
    viewModel.bindOnTextChanged([this]() { update(); });
}

void TextView::setTextFormat(sf::Text& text, TextFormat& format)
{
    text.setFont(format.font);
    text.setCharacterSize(format.charSize);
    text.setFillColor(format.color);
    text.setStyle(format.style);
}

void TextView::changeCapsStyle(std::vector<sf::Text>& text, CapsStyle& capsStyle)
{
    switch (capsStyle)
    {
    case CapsStyle::Regular:
        return;
    case CapsStyle::AllCaps:
        for (sf::Text& t : text)
        {
            sf::String str = t.getString();
            std::transform(str.begin(), str.end(), str.begin(),
                [](unsigned char c) { return std::toupper(c); });
            t.setString(str);
        }
        break;
    case CapsStyle::AllLower:
        for (sf::Text& t : text)
        {
            sf::String str = t.getString();
            std::transform(str.begin(), str.end(), str.begin(),
                [](unsigned char c) { return std::tolower(c); });
            t.setString(str);
        }
        break;
    case CapsStyle::CapOnlyFirstLetter:
        if (text.size() > 0) 
        {
            if (text[0].getString().getSize() > 0)
            {
                sf::String str = text[0].getString();
                str[0] = std::toupper(static_cast<char>(str[0]));
                std::transform(str.begin() + 1, str.end(), str.begin() + 1,
                    [](unsigned char c) { return std::tolower(c); });
                text[0].setString(str);

                if (text.size() > 1)
                    for (size_t i = 1; i < text.size(); i++)
                    {
                        sf::String str = text[i].getString();
                        std::transform(str.begin(), str.end(), str.begin(),
                            [](unsigned char c) { return std::tolower(c); });
                        text[i].setString(str);
                    }
            }
        }
        break;
    default:
        std::cout << "TextView::changeCapsStyle-> case not implemented" << std::endl;
        return;
    }
}

std::vector<std::string> TextView::splitTextLines(const std::string& text)
{
    std::vector<std::string> lines;
    std::stringstream ssText(text);
    std::string line;

    while (std::getline(ssText, line)) //Function that searches for a "\n" and saves the chars before it on a variable
    {
        lines.push_back(line);
    }
    return lines;
}

std::vector<sf::Text> TextView::createAlignedText(const sf::String& textString, TextAlignment align)
{
    std::vector<sf::Text> alignedText;
    std::vector<std::string> lines = splitTextLines(textString);

    float lineSpacing = textFormat.charSize * 1.2f;
    float currentY = textPosition.y;

    for (const auto& line : lines) {

        sf::Text textLine;
        textLine.setString(line);
        setTextFormat(textLine, textFormat);
        sf::FloatRect bounds = textLine.getLocalBounds();

        float lineX = textPosition.x;

        switch (align)
        {
        case TextAlignment::Left:
            break;
        case TextAlignment::Center:
            lineX -= bounds.width / 2.f;
            break;
        case TextAlignment::Right:
            lineX -= bounds.width;
            break;
        default:
            std::cout << "TextView::changeTextAlignment-> case not implemented" << std::endl;
            break;
        }


        textLine.setPosition(lineX - bounds.left, currentY - bounds.top);
        currentY += lineSpacing;
        alignedText.push_back(textLine);
    }

    return alignedText;
}

void TextView::draw(sf::RenderWindow& window)
{
    //std::string str = text.getString().toAnsiString();
    //std::cout << str << std::endl;
    for (sf::Text& t : text) window.draw(t);
}

void TextView::update()
{
    textContent = viewModel.getText();
    text = createAlignedText(textContent, textFormat.textAlignment);
    changeCapsStyle(text, textFormat.capsStyle);
}
