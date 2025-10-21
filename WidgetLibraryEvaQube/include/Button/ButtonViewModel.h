#pragma once

#include <string>

#include "Button/ButtonModel.h"


class ButtonViewModel
{

public:
    
    ButtonViewModel(ButtonModel& m) : model(m) {}
    
    void click() { model.click(); }
    void hover() { model.hover(); }
    bool isEnabled() const { return model.enabled; }
    bool isSelected() const { return model.selected; }
    void bindOnClick(std::function<void()> handler) { model.onClick = handler; }
    void bindOnHover(std::function<void()> handler) { model.onHover = handler; }


private:

    ButtonModel& model;

};