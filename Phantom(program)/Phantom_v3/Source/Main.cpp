#include "DxLib.h"
#include "SceneMgr.h"
#include "Keyboard.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	// �E�C���h�E���[�h�ŋN��
	SetMainWindowText("Phantom");
	ChangeWindowMode(TRUE);

	// �E�C���h�E�̃T�C�Y���蓮�ł͂ł����A���E�C���h�E�̃T�C�Y�ɍ��킹�Ċg������Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);
	SetGraphMode(1280, 1024, 32);	//��ʃT�C�Y�͂����Ō��߂�I

	/*int width, height, cb;
	GetScreenState(&width, &height, &cb);	//��ʂ̑傫���擾*/

	DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�������Ɨ���ʐݒ�

	SceneMgr_Initialize();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//��ʍX�V & ���b�Z�[�W���� & ��ʏ���

		Keyboard_Update();//�L�[�{�[�h���͍X�V

		SceneMgr_Update();  //�X�V
		SceneMgr_Draw();    //�`��

	}

	SceneMgr_Finalize();

	return 0;
}