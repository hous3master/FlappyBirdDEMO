#pragma once
#include "Entity.h"
class Bird : public Entity
{
private:
	int lifes;
public:
	Bird();
	Bird(int px, int py, int pw, int ph);
	~Bird();
	void new_lifes(int new_data);
	int return_lifes();
};

