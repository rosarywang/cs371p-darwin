using namespace std;
#include <cstdlib>
#include "Species.h"

class Creature {
private:
	Species s;
	int pc;
	bool moved;
	int row;
	int col;
	int dir;
	int max_row;
	int max_col;

public:
	Creature(Species sp, int x, int y, int d, int mr, int mc){
		s = sp;
		row = x;
		col = y;
		dir = d;
		pc = 0;
		moved = false;
		max_row = mr;
		max_col = mc;
	}

	//instructions function
	void readInstruction(){
		int n = this.s[pc]/10;
		switch(this.s[pc]%10){
			case 0:
				hop();
				break;
			case 1:
				left();
				break;
			case 2:
				right();
				break;
			case 3: 
				infect();
				break;
			case 4:
				if_empty(n);
				break;
			case 5:
				if_wall(n);
				break;
			case 6:
				if_random(n);
				break;
			case 7:
				if_enemy(n);
				break;
			case 8:
				go(n);
				break;
		}
	}

	void hop(){
		switch(dir){
			case 0:
				if(row > 0)
					--row;
				break;
			case 1:
				if(col < max_col-1)
					++col;
				break;
			case 2:
				if(row < max_row-1)
					++row;
				break;
			case 3:
				if(col > 0 )
					--col;
				break;
		}
		moved = true;
	}

	void left(){
		dir = (dir+3)%4;
		moved = true;
	}

	void right(){
		dir = (dir+1)%4;
		moved = true;
	}

	void infect(){
		bool infect = Darwin.infect(this);
	}

	void if_empty(int n){
		bool empty = Darwin.if_empty(this);
	}

	void if_wall(int n){
		switch(dir){
			case 0:
				if(row > 0)
					pc = n;
				break;
			case 1:
				if(col < max_col-1)
					pc = n;
				break;
			case 2:
				if(row < max_row-1)
					pc = n;
				break;
			case 3:
				if(col > 0 )
					pc = n;
				break;
			default:
				++pc;
		}
		readInstruction();
	}

	void if_random(int n){
		int r = rand();
		if(r % 2 == 0)
			++pc;
		else
			pc = n;
		readInstruction();
	}

	void if_enemy(int n){
		bool enemy = Darwin.if_enemy(this);
	}

	void go(int n){
		pc = n;
		readInstruction();
	}
}