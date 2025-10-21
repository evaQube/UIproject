#include <Button/ButtonView.h>

#include <iostream>

ButtonView::ButtonView(ButtonViewModel& vm, const sf::Vector2f& pos, 
    const sf::Vector2f& size, const ButtonColors colors)
    : viewModel(vm)
{
    buttonColors = colors;

    shape.setPosition(pos);
    shape.setSize(size);
    shape.setFillColor(buttonColors.baseColor);
}

ButtonView::ButtonView(ButtonViewModel& vm, const sf::Vector2f& pos, 
    const sf::Vector2f& size, const ButtonColors colors,
    TextView::TextFormat& textFormat, const sf::String& text,
    const bool transparentButton)
    : viewModel(vm)
{
    buttonColors = colors;

    shape.setPosition(pos);
    shape.setSize(size);
    if (transparentButton)
    {
        shape.setFillColor(sf::Color::Transparent);
        buttonColors.baseColor = textFormat.color;
    }
    else shape.setFillColor(buttonColors.baseColor);

    textModel = std::make_unique<TextModel>();
    textViewModel = std::make_unique<TextViewModel>(*textModel);
    textView = std::make_unique<TextView>(*textViewModel, pos, textFormat);
    //FIX TEXT POSITION

    textViewModel->setText(text);
}

void ButtonView::changeColors(const ButtonColors colors)
{
    sf::Color appliedColor = (shape.getFillColor() != sf::Color::Transparent) ? 
                                shape.getFillColor() : textView->getColor();

    sf::Color colorToApply;
    if (appliedColor == buttonColors.baseColor) colorToApply = colors.baseColor;
    else if (appliedColor == buttonColors.disabledColor) colorToApply = colors.disabledColor;
    else if (appliedColor == buttonColors.hoverColor) colorToApply = colors.hoverColor;
    else if (appliedColor == buttonColors.selectedColor) colorToApply = colors.selectedColor;

    (shape.getFillColor() != sf::Color::Transparent) ? 
        shape.setFillColor(colorToApply) : textView->changeColor(colorToApply);

    buttonColors = colors;
}

void ButtonView::draw(sf::RenderWindow& window)
{
    if (shape.getFillColor() != sf::Color::Transparent) 
    {
        shape.setFillColor(viewModel.isEnabled() ? shape.getFillColor() : buttonColors.disabledColor);
        window.draw(shape);
    }
    else if (textView) 
    {
        textView->changeColor(viewModel.isEnabled() ? textView->getColor() : buttonColors.disabledColor);
    }

    if (textView)
        textView->draw(window);
}

void ButtonView::handleClick(const sf::Vector2f& mousePos) 
{
    if (shape.getGlobalBounds().contains(mousePos) && viewModel.isEnabled()) 
    {
        viewModel.click();
        
        sf::Color selectedColor = viewModel.isSelected() ? buttonColors.selectedColor : buttonColors.baseColor;
        if (shape.getFillColor() != sf::Color::Transparent) shape.setFillColor(selectedColor);
        else if (textView) textView->changeColor(selectedColor);
    }
}

void ButtonView::handleHover(const sf::Vector2f& mousePos)
{
    if (shape.getGlobalBounds().contains(mousePos) && viewModel.isEnabled()) 
    {
        viewModel.hover();

        if (shape.getFillColor() != sf::Color::Transparent) shape.setFillColor(buttonColors.hoverColor);
        else if (textView) textView->changeColor(buttonColors.hoverColor);
    }
    else 
    {
        sf::Color selectedColor = viewModel.isSelected() ? buttonColors.selectedColor : buttonColors.baseColor;
        if (shape.getFillColor() == buttonColors.hoverColor) shape.setFillColor(selectedColor);
        else if (textView) if (textView->getColor() == buttonColors.hoverColor) textView->changeColor(selectedColor);
    }
}
