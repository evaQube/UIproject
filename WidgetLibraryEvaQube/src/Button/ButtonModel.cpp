#include <Button/ButtonModel.h>

#include <iostream>

void ButtonModel::click() 
{
	if (enabled && onClick) 
	{
		onClick();
		if (selectable) selected = !selected;
	}
		
}

void ButtonModel::hover()
{
	if (enabled && onHover)
		onHover();
}
