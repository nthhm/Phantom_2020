#include "DxLib.h"
#include "SceneMgr.h"
#include "Keyboard.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	// ウインドウモードで起動
	SetMainWindowText("Phantom");
	ChangeWindowMode(TRUE);

	// ウインドウのサイズを手動ではできず、且つウインドウのサイズに合わせて拡大もしないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);
	SetGraphMode(1280, 1024, 32);	//画面サイズはここで決める！

	/*int width, height, cb;
	GetScreenState(&width, &height, &cb);	//画面の大きさ取得*/

	DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //初期化と裏画面設定

	SceneMgr_Initialize();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//画面更新 & メッセージ処理 & 画面消去

		Keyboard_Update();//キーボード入力更新

		SceneMgr_Update();  //更新
		SceneMgr_Draw();    //描画

	}

	SceneMgr_Finalize();

	return 0;
}