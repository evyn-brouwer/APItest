#include "Input.h"
#include <Windows.h>

bool isEvent(unsigned char event)
{
	return GetAsyncKeyState(event);
}
