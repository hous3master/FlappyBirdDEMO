#pragma once
#include "Entity.h"
class PipeGroup: public Entity
{
private:
	Rectangle* topPipe;
	Rectangle* downPipe;
	int pipe_gap;
public:
	PipeGroup();
	PipeGroup(int px, int py, int pw, int ph, int top_pipe_height);
	~PipeGroup();
	void Draw_Pipes(Graphics^ g);
	void Move();
	vector<Rectangle*> return_both_rectangles();
};

