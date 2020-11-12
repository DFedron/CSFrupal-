#include<random>

#include "hero.h"

hero::hero(WINDOW * gwin, WINDOW *mwin){
	//create a random location
	random_device generator;
	uniform_int_distribution<int> dist(0,31);
	current_x = dist(generator);
	current_y = dist(generator);

	energy = 100;
	whiffles = 1000;
	
	gamewin = gwin;
	menuwin = mwin;
	getmaxyx(gamewin, yMax, xMax);
	keypad(gamewin, true);

	start_color();	
	init_pair(3, COLOR_YELLOW, COLOR_RED);
	character = '@' | COLOR_PAIR(3);

	init_pair(2, COLOR_GREEN, COLOR_GREEN);
	space = ' ' | COLOR_PAIR(2);
}

//movement
void hero::mvup(){
	mvwaddch(gamewin, current_y, current_x, space);
	current_y--;
	energy -= 1;
	if(current_y < 1)
		current_y = 0;
}

void hero::mvdown(){

	mvwaddch(gamewin, current_y, current_x, space);
	current_y++;
	energy -= 1;
	if(current_y > yMax-2)
		current_y = yMax-2;
}

void hero::mvleft(){

	mvwaddch(gamewin, current_y, current_x, space);
	current_x--;
	energy -= 1;
	if(current_x < 1)
		current_x = 0;
}

void hero::mvright(){

	mvwaddch(gamewin, current_y, current_x, space);
	current_x++;
	energy -= 1;
	if(current_x > xMax-2)
		current_x = xMax-2;
}

int hero::mv(){
	int choice = wgetch(gamewin);
	switch(choice){
		case KEY_UP:
			mvup();
			break;
		case KEY_DOWN:
			mvdown();
			break;
		case KEY_LEFT:
			mvleft();
			break;
		case KEY_RIGHT:
			mvright();
			break;
		default:
			break;
	}
	return choice;
}

void hero::display(){
	mvwaddch(gamewin, current_y, current_x, character);
	wmove(gamewin, current_y, current_x);
	mvwprintw(menuwin, LINES-2, 2, "Whiffles: %d", whiffles);
	mvwprintw(menuwin, LINES-1, 2, "Energy: %d", energy);
	wrefresh(menuwin);

}





