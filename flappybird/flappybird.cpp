// flappybird.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include<time.h>
#pragma comment(lib,"Winmm.lib")

void Print();
void Begin();
void Printstone();
void Bird();
void Judgement();
void Scoleprint();
void Endorretry();

int bird_x = 150, bird_y = 300, i = 0, k = 0;
int scole = 0, t = 0;
int stone_x1, stone_y1;
int stone_x2, stone_y2;
IMAGE background, bird1[4], bird2[4], scole1[10], scole2[10], stone_up1, stone_up2, stone_down1, stone_down2,
stone_up3, stone_up4, stone_down3, stone_down4;
MOUSEMSG m;

int main()
{
	if (t == 0) {
		Begin();
		t++;
	}
	if (t) {
		Print();
		_getch();
		bird_y = 300;
		bird_x = 150;
		i = 0;
		k = 0;
		scole = 0;
	}
	while (1) {
		Bird();
		Print();
		Judgement();
	}
	closegraph();
    return 0;
}

void Print() {
	putimage(0, 0, &background);
	Printstone();
	putimage(bird_x, bird_y, &bird1[i % 3], NOTSRCERASE);
	putimage(bird_x, bird_y, &bird2[i % 3], SRCINVERT);
	if (k % 5 == 0) {
		i++;
	}
	k++;
	Scoleprint();
	FlushBatchDraw();
}
void Printstone() {
	Sleep(30);
	if (stone_x1 > 210) {
		putimage(stone_x1, stone_y1, &stone_up2, NOTSRCERASE);
		putimage(stone_x1, stone_y1, &stone_up1, SRCINVERT);
		putimage(stone_x1, stone_y1 + 750, &stone_down2, NOTSRCERASE);
		putimage(stone_x1, stone_y1 + 750, &stone_down1, SRCINVERT);
		putimage(stone_x2, stone_y2, &stone_up4, NOTSRCERASE);
		putimage(stone_x2, stone_y2, &stone_up3, SRCINVERT);
		putimage(stone_x2, stone_y2 + 750, &stone_down4, NOTSRCERASE);
		putimage(stone_x2, stone_y2 + 750, &stone_down3, SRCINVERT);
		stone_x1--;
		stone_x2--;

	}
	else if (stone_x1 == 210)//左柱子消失，将stone_x2,stone_y2值归位
	{
		stone_x2 = stone_x1;
		stone_y2 = stone_y1;
		putimage(stone_x1, stone_y1, &stone_up2, NOTSRCERASE);
		putimage(stone_x1, stone_y1, &stone_up1, SRCINVERT);
		putimage(stone_x1, stone_y1 + 750, &stone_down2, NOTSRCERASE);
		putimage(stone_x1, stone_y1 + 750, &stone_down1, SRCINVERT);
		stone_x1--;
		stone_x2--;
	}
	else if (stone_x1 < 210 && stone_x1>0)//画面只存在一根柱子的情况
	{
		putimage(stone_x1, stone_y1, &stone_up2, NOTSRCERASE);
		putimage(stone_x1, stone_y1, &stone_up1, SRCINVERT);
		putimage(stone_x1, stone_y1 + 750, &stone_down2, NOTSRCERASE);
		putimage(stone_x1, stone_y1 + 750, &stone_down1, SRCINVERT);
		stone_x1--;
		stone_x2--;
	}
	if (stone_x1 == 0) {
		stone_y1 = rand() % 310 - 555;
		stone_x1 = 350;
		putimage(stone_x1, stone_y1, &stone_up2, NOTSRCERASE);
		putimage(stone_x1, stone_y1, &stone_up1, SRCINVERT);
		putimage(stone_x1, stone_y1 + 750, &stone_down2, NOTSRCERASE);
		putimage(stone_x1, stone_y1 + 750, &stone_down1, SRCINVERT);
		stone_x1--;
		stone_x2--;

	}
}

void Begin() {
	mciSendString(_T("open C:\\Users\\yliu3\\Music\\bgm.mp3 alias music "), NULL, 0, NULL);
	mciSendString(_T("play music"), NULL, 0, NULL);
	initgraph(350, 600);
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, _T("YixianLiu"));
	IMAGE beforegame;
	loadimage(&beforegame, _T("D:\\visualworkspace\\flappybird\\素材库\\before.jpg"));
	putimage(0, 0, &beforegame);
	Sleep(1000);
	_getch();
	BeginBatchDraw();
	loadimage(&background, _T("D:\\visualworkspace\\flappybird\\素材库\\backgroundfd.jpg"));

	loadimage(&bird2[0], _T("D:\\visualworkspace\\flappybird\\素材库\\bird1-2.gif") );
	loadimage(&bird1[0], _T("D:\\visualworkspace\\flappybird\\素材库\\bird1-1.gif") );
	loadimage(&bird2[1], _T("D:\\visualworkspace\\flappybird\\素材库\\bird2-2.gif") );
	loadimage(&bird1[1], _T("D:\\visualworkspace\\flappybird\\素材库\\bird2-1.gif") );
	loadimage(&bird2[2], _T("D:\\visualworkspace\\flappybird\\素材库\\bird3-2.gif") );
	loadimage(&bird1[2], _T("D:\\visualworkspace\\flappybird\\素材库\\bird3-1.gif") );
	loadimage(&bird2[3], _T("D:\\visualworkspace\\flappybird\\素材库\\bird4-2.gif") );
	loadimage(&bird1[3], _T("D:\\visualworkspace\\flappybird\\素材库\\bird4-1.gif") );

	loadimage(&stone_up1,_T("D:\\visualworkspace\\flappybird\\素材库\\stone_up1.gif ") );
	loadimage(&stone_up2, _T("D:\\visualworkspace\\flappybird\\素材库\\stone_up2.gif")  );
	loadimage(&stone_down1, _T("D:\\visualworkspace\\flappybird\\素材库\\stone_down1.gif "));
	loadimage(&stone_down2, _T("D:\\visualworkspace\\flappybird\\素材库\\stone_down2.gif "));
	loadimage(&stone_up3, _T("D:\\visualworkspace\\flappybird\\素材库\\stone_up1.gif "));
	loadimage(&stone_up4, _T("D:\\visualworkspace\\flappybird\\素材库\\stone_up2.gif "));
	loadimage(&stone_down3, _T("D:\\visualworkspace\\flappybird\\素材库\\stone_down1.gif "));
	loadimage(&stone_down4, _T("D:\\visualworkspace\\flappybird\\素材库\\stone_down2.gif "));

	loadimage(&scole1[0],_T("D:\\visualworkspace\\flappybird\\素材库\\0_1.jpg") );
	loadimage(&scole2[0],_T("D:\\visualworkspace\\flappybird\\素材库\\0_2.jpg"));
	loadimage(&scole1[1], _T("D:\\visualworkspace\\flappybird\\素材库\\1_1.jpg"));
	loadimage(&scole2[1], _T("D:\\visualworkspace\\flappybird\\素材库\\1_2.jpg"));
	loadimage(&scole1[2], _T("D:\\visualworkspace\\flappybird\\素材库\\2_1.jpg"));
	loadimage(&scole2[2], _T("D:\\visualworkspace\\flappybird\\素材库\\2_2.jpg"));
	loadimage(&scole1[3], _T("D:\\visualworkspace\\flappybird\\素材库\\3_1.jpg"));
	loadimage(&scole2[3], _T("D:\\visualworkspace\\flappybird\\素材库\\3_2.jpg"));
	loadimage(&scole1[4], _T("D:\\visualworkspace\\flappybird\\素材库\\4_1.jpg"));
	loadimage(&scole2[4], _T("D:\\visualworkspace\\flappybird\\素材库\\4_2.jpg"));
	loadimage(&scole1[5], _T("D:\\visualworkspace\\flappybird\\素材库\\5_1.jpg"));
	loadimage(&scole2[5], _T("D:\\visualworkspace\\flappybird\\素材库\\5_2.jpg"));
	loadimage(&scole1[6], _T("D:\\visualworkspace\\flappybird\\素材库\\6_1.jpg"));
	loadimage(&scole2[6], _T("D:\\visualworkspace\\flappybird\\素材库\\6_2.jpg"));
	loadimage(&scole1[7], _T("D:\\visualworkspace\\flappybird\\素材库\\7_1.jpg"));
	loadimage(&scole2[7], _T("D:\\visualworkspace\\flappybird\\素材库\\7_2.jpg"));
	loadimage(&scole1[8], _T("D:\\visualworkspace\\flappybird\\素材库\\8_1.jpg"));
	loadimage(&scole2[8], _T("D:\\visualworkspace\\flappybird\\素材库\\8_2.jpg"));
	loadimage(&scole1[9], _T("D:\\visualworkspace\\flappybird\\素材库\\9_1.jpg"));
	loadimage(&scole2[9], _T("D:\\visualworkspace\\flappybird\\素材库\\9_2.jpg"));
	srand(time(0));
	Print();

	stone_y1 = rand() % 310 - 555;
	stone_x1 = 350;
	stone_x2 = stone_y2 = -9999;

}
void Bird() {
	char space;
	if (_kbhit()) {
		space = _getch();
		if (space == ' ') {
			bird_y -= 50;

		}
		else if (space == 27) {
			_getch();
		}

	 }
	else {
		bird_y += 3;
	}
	while (MouseHit()) {
		m = GetMouseMsg();
		switch (m.uMsg) {
		case WM_LBUTTONDOWN:
			bird_y -= 80;
			break;
		case WM_RBUTTONDOWN:
			_getch();
			break;
		}
		
	}
}

void Judgement() {
	if ((stone_x1 > 10 && stone_x1 < 20) || (stone_x1 > 174 && stone_x1 < 184)) {
		if ((bird_y > (stone_y1 + 576) && bird_y < (stone_y1 + 600)) || (bird_y > (stone_y1 + 726) && bird_y < (stone_y1 + 750))) {
			Endorretry();
		}
	}
	else if (stone_x1 > 20 && stone_x1 < 174) {
		if (!(bird_y > (stone_y1 + 600) && bird_y < (stone_y1 + 726))) {
			Endorretry();
		}
	}
	if (bird_y > 726) {
		Endorretry();
	} 
	if (stone_x1 == 150) {
		scole++;
	}
}

void Endorretry() {
	if (bird_y < 550 && stone_x1>160) {
		while (bird_y < 550) {
			putimage(0, 0, &background);
			putimage(stone_x1, stone_y1, &stone_up2, NOTSRCERASE);
			putimage(stone_x1, stone_y1, &stone_up1, SRCINVERT);
			putimage(stone_x1, stone_y1 + 750, &stone_down2, NOTSRCERASE);
			putimage(stone_x1, stone_y1 + 750, &stone_down1, SRCINVERT);
			putimage(stone_x2, stone_y2, &stone_up4, NOTSRCERASE);
			putimage(stone_x2, stone_y2, &stone_up3, SRCINVERT);
			putimage(stone_x2, stone_y2 + 750, &stone_down4, NOTSRCERASE);
			putimage(stone_x2, stone_y2 + 750, &stone_down3, SRCINVERT);
			putimage(bird_x, bird_y, &bird1[3], NOTSRCERASE);
			putimage(bird_x, bird_y, &bird2[3], SRCINVERT);
			FlushBatchDraw();
			bird_y++;

		}
	}
	IMAGE gameover1, gameover2, atlast;
	loadimage(&gameover1, _T("D:\\visualworkspace\\flappybird\\素材库\\gameover1.gif"));
	loadimage(&gameover2, _T("D:\\visualworkspace\\flappybird\\素材库\\gameover2.gif"));
	putimage(80, 200, &gameover1, NOTSRCERASE);
	putimage(80, 200, &gameover2, SRCINVERT);
	FlushBatchDraw();
	Sleep(1000);
	loadimage(&atlast, _T("D:\\visualworkspace\\flappybird\\素材库\\atlast.jpg"));
	putimage(0, 0, &atlast);
	Scoleprint();
	FlushBatchDraw();
	_getch();

	stone_y1 = rand() % 350 - 555;
	stone_x1 = 350;
	stone_x2 = stone_y2 = -9999;
	bird_y = 300;
	scole = 0;
	main();
}

void Scoleprint() {
	IMAGE *fen1[6], *fen2[6];
	int he, weishu = 1, i = 0, sdsf = scole;
	if (sdsf == 0) {
		putimage(250, 50, &scole1[0], NOTSRCERASE);
		putimage(250, 50, &scole2[0], SRCINVERT);
	}

	while (sdsf > 0) {
		he = sdsf % 10;
		fen1[i] = &scole1[he];
		fen2[i] = &scole2[he];
		putimage(300 - 50 * weishu, 50, fen1[i], NOTSRCERASE);
		putimage(300 - 50 * weishu, 50, fen2[i], SRCINVERT);
		sdsf /= 10;
		i++;
		weishu++;
	}

}
