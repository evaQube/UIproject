#include <Image/ImageView.h>

ImageView::ImageView(ImageViewModel& vm, const sf::Vector2f& pos, const sf::Vector2f& scale, const float& rot) : viewModel(vm)
{
	image.setPosition(pos);
	image.setScale(scale);
	image.setRotation(rot);

	update();
	viewModel.bindOnTextureChanged([this]() { update(); });

	placeholder.setSize({ 100, 100 });
	placeholder.setFillColor(sf::Color::Magenta);
	placeholder.setPosition(image.getPosition());
}

void ImageView::draw(sf::RenderWindow& window)
{
	if (image.getTexture() != nullptr)
		window.draw(image);
	else 
		window.draw(placeholder);
}

void ImageView::update()
{
	if (viewModel.getTexture() != nullptr) image.setTexture(*viewModel.getTexture());
}
