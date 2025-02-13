#include "menuScene.h"

void menuSceneDraw(struct menuScene* s)
{
	putimage(0, 0, s->bk);//绘制背景图片
	if (s->isStartGameHover == true)//根据鼠标是否悬停选择文字颜色
		settextcolor(WHITE);
	else
		settextcolor(BLACK);
	drawtext("开始游戏", &s->rectStartGame, DT_CENTER);//绘制文字
	if (s->isEndGameHover == true)
		settextcolor(WHITE);
	else
		settextcolor(BLACK);
	drawtext("结束游戏", &s->rectEndGame, DT_CENTER);
}
void menuSceneUpdate(struct menuScene* s)
{

}
void menuSceneControl(struct menuScene* s, ExMessage* msg)
{
	switch (msg->message)
	{
	case WM_LBUTTONDOWN://表示按下鼠标左键
	  {
		if (s->isEndGameHover == true)
			exit(0);//结束整个程序
		if (s->isStartGameHover == true)
			s->isQuit = true;
		//检查鼠标是否悬停在开始或结束游戏按钮上
		break;
	  }
	case WM_MOUSEMOVE:
	  {
		if (msg->x > s->rectStartGame.left
			&& msg->x < s->rectStartGame.right
			&& msg->y<s->rectStartGame.bottom
			&& msg->y>s->rectStartGame.top)
			s->isStartGameHover = true;
		else
			s->isStartGameHover = false;
		if (msg->x > s->rectEndGame.left
			&& msg->x < s->rectEndGame.right
			&& msg->y<s->rectEndGame.bottom
			&& msg->y>s->rectEndGame.top)
			s->isEndGameHover = true;
		else
			s->isEndGameHover = false;
		break;
	  }
	}
}
bool menuSceneIsQuit(struct menuScene* s)
{
	return s->isQuit;
}
void menuSceneInit(struct menuScene* s)
{
	s->super.draw = (void(*)(struct scene*))menuSceneDraw;
	s->super.update = (void(*)(struct scene*))menuSceneUpdate;
	s->super.control = (void(*)(struct scene*, ExMessage*))menuSceneControl;
	s->super.isQuit = (bool(*)(struct scene*))menuSceneIsQuit;
	s->isStartGameHover = false;
	s->isEndGameHover = false;
	s->isQuit = false;
	s->bk = new IMAGE;
	loadimage(s->bk, "img/menu.png");
	s->rectStartGame.left = 130;
	s->rectStartGame.top = 430;
	s->rectStartGame.right = 300;
	s->rectStartGame.bottom = 480;
	s->rectEndGame.left = 130;
	s->rectEndGame.top = 540;
	s->rectEndGame.right = 300;
	s->rectEndGame.bottom = 590;
	settextcolor(BLACK);
	settextstyle(50, 0, "微软雅黑");
	setbkmode(TRANSPARENT);
}
void menuSceneDestroy(struct menuScene* s)
{
	delete s->bk;
}