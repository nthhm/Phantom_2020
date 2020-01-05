#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"
#include "FontSize.h"

const static int GAME_X = 350;    //「ゲーム」文字のx位置
const static int CONFIG_X = 1000;    //「設定」文字のx位置

//列挙型。上から0からの整数値が割り当てられる
typedef enum {
	eMenu_Game,        //ゲーム(0)
	eMenu_Config,    //設定(1)
	eMenu_Num,        //本項目の数(2)
} eMenu;

static int mImageHandle;    //画像ハンドル格納用変数
static int NowSelect = eMenu_Game;    //現在の選択状態(初期はゲーム選択中)
static int FontHandle;

//初期化
void Menu_Initialize() {
	mImageHandle = LoadGraph("dat\\images\\title03.png");    //画像のロード
	FontHandle = ChangeFontSize(40);
}

//終了処理
void Menu_Finalize() {
	DeleteGraph(mImageHandle);    //画像の解放
}

//更新
void Menu_Update() {
	if (Keyboard_Get(KEY_INPUT_RIGHT) == 1) {//下キーが押されていたら
		NowSelect = (NowSelect + 1) % eMenu_Num;//選択状態を一つ下げる
	}
	if (Keyboard_Get(KEY_INPUT_LEFT) == 1) {//上キーが押されていたら
		NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//選択状態を一つ上げる
	}
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {//エンターキーが押されたら
		switch (NowSelect) {//現在選択中の状態によって処理を分岐
		case eMenu_Game://ゲーム選択中なら
			SceneMgr_ChangeScene(eScene_Game);//シーンをゲーム画面に変更
			break;
		case eMenu_Config://設定選択中なら
			SceneMgr_ChangeScene(eScene_Config);//シーンを設定画面に変更
			break;
		}
	}
}

//描画
void Menu_Draw() {

	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawStringToHandle(GAME_X, 900, "start!", GetColor(200, 0, 0), FontHandle);
	DrawStringToHandle(CONFIG_X, 900, "config", GetColor(200, 0, 0), FontHandle);


	int x = 0;
	switch (NowSelect) {//現在の選択状態に従って処理を分岐
	case eMenu_Game://ゲーム選択中なら
		x = GAME_X-100;    //ゲームの座標を格納
		break;
	case eMenu_Config://設定選択中なら
		x = CONFIG_X-100;    //設定の座標を格納
		break;
	}
	DrawStringToHandle(x, 900, "■", GetColor(200, 0, 0), FontHandle);
}
