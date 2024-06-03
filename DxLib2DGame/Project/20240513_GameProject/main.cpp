#include "DxLib.h"//Dx���C�u�����[���C���N���[�h�i�ǂݍ��݁j

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windows�̃��C���œ�����
{

	//��{�݌v
	ChangeWindowMode(TRUE);//Windows�̉�ʂ��A�N�e�B�u�ɂ���
	DxLib_Init();//DxLib�̏�����
	SetDrawScreen(DX_SCREEN_BACK);//��ʂ̔w�i�͍�
	SetGraphMode(800, 600, 32);//��ʂ̑傫��

	//DxLib�̏���������
	if (DxLib_Init() == -1)
	{
		//�G���[���N�����璼���ɏI��
		return -1;
	}
	//�~�̏����ʒu
	int circleX = 400;
	int circleY = 300;
	int stringX=10, stringY=15;
	int stringX1 = 10, stringY1 = 50;
	int StringColor = GetColor(255, 255, 255);
	int StringColor2 = GetColor(255, 0, 0);
	int mouseX = 0, mouseY = 0;

	//�Q�[�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//��ʂ̏�����
		ClearDrawScreen();
		//��ʂɉ~��`�悳����
		DrawCircle(circleX, circleY, 30, GetColor(255, 255, 0), TRUE);
		circleX = mouseX;
		circleY = mouseY;
		//�����̃T�C�Y���w��
		SetFontSize(30);
		//�}�E�X�̍��W���擾
		GetMousePoint(&mouseX, &mouseY);
		//�}�E�X���N���b�N���ꂽ��
		if ((GetMouseInput() & MOUSE_INPUT_LEFT))
		{
			SetFontSize(30);
			DrawCircle(mouseX, mouseY, 30, GetColor(255, 255, 255), TRUE);
			DrawString(stringX1, stringY1, "Hit!", StringColor2);
		}
		//��ʂɕ�����`�悳����
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
		//�~��X���W�ɓ���������
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

		//����ʂ̓��e��\��ʂɔ��f������
		ScreenFlip();

	}

	//��ʂɓ_��`�悳���ĂˁiX���W�A�x���W�A�_�̐F�w��j
	//DrawPixel(320, 240, GetColor(255, 0, 0));
	//Dxlib�g�p�̏I������
	DxLib_End();
	//�\�[�X�̏I��
	return 0;
}