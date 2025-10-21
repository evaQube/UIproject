#include <Image/ImageModel.h>

void ImageModel::setTexture(sf::Texture* newTexture)
{
	texture = newTexture;
	if (onTextureChanged) onTextureChanged();
}
