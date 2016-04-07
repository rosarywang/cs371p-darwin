#include "Creature.h"

	Creature::Creature() {
		this->moved = true;
		this->index = -1;
	}

	Creature::Creature(Species sp, int row, int col, int dir, int max_row, int max_col, int index){
		assert(row >= 0);
		assert(col >= 0);
		assert(row < max_row);
		assert(col < max_col);
		assert(max_row > 0);
		assert(max_col > 0);
		assert(dir >= 0);
		assert(dir < 4);
		assert(index >= 0);
		this->sp = sp;
		this->row = row;
		this->col = col;
		this->dir = dir;
		this->pc = 0;
		this->moved = false;
		this->max_row = max_row;
		this->max_col = max_col;
		this->index = index;
	}

	int Creature::get_index() {
		assert(this->index >= 0);
		return this->index;
	}

	char Creature::get_species() {
		assert(this->sp.get_initial() != '\0');
		return this->sp.get_initial();
	}

	bool Creature::check_same_species(Creature c){
		return this->sp.get_initial() == (c.sp).get_initial();
	}

	void Creature::reset_moved() {
		if(this->index > -1)
			this->moved = false;
	}

	void Creature::read_instruction(Darwin* darwin){
		if(!this->moved) {
			assert(this->pc >= 0);
			assert(this->sp[this->pc] >= 0);
			int n = this->sp[this->pc]/10;	
			switch(this->sp[this->pc]%10){
				case 0:
					hop(darwin);
					break;
				case 1:
					left();
					break;
				case 2:
					right();
					break;
				case 3:
					infect(darwin);
					break;
				case 4:
					if_empty(darwin, n);
					break;
				case 5:
					if_wall(darwin, n);
					break;
				case 6:
					if_random(darwin, n);
					break;
				case 7:
					if_enemy(darwin, n);
					break;
				case 8:
					go(darwin, n);
					break;
			}
		}
	}

	void Creature::hop(Darwin* darwin){
		assert(this->row >= 0);
		assert(this->col >= 0);
		assert(this->row < this->max_row);
		assert(this->col < this->max_col);
		assert(!this->moved);
		int oldR = this->row;
		int oldC = this->col;
		if(darwin->is_empty(this->row, this->col, this->dir)) {
			switch(this->dir){
				case 1:
					if(this->row > 0)
						--this->row;
					break;
				case 2:
					if(this->col < this->max_col-1)
						++this->col;
					break;
				case 3:
					if(this->row < this->max_row-1)
						++row;
					break;
				case 0:
					if(this->col > 0 )
						--this->col;
					break;
			}
		}
		this->moved = true;
		++this->pc;
		darwin->update_board(*this, oldR, oldC, this->row, this->col);
	}

	void Creature::left(){
		assert(!this->moved);
		this->dir = (this->dir+3)%4;
		this->moved = true;
		++this->pc;
		assert(this->dir >= 0);
		assert(this->dir < 4);
	}

	void Creature::right(){
		assert(!this->moved);
		this->dir = (this->dir+1)%4;
		this->moved = true;
		++this->pc;
		assert(this->dir >= 0);
		assert(this->dir < 4);
	}

	void Creature::infect(Darwin* darwin){
		assert(!this->moved);
		Creature& e = darwin->get_enemy(*this, this->row, this->col, this->dir);
		e.sp = Species(this->sp);
		e.pc = 0;
		this->moved = true;
		++this->pc;
		assert(this->pc >= 0);
		assert((e.sp).get_initial() == this->sp.get_initial());
	}

	void Creature::if_empty(Darwin* darwin, int n){
		bool empty = darwin->is_empty(this->row, this->col, this->dir);
		if(empty)
			this->pc = n;
		else
			++this->pc;
		assert(this->pc >= 0);
		read_instruction(darwin);
	}

	void Creature::if_wall(Darwin* darwin, int n){
		bool wall = darwin->is_wall(this->row, this->col, this->dir);
		if(wall)
			this->pc = n;
		else
			++this->pc;
		assert(this->pc >= 0);
		read_instruction(darwin);
	}

	void Creature::if_random(Darwin* darwin, int n){
		int r = rand();
		if(r % 2 == 0)
			++this->pc;
		else
			this->pc = n;
		assert(this->pc >= 0);
		read_instruction(darwin);
	}

	void Creature::if_enemy(Darwin* darwin, int n){
		bool enemy = darwin->is_enemy(*this, this->row, this->col, this->dir);
		if(enemy){
			this->pc = n;
		}
		else{
			++this->pc;
		}
		assert(this->pc >= 0);
		read_instruction(darwin);
	}

	void Creature::go(Darwin* darwin, int n){
		this->pc = n;
		assert(this->pc >= 0);
		read_instruction(darwin);
	}