#include "DxLib.h"
#include "Menu.h"
#include "FontSize.h"

static int FontHandle;

int ChangeFontSize(int Size) {
	FontHandle = CreateFontToHandle("�l�r �o�S�V�b�N", 100, 13, DX_FONTTYPE_NORMAL);
	return FontHandle;
}