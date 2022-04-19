#include <iostream>
#include <ncurses.h>
#include <string>
#include <list>
#include <thread>
#include <chrono>

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
	getmaxyx(stdscr, d_rows, d_colls);
	refresh();
	getch();
	}
	endwin();
	}
	
	//~Display();
};

class Point{
   private:
   	Direction direct;
	int x, y;
	const char* elem = nullptr;
		
   public:
	Point(int x =50, int y =50, const char* input = "[*]") : x(x), y(y), elem(input) {} //constructor
	Point(const Point& point) : x(point.x),y(point.y), elem(point.elem) {} //copy constructor
	
	void Draw(){
	move(y,x);
	addstr(elem);
        }
        
        void Move(int offset, Direction dir){
        	if(dir == Direction::UP){
        		y-=offset;
        	}else if(dir == Direction::DOWN){
        		y+=offset;
        	}else if (dir == Direction::LEFT){
        		x-=offset;
        	}else if (dir == Direction::RIGTH){
        		x+=offset;
        	}
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
    	
    	//~EntityByPoint();
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

class MySnake : public EntityByPoint {
	private :
	Point head;
	Point body;
	Direction dir;
	public:
	
	MySnake(int x_head = 15, int y_head = 15, const char* head_style = "|x]", const char* body_style = "*" ,int length= 10) : head(x_head,y_head,head_style){
	         elements.push_back(head);
		for (int z = length-1; z>0; --z){
		Point body( (x_head - z), y_head, body_style);
		elements.push_back(body);
		}
	}
	
	
	void MoveSnake(Direction dir, int speed = 30, int offset = 1) {
		list<Point> new_lst;
		for (auto p : elements){
			p.Move(offset,dir);
		        new_lst.push_back(p);
		
		}
		elements.clear();
		elements = new_lst;
		
	}
	
	
};








int main(void){

	Direction dir = Direction::RIGTH;
	Display my_d;
	my_d.DWinInit();
	
	VerticalLine v_one(0,(my_d.GetRows()-1),0,"*|");
	VerticalLine v_two(0,(my_d.GetRows()-1),(my_d.GetColls()-2),"|*");
	MySnake snake(15,15,"||x}", "%", 5);
	HorizontalLine h_one(0,(my_d.GetColls()-1),0,"=");
	HorizontalLine h_two(0,(my_d.GetColls()-1),(my_d.GetRows()-1),"=");
	
	
	v_one.Draw();
	v_two.Draw();
	h_one.Draw();
	h_two.Draw();
	for (int x =0 ; x< 10'000; ++x){
	snake.MoveSnake(dir);
	snake.Draw();
	refresh();
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	
	my_d.DWinClose();
	
return 0;

}
