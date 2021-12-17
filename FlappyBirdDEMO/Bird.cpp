#include "Bird.h"
Bird::Bird() {}
Bird::Bird(int px, int py, int pw, int ph) : Entity(px, py, pw, ph, 1, 1, 0, 0) {
	lifes = 5;
	vertical_velocity = 50;
	horizontal_velocity = 0;
	new_orientation(direction::still);
}
Bird::~Bird() {}
void Bird::new_lifes(int new_data) { lifes = new_data; }
int Bird::return_lifes() { return lifes; }
