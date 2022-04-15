#include <iostream>
#include <ncurses.h>

using std::cout;
using std::cin;
using std::endl;



int main(void){
	int x,y;
	cin >> y >> x;
	char v = '*';
	cout<<"Hello, Word"<<endl;
	initscr();
	move(y,x);
	addch(v);
	refresh();
	getch();
	endwin();	
return 0;
}
