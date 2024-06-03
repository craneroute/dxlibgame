#include "DxLib.h"//Dxライブラリーをインクルード（読み込み）

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windowsのメインで動かす
{

	//基本設計
	ChangeWindowMode(TRUE);//Windowsの画面をアクティブにする
	DxLib_Init();//DxLibの初期化
	SetDrawScreen(DX_SCREEN_BACK);//画面の背景は黒
	SetGraphMode(800, 600, 32);//画面の大きさ

	//DxLibの初期化処理
	if (DxLib_Init() == -1)
	{
		//エラーが起きたら直ちに終了
		return -1;
	}
	//円の初期位置
	int circleX = 400;
	int circleY = 300;
	int stringX=10, stringY=15;
	int stringX1 = 10, stringY1 = 50;
	int StringColor = GetColor(255, 255, 255);
	int StringColor2 = GetColor(255, 0, 0);
	int mouseX = 0, mouseY = 0;

	//ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//画面の初期化
		ClearDrawScreen();
		//画面に円を描画させる
		DrawCircle(circleX, circleY, 30, GetColor(255, 255, 0), TRUE);
		circleX = mouseX;
		circleY = mouseY;
		//文字のサイズを指定
		SetFontSize(30);
		//マウスの座標を取得
		GetMousePoint(&mouseX, &mouseY);
		//マウスがクリックされたら
		if ((GetMouseInput() & MOUSE_INPUT_LEFT))
		{
			SetFontSize(30);
			DrawCircle(mouseX, mouseY, 30, GetColor(255, 255, 255), TRUE);
			DrawString(stringX1, stringY1, "Hit!", StringColor2);
		}
		//画面に文字を描画させる
		//DrawString(10, 25, "kkkkk", StringColor);
		DrawFormatString(stringX, stringY, StringColor,"X:%d Y:%d", mouseX, mouseY);
		

		/*if (CheckHitKey(KEY_INPUT_UP)|| CheckHitKey(KEY_INPUT_W))
		{
			circleY -= 3;
		}
		if (CheckHitKey(KEY_INPUT_DOWN)|| CheckHitKey(KEY_INPUT_S))
		{
			circleY += 3;
		}
		if (CheckHitKey(KEY_INPUT_LEFT)|| CheckHitKey(KEY_INPUT_A))
		{
			circleX -= 3;
		}
		if (CheckHitKey(KEY_INPUT_RIGHT)|| CheckHitKey(KEY_INPUT_D))
		{
			circleX += 3;
		}*/
		//円のX座標に動きをつける
		//circleX += 4;
		//circleY += 3;
		/*if (circleY <= 30)
		{
			circleY += 3;
		}
		if (circleY >= 570)
		{
			circleY -= 3;
		}
		if (circleX <= 30)
		{
			circleX += 3;
		}
		if (circleX >= 770)
		{
			circleX -= 3;
		}*/

		//裏画面の内容を表画面に反映させる
		ScreenFlip();

	}

	//画面に点を描画させてね（X座標、Ｙ座標、点の色指定）
	//DrawPixel(320, 240, GetColor(255, 0, 0));
	//Dxlib使用の終了処理
	DxLib_End();
	//ソースの終了
	return 0;
}