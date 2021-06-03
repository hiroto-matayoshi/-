#include"Menu.h"
#include"SceneMgr.h"
#include"DxLib.h"
#include"Input.h"

#define PI 3.1415926535897932384626433832795f

static int mImageTitle; 	// 画像ハンドル格納用変数
static int mImageCone;	
static int mImageMenu;

static int MenuNumber = 0;  //メニューカーソル管理用変数

// 初期化
void Menu_Initialize() {	
	mImageTitle = LoadGraph("images/Tetris_title.png");     //画像のロード
	mImageCone = LoadGraph("images/cone.png");
    mImageMenu = LoadGraph("images/menu_r.png");
}

// 終了処理
void Menu_Finalize() {
	DeleteGraph(mImageTitle);       // 画像の解放
	DeleteGraph(mImageCone);
    DeleteGraph(mImageMenu);
}

//更新
void Menu_Update() {
    //メニューカーソル移動処理
    if (iKeyFlg & PAD_INPUT_DOWN) {
        if (++MenuNumber > 3) MenuNumber = 0;
    }
    if (iKeyFlg & PAD_INPUT_UP) {
        if (--MenuNumber < 0) MenuNumber = 3;
    }

    if (iKeyFlg == PAD_INPUT_1) { //Zキーが押されていたら
        switch (MenuNumber) {       //シーンによって処理を分岐
        case 0:    //現在の画面がメニューなら
            SceneMgr_ChangeScene(eScene_Game); //シーンをゲーム画面に変更
            break;
        case 1:
            SceneMgr_ChangeScene(eScene_Help); //シーンをゲーム画面に変更
            break;
        case 2:
            SceneMgr_ChangeScene(eScene_End); //シーンをゲーム画面に変更
            break;

        }
    }

}

// 描画
void Menu_Draw() {
	DrawGraph(0, 0, mImageTitle, FALSE );

    // メニュー
    DrawGraph(280, 340, mImageMenu, TRUE);

    // メニューカーソル
    DrawRotaGraph(245, 360 + MenuNumber * 40, 0.7f, PI / 2, mImageCone, TRUE);

}
