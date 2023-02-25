#include <iostream>
using std::cout;

class Character
{
private:
	int life;
	int attack;
	int range;

public:
	int getLife();
	int getAttack();
	int getRange();

	int setLife();
	int setAttack();
	int setRange();

	void place(Board &board);

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void trail();

	~Character();
};