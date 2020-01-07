#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"

const static int GAME_X = 500;    //「ゲーム」文字のx位置
const static int CONFIG_X = 800;    //「設定」文字のx位置

//列挙型。上から0からの整数値が割り当てられる
typedef enum {
	eMenu_Game,        //ゲーム(0)
	eMenu_Config,    //設定(1)
	eMenu_Num,        //本項目の数(2)
} eMenu;

static int mImageHandle[2];    //画像ハンドル格納用変数
static int NowSelect = eMenu_Game;    //現在の選択状態(初期はゲーム選択中)

//初期化
void Menu_Initialize() {
	mImageHandle[0] = LoadGraph("dat\\images\\title01.jpg");    //画像のロード
	mImageHandle[1] = LoadGraph("dat\\images\\Untitled.f.png");    //画像のロード
}

//終了処理
void Menu_Finalize() {
	for (int i = 0; i < 1; i++) {
		DeleteGraph(mImageHandle[i]);    //画像の解放
	}
}

//更新
void Menu_Update() {
	if (Keyboard_Get(KEY_INPUT_RIGHT) == 1) {//右キーが押されていたら
		NowSelect = (NowSelect + 1) % eMenu_Num;//選択状態を一つ下げる
	}
	if (Keyboard_Get(KEY_INPUT_LEFT) == 1) {//左キーが押されていたら
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
	DrawGraph(0, 0, mImageHandle[0], FALSE);
	DrawRotaGraph(320, 100, 0.3, 0, mImageHandle[1], TRUE);
	//DrawString(50, 350, "メニュー画面です。", GetColor(0, 0, 0));
	//DrawString(50, 370, "上下キーを押し、エンターを押して下さい。", GetColor(0, 0, 0));
	DrawString(GAME_X, 600, "start!", GetColor(200, 0, 0));
	DrawString(CONFIG_X, 600, "config", GetColor(200, 0, 0));
	// 描画する文字列のサイズを設定
	//DrawStringToHandle(0, 0, "Phantom", GetColor(200, 0, 0), FontHandle);

	int x = 0;
	switch (NowSelect) {//現在の選択状態に従って処理を分岐
	case eMenu_Game://ゲーム選択中なら
		x = GAME_X - 30;    //ゲームの座標を格納
		break;
	case eMenu_Config://設定選択中なら
		x = CONFIG_X - 30;    //設定の座標を格納
		break;
	}
	DrawString(x, 600, "■", GetColor(200, 0, 0));
}
