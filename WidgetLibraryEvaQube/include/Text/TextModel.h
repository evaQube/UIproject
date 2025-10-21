#pragma once

#include <functional>
#include <string>

class TextModel
{

public:
    
    std::function<void()> onTextChanged;

    void setText(const std::string& newText);
    const std::string& getText() const { return content; }


private:

    std::string content;

};