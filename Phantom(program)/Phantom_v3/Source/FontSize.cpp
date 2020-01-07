#include "DxLib.h"
#include "Menu.h"
#include "FontSize.h"

static int FontHandle;

int ChangeFontSize(int Size) {
	FontHandle = CreateFontToHandle(NULL, Size, -1, -1);
	return FontHandle;
}