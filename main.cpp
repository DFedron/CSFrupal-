#include<ncurses.h>

#include"map.h"
#include"hero.h"

#define maplength 32

int main(){
	initscr();
	cbreak();
	noecho();
	
	//make sure map is on the center
	int xStart = (COLS*3/4 - maplength) / 2;
	int yStart = (LINES - maplength) / 2;
	WINDOW * gamewin = newwin(maplength, maplength, yStart, xStart);
	int c = ' ';
	wborder(gamewin,c,c,c,c,c,c,c,c);
	wrefresh(gamewin);
	
	WINDOW * menuwin = newwin(LINES, COLS/4, 0, COLS*3/4);	
	int s = '#';
	wborder(menuwin,s,c,c,c,s,c,s,c);
	wrefresh(menuwin);

	hero * HERO = new hero(gamewin,menuwin);
	map * MAP = new map(gamewin);

	MAP->draw();
	do{
		HERO->display();
		wrefresh(gamewin);
	}while(HERO->mv() != 'q');

	
	delete HERO;
	delete MAP;	
	endwin();
	return 0;
}
