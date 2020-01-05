#include "DxLib.h"
#include "SceneMgr.h"
#include "Keyboard.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ウインドウモードで起動
	SetMainWindowText("Phantom");
	ChangeWindowMode(TRUE);
	SetGraphMode(1600, 1000, 32);


	DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //初期化と裏画面設定

	SceneMgr_Initialize();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//画面更新 & メッセージ処理 & 画面消去

		Keyboard_Update();//キーボード入力更新

		SceneMgr_Update();  //更新
		SceneMgr_Draw();    //描画

	}

	SceneMgr_Finalize();

	DxLib_End(); // DXライブラリ終了処理
	return 0;
}
