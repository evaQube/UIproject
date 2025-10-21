#include <Text/TextModel.h>

void TextModel::setText(const std::string& newText)
{
    content = newText;
    if (onTextChanged) onTextChanged();
}
