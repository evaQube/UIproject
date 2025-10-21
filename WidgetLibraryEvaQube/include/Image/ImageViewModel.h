#pragma once

#include "Image/ImageModel.h" 

class ImageViewModel
{

public:

    ImageViewModel(ImageModel& m) : model(m) {}

    sf::Texture* getTexture() const { return model.getTexture(); }
    void setTexture(sf::Texture* newTexture) { model.setTexture(newTexture); }
    void bindOnTextureChanged(std::function<void()> handler) { model.onTextureChanged = handler; }


private:

    ImageModel& model;

};