#pragma once

#include <functional>

class ButtonModel
{

public:
    bool enabled = true;
    bool selected = false;
    bool selectable = true;

    std::function<void()> onClick;
    std::function<void()> onHover;

    void click();
    void hover();

};