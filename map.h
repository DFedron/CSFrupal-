#include<ncurses.h>


class map{
	int xMax;
	int yMax;
	WINDOW * gamewin;
	chtype space;
 public:
	map(WINDOW * gwin);
	void draw();	 
};
