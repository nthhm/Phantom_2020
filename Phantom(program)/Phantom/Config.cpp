#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"

static int mImageHandle;    //�摜�n���h���i�[�p�ϐ�

//������
void Config_Initialize() {
}

//�I������
void Config_Finalize() {
	DeleteGraph(mImageHandle);//�摜�̉��
}

//�X�V
void Config_Update() {
	if (Keyboard_Get(KEY_INPUT_ESCAPE) != 0) {//Esc�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}
}

//�`��
void Config_Draw() {
	DrawString(30, 30, "�������ł��B", GetColor(255, 255, 255));
}