#include "Game.h"
Game::Game() {
	objBird = new Bird(40, 250, 1, 1);
	timer2 = timer1 = time(0);
}
Game::~Game() {}
void Game::InsertPipes() {
	System::Random^ rnd = gcnew System::Random;
	if (difftime(time(0), timer2) > 1.5) {
		arrPipes.push_back(new PipeGroup(1, 1, 1, 1, rnd->Next(10, 390)));
		timer2 = time(0);
	}
	delete rnd;
	for (int i = 0; i < arrPipes.size(); i++) {
		if (arrPipes.at(i)->return_flag()) {
			arrPipes.erase(arrPipes.begin() + i);
			break;
		}
	}
}
void Game::Draw_Bird(Graphics^ g, Bitmap^ bmp) {
	objBird->Move(g);
	objBird->Draw_from_image(g, bmp);
}
void Game::Draw_Pipes(Graphics^ g) {
	for (int i = 0; i < arrPipes.size(); i++) {
		arrPipes.at(i)->Move();
		arrPipes.at(i)->Draw_Pipes(g);
	}
}
void Game::Jump() {
	objBird->new_orientation(direction::up);
}
void Game::Gravity() {
	objBird->new_dy(30);
}