#include "PipeGroup.h"
PipeGroup::PipeGroup(){}
PipeGroup::PipeGroup(int px, int py, int pw, int ph, int top_pipe_height): Entity(px, py, pw, ph) {
	dx = -20;
	pipe_gap = 200;
	topPipe = new Rectangle(500, 1, 100, top_pipe_height);
	downPipe = new Rectangle(500, 1 + top_pipe_height + pipe_gap, 100, 600 - 1 - top_pipe_height - pipe_gap);
}
PipeGroup::~PipeGroup(){}
void PipeGroup::Draw_Pipes(Graphics^ g) {
	Pen^ p = gcnew Pen(Color::Black);
	p->Width = 5;
	SolidBrush^ b = gcnew SolidBrush(Color::Green);
	g->DrawRectangle(p, *topPipe);
	g->FillRectangle(b, *topPipe);
	g->DrawRectangle(p, *downPipe);
	g->FillRectangle(b, *downPipe);
}
void PipeGroup::Move() {
	if (topPipe->X + dx < 1 || downPipe->X + dx < 1) {
		flag = true;
		dx = 0;
	}
	topPipe->X += dx;
	downPipe->X += dx;
}
vector<Rectangle*> PipeGroup::return_both_rectangles() {
	vector<Rectangle* > arr;
	arr.push_back(topPipe);
	arr.push_back(downPipe);
	return arr;
}