#include<ncurses.h>




using namespace std;

class hero{
	
	int current_x;
	int current_y;
	
	int yMax;
	int xMax;
	
	chtype character;
	chtype space;

	int energy;
	int whiffles;
	
	WINDOW * gamewin;
	WINDOW * menuwin;

 public:

	hero(WINDOW * gwin, WINDOW * mwin);
	
	//get the hero's location
	void mvup();
	void mvdown();
	void mvleft();
	void mvright();
	int mv();
	void display();
};
