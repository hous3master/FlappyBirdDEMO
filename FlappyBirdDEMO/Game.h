#pragma once
#include "Bird.h"
#include "PipeGroup.h"
class Game
{
private:
	Bird* objBird;
	vector<PipeGroup*> arrPipes;
	time_t timer1;
	time_t timer2;
public:
	Game();
	~Game();
	void InsertPipes();
	void Draw_Bird(Graphics^ g, Bitmap^ bmp);
	void Draw_Pipes(Graphics^ g);
	void Jump();
	void Gravity();
	bool End_Game();
};

