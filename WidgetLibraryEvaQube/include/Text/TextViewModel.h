#pragma once

#include "Text/TextModel.h"

class TextViewModel
{

public:

    //TextViewModel para construirse correctamente necesita una referencia a un TextModel.
    //El TextModel se inicializa antes de hacer nada mas al usar este constructor.
    TextViewModel(TextModel& m) : model(m) {}
    //Equivalencia (incorrecta y menos eficiente)-> TextViewModel(TextModel m) { model = m; }

    std::string getText() const { return model.getText(); }
    void setText(const std::string& newText) { model.setText(newText); }
    void bindOnTextChanged(std::function<void()> handler) { model.onTextChanged = handler; }


private:

    TextModel& model;

};