#include <iostream>
#include <ncurses.h>
#include <string>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::list;

enum Direction {UP, DOWN, LEFT,RIGTH};



class Display{
	private:
	unsigned int d_rows;
	unsigned int d_colls;
	char stop_button;
	
	public:
	
	Display(char input_stop_button = 'p' ):stop_button(input_stop_button){}
	
	unsigned int GetRows(){return d_rows;}
	unsigned int GetColls(){return d_colls;}
	
	void DWinInit(){
	initscr();
	getmaxyx(stdscr, d_rows, d_colls);
	noecho();
	curs_set(0);
	}
	
	
	void DWinClose(){
	refresh();
	while (getch()!='p'){
	getch();
	refresh();
	}
	endwin();
	}
	
	//~Display();
};

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
        
        void Resize(){
        	
        }
        //~Point (){}
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
    	
    	//virtual ~EntityByPoint();
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
	Direction dir;
	public:
	
	MySnake(int x_head = 15, int y_head = 15, const char* head_style = "|x]", const char* body_style = "*" ,int length= 10) : head(x_head,y_head,head_style){
	         elements.push_back(head);
		for (int z = length; z>0; --z){
		Point body( (x_head - z), y_head, body_style);
		elements.push_back(body);
		}
	}
	
	
	void Move(Direction dir, int speed = 30) {
		if(dir == RIGTH){
		 elements.pop_front();
		 elements.pop_back();
		 elements.push_back(head);
		}
	}
	
	


};








int main(void){

	//Direction dir;
	Display my_d;
	my_d.DWinInit();
	
	VerticalLine v_one(0,(my_d.GetRows()-1),0,"*|");
	VerticalLine v_two(0,(my_d.GetRows()-1),(my_d.GetColls()-2),"|*");
	MySnake snake(15,15,"|x]", "*", 10);
	HorizontalLine h_one(0,(my_d.GetColls()-1),0,"=");
	HorizontalLine h_two(0,(my_d.GetColls()-1),(my_d.GetRows()-1),"=");
	
	//snake.Move( dir.RIGTH, 300);
	v_one.Draw();
	v_two.Draw();
	h_one.Draw();
	h_two.Draw();
	snake.Draw();
	
	my_d.DWinClose();
	
return 0;
}
