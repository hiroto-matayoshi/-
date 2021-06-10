#include"Menu.h"
#include"SceneMgr.h"
#include"DxLib.h"
#include"Input.h"

#define PI 3.1415926535897932384626433832795f

static int mImageTitle; 	// �摜�n���h���i�[�p�ϐ�
static int mImageCone;	
static int mImageMenu;

static int MenuNumber = 0;  //���j���[�J�[�\���Ǘ��p�ϐ�

static int mSoundsSelect;   //���t�@�C���i�[�p�ϐ�
static int mSoundsMove;     

// ������
void Menu_Initialize() {	
	mImageTitle = LoadGraph("images/Tetris_title.png");     //�摜�̃��[�h
	mImageCone = LoadGraph("images/cone.png");
    mImageMenu = LoadGraph("images/menu_r.png");

    mSoundsSelect = LoadSoundMem("sounds/����A�{�^������8.mp3");    //���艹�̃��[�h
    mSoundsMove = LoadSoundMem("sounds/�J�[�\���ړ�11.mp3");    //�ړ����̃��[�h

    // �a�f�l�Đ�
    PlayMusic("sounds/yamiyouen.mp3", DX_PLAYTYPE_LOOP);
}

// �I������
void Menu_Finalize() {
	DeleteGraph(mImageTitle);       // �摜�̉��
	DeleteGraph(mImageCone);
    DeleteGraph(mImageMenu);

    StopSoundMem(mSoundsSelect);
    StopSoundMem(mSoundsMove);

    // �a�f�l��~
    StopMusic();
}

//�X�V
void Menu_Update() {
    //���j���[�J�[�\���ړ�����
    if (iKeyFlg & PAD_INPUT_DOWN) {
        PlaySoundMem(mSoundsMove, DX_PLAYTYPE_BACK);
        if (++MenuNumber > 3) MenuNumber = 0;
    }
    if (iKeyFlg & PAD_INPUT_UP) {
        PlaySoundMem(mSoundsMove, DX_PLAYTYPE_BACK);
        if (--MenuNumber < 0) MenuNumber = 3;
    }

    if (iKeyFlg == PAD_INPUT_1) {	//
        switch (MenuNumber) {		//
        case 0:		//
            SceneMgr_ChangeScene(eScene_Game);	//
            break;
        case 1:
            SceneMgr_ChangeScene(eScene_Rank);	//
            break;
        case 2:
            SceneMgr_ChangeScene(eScene_Help);	//
            break;
        case 3:
            SceneMgr_ChangeScene(eScene_End);	//
            break;
        }
    }
}

// �`��
void Menu_Draw() {
	DrawGraph(0, 0, mImageTitle, FALSE );

    // ���j���[
    DrawGraph(280, 340, mImageMenu, TRUE);

    // ���j���[�J�[�\��
    DrawRotaGraph(245, 360 + MenuNumber * 40, 0.7f, PI / 2, mImageCone, TRUE);

}
