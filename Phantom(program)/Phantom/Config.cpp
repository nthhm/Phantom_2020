#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"

static int mImageHandle;    //画像ハンドル格納用変数

//初期化
void Config_Initialize() {
}

//終了処理
void Config_Finalize() {
	DeleteGraph(mImageHandle);//画像の解放
}

//更新
void Config_Update() {
	if (Keyboard_Get(KEY_INPUT_ESCAPE) != 0) {//Escキーが押されていたら
		SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
	}
}

//描画
void Config_Draw() {
	DrawString(30, 30, "準備中です。", GetColor(255, 255, 255));
}