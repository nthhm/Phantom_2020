#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"

const static int GAME_X = 500;    //�u�Q�[���v������x�ʒu
const static int CONFIG_X = 800;    //�u�ݒ�v������x�ʒu

//�񋓌^�B�ォ��0����̐����l�����蓖�Ă���
typedef enum {
	eMenu_Game,        //�Q�[��(0)
	eMenu_Config,    //�ݒ�(1)
	eMenu_Num,        //�{���ڂ̐�(2)
} eMenu;

static int mImageHandle[2];    //�摜�n���h���i�[�p�ϐ�
static int NowSelect = eMenu_Game;    //���݂̑I�����(�����̓Q�[���I��)

//������
void Menu_Initialize() {
	mImageHandle[0] = LoadGraph("dat\\images\\title01.jpg");    //�摜�̃��[�h
	mImageHandle[1] = LoadGraph("dat\\images\\Untitled.f.png");    //�摜�̃��[�h
}

//�I������
void Menu_Finalize() {
	for (int i = 0; i < 1; i++) {
		DeleteGraph(mImageHandle[i]);    //�摜�̉��
	}
}

//�X�V
void Menu_Update() {
	if (Keyboard_Get(KEY_INPUT_RIGHT) == 1) {//�E�L�[��������Ă�����
		NowSelect = (NowSelect + 1) % eMenu_Num;//�I����Ԃ��������
	}
	if (Keyboard_Get(KEY_INPUT_LEFT) == 1) {//���L�[��������Ă�����
		NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//�I����Ԃ���グ��
	}
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {//�G���^�[�L�[�������ꂽ��
		switch (NowSelect) {//���ݑI�𒆂̏�Ԃɂ���ď����𕪊�
		case eMenu_Game://�Q�[���I�𒆂Ȃ�
			SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
			break;
		case eMenu_Config://�ݒ�I�𒆂Ȃ�
			SceneMgr_ChangeScene(eScene_Config);//�V�[����ݒ��ʂɕύX
			break;
		}
	}
}

//�`��
void Menu_Draw() {
	DrawGraph(0, 0, mImageHandle[0], FALSE);
	DrawRotaGraph(320, 100, 0.3, 0, mImageHandle[1], TRUE);
	//DrawString(50, 350, "���j���[��ʂł��B", GetColor(0, 0, 0));
	//DrawString(50, 370, "�㉺�L�[�������A�G���^�[�������ĉ������B", GetColor(0, 0, 0));
	DrawString(GAME_X, 600, "start!", GetColor(200, 0, 0));
	DrawString(CONFIG_X, 600, "config", GetColor(200, 0, 0));
	// �`�悷�镶����̃T�C�Y��ݒ�
	//DrawStringToHandle(0, 0, "Phantom", GetColor(200, 0, 0), FontHandle);

	int x = 0;
	switch (NowSelect) {//���݂̑I����Ԃɏ]���ď����𕪊�
	case eMenu_Game://�Q�[���I�𒆂Ȃ�
		x = GAME_X - 30;    //�Q�[���̍��W���i�[
		break;
	case eMenu_Config://�ݒ�I�𒆂Ȃ�
		x = CONFIG_X - 30;    //�ݒ�̍��W���i�[
		break;
	}
	DrawString(x, 600, "��", GetColor(200, 0, 0));
}
