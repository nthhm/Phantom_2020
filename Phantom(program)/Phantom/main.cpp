#include "DxLib.h"
#include "SceneMgr.h"
#include "Keyboard.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// �E�C���h�E���[�h�ŋN��
	SetMainWindowText("Phantom");
	ChangeWindowMode(TRUE);
	SetGraphMode(1600, 1000, 32);


	DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�������Ɨ���ʐݒ�

	SceneMgr_Initialize();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//��ʍX�V & ���b�Z�[�W���� & ��ʏ���

		Keyboard_Update();//�L�[�{�[�h���͍X�V

		SceneMgr_Update();  //�X�V
		SceneMgr_Draw();    //�`��

	}

	SceneMgr_Finalize();

	DxLib_End(); // DX���C�u�����I������
	return 0;
}
