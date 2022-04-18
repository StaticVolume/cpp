#include "classes.h"


//class Point

Point::Draw(Point point){
	
	initscr();
	move(point.y,point.x);
	printw(stdscr,"%s", point.elem);
	refresh();
	getch();
	endwin();
	
}
