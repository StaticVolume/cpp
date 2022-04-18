#pragma once
#include <iostream>
#include <string>
#include <list>


using std::cout;
using std::cin;
using std::endl;
using std::string;



Class Point{
   private:
	int x,int y;
	string elem;
	Point(){};
		
   public:
	Point(int x =15, int y =15, string elem = "*") : this->x(x), this->y(y),this->elem(elem) {}; //constructor
	Point(Point point) : this->x(point.x),this->y(point.y), this->elem(point.elem) {}; //copy constructor
	
     void Draw(Point point){
	initscr();
	move(point.y,point.x);
	printw(stdscr,"%s", point.elem);
	refresh();
	getch();
	endwin();

}



	
};



Class EntityByPoint{
	

};




