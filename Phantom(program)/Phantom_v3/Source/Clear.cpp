#include "Clear.h"
#include "SceneMgr.h"
#include "Dxlib.h"
#include "Keyboard.h"

const static int MENU_X = 500;    //「ゲーム」文字のx位置
const static int EXIT_X = 800;    //「設定」文字のx位置

// 列挙型。上から0からの整数値が割り当てられる
typedef enum {
	eClear_Menu,        //ゲーム(0)
	eClear_Exit,    //設定(1)
	eClear_Num,        //本項目の数(2)
} eClear;


static int mImageHandle;    //画像ハンドル格納用変数
static int NowSelect = eClear_Menu;    //現在の選択状態


//初期化
void Clear_Initialize() {
	mImageHandle = LoadGraph("dat\\images\\Clear.jpg");
}

//終了処理
void Clear_Finalize() {
	DeleteGraph(mImageHandle);
}

//更新
void Clear_Update() {
	if (Keyboard_Get(KEY_INPUT_RIGHT) == 1) {//右キーが押されていたら
		NowSelect = (NowSelect + 1) % eClear_Num;//選択状態を一つ下げる
	}
	if (Keyboard_Get(KEY_INPUT_LEFT) == 1) {//左キーが押されていたら
		NowSelect = (NowSelect + (eClear_Num - 1)) % eClear_Num;//選択状態を一つ上げる
	}
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {//エンターキーが押されたら
		switch (NowSelect) {//現在選択中の状態によって処理を分岐
		case eClear_Menu://メニュー選択中なら
			SceneMgr_ChangeScene(eScene_Menu);//シーンをゲーム画面に変更
			break;
		case eClear_Exit://設定選択中なら
			Clear_Finalize();
			DxLib_End();
		}
	}
}

void Clear_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(MENU_X, 600, "メニューへ", GetColor(200, 0, 0));
	DrawString(EXIT_X, 600, "終了", GetColor(200, 0, 0));

	int x = 0;
	switch (NowSelect) {//現在の選択状態に従って処理を分岐
	case eClear_Menu://メニュー選択中なら
		x = MENU_X - 30;    //メニューの座標を格納
		break;
	case eClear_Exit://終了選択中なら
		x = EXIT_X - 30;    //終了の座標を格納
		break;
	}
	DrawString(x, 600, "■", GetColor(200, 0, 0));
}