#include "map.h"

map::map(WINDOW *gwin){
	gamewin = gwin;
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_GREEN);
	space = ' ' | COLOR_PAIR(1);

	getmaxyx(gamewin, yMax, xMax);
}
	
	
void map:: draw(){

	for(int i=0; i<yMax-1; ++i)
	       for(int j=0; j<xMax-1; ++j)
	       		mvwaddch(gamewin, i, j, space);

	wrefresh(gamewin);
	
}


