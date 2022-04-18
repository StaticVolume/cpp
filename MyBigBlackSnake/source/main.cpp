#include <iostream>
#include <ncurses.h>
#include <string>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::list;

enum Direction{UP,DOWN,LEFT,RIGTH};


class Point{
   private:
	int x, y;
	const char* elem = nullptr;
		
   public:
	Point(int x =50, int y =50, const char* input = "[*]") : x(x), y(y), elem(input) {} //constructor
	Point(const Point& point) : x(point.x),y(point.y), elem(point.elem) {} //copy constructor
	
	void Draw(){
	move(y,x);
	addstr(elem);
	
        }
        
};


class EntityByPoint{
  
    protected:
	list<Point> elements;
	
    public:    
    	void Draw(){
    	for (auto elem : elements){
    	elem.Draw();
    	}
    	}
};



class VerticalLine : public EntityByPoint{
	
	public:
	VerticalLine(int y_start, int y_last, int x, const char* elem){
		for (int y=y_start; y<=y_last; ++y){
			Point p(x,y,elem);
			elements.push_back(p);
		}
	}

};

class HorizontalLine : public EntityByPoint{
	
	public:
	HorizontalLine(int x_start, int x_last, int y, const char* elem){
		
		for(int x=x_start; x<=x_last; ++x){
			Point p(x,y,elem);
			elements.push_back(p);
		}
	}

};

class MySnake : public EntityByPoint{
	private :
	Point head;
	public:
	
	MySnake(int x_head, int y_head, const char* head_style, const char* body_style ,int length) : head(x_head,y_head,head_style){
	         elements.push_back(head);
		for (int z = length; z>0; --z){
		Point body( (x_head - z), y_head, body_style);
		elements.push_back(body);
		}
	}


};








int main(void){

	int row{0},col{0};
	
	
	
	initscr();
	getmaxyx(stdscr, row, col);
	
	
	VerticalLine v_one(0,(row-1),0,"*|");
	VerticalLine v_two(0,(row-1),(col-2),"|*");
	MySnake snake(15,15,"|x]", "*", 10);
	HorizontalLine h_one(0,(col-1),0,"=");
	HorizontalLine h_two(0,(col-1),(row-1),"=");
	
	
	v_one.Draw();
	v_two.Draw();
	h_one.Draw();
	h_two.Draw();
	snake.Draw();
	
	
	
	
	
	refresh();
	getch();
	endwin();
return 0;
}
