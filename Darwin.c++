using namespace std;

#include "Darwin.h"

	Darwin::Darwin(int rows, int cols) {
		this->rows = rows;
		this->cols = cols;
	}

	void Darwin::addCreature(Creature& c, int row, int col){
		creatures.push_back(c);
		board[row][col] = creatures.size()-1;
	}

	// Creature Darwin::infect(Creature c){
	// 	return null;
	// }