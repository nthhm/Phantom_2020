#include "Out.h"
#include "SceneMgr.h"
#include "Dxlib.h"
#include "Keyboard.h"

const static int MENU_X = 500;    //�u�Q�[���v������x�ʒu
const static int EXIT_X = 800;    //�u�ݒ�v������x�ʒu

// �񋓌^�B�ォ��0����̐����l�����蓖�Ă���
typedef enum {
	eOut_Menu,        //�Q�[��(0)
	eOut_Exit,    //�ݒ�(1)
	eOut_Num,        //�{���ڂ̐�(2)
} eOut;


static int mImageHandle;    //�摜�n���h���i�[�p�ϐ�
static int NowSelect = eOut_Menu;    //���݂̑I�����


//������
void Out_Initialize() {
	mImageHandle = LoadGraph("dat\\images\\out.jpg");
}

//�I������
void Out_Finalize() {
	DeleteGraph(mImageHandle);
}

//�X�V
void Out_Update() {
	if (Keyboard_Get(KEY_INPUT_RIGHT) == 1) {//�E�L�[��������Ă�����
		NowSelect = (NowSelect + 1) % eOut_Num;//�I����Ԃ��������
	}
	if (Keyboard_Get(KEY_INPUT_LEFT) == 1) {//���L�[��������Ă�����
		NowSelect = (NowSelect + (eOut_Num - 1)) % eOut_Num;//�I����Ԃ���グ��
	}
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {//�G���^�[�L�[�������ꂽ��
		switch (NowSelect) {//���ݑI�𒆂̏�Ԃɂ���ď����𕪊�
		case eOut_Menu://���j���[�I�𒆂Ȃ�
			SceneMgr_ChangeScene(eScene_Menu);//�V�[�����Q�[����ʂɕύX
			break;
		case eOut_Exit://�ݒ�I�𒆂Ȃ�
			Out_Finalize();
			DxLib_End();
		}
	}
}

void Out_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(MENU_X, 600, "���j���[��", GetColor(200, 0, 0));
	DrawString(EXIT_X, 600, "�I��", GetColor(200, 0, 0));

	int x = 0;
	switch (NowSelect) {//���݂̑I����Ԃɏ]���ď����𕪊�
	case eOut_Menu://���j���[�I�𒆂Ȃ�
		x = MENU_X - 30;    //���j���[�̍��W���i�[
		break;
	case eOut_Exit://�I���I�𒆂Ȃ�
		x = EXIT_X - 30;    //�I���̍��W���i�[
		break;
	}
	DrawString(x, 600, "��", GetColor(200, 0, 0));
}
