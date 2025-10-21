#pragma once

#include "Core/WidgetModel.h" 

class WidgetViewModel
{

public:

    WidgetViewModel(WidgetModel& m) : model(m) {}


protected:

    WidgetModel& model;

};

