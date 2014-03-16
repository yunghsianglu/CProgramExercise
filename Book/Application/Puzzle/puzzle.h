#ifndef PUZZLE_H
#define PUZZLE_H
// move the empty tile '-' by one step
// size: the lengh of one side, can be 2, 3, 4, 5, or 6
// state: an array of digits or characters, the
//        length of the array is size x size
// nummove: the number of steps
// moves: each element is one the four letters 'D', 'U', 'L', or 'R'
// The function returns 0 if the move fails.  The function
//     returns 1 if the move succeeds.
// This function modifies the elements in state

int moveTiles(int size, char * state, int nummove, char * moves);

// find all reachable states from srcstate after moving
// nummove steps
// size: the lengh of one side, can be 2, 3, 4, 5, or 6
// srcstate: an array of digits or characters, the
//           length of the array is size x size
//           srcstate is unchanged in the function
// nummove: the number of moves, each move can be one of the four
//          letters 'D', 'U', 'L', or 'R'
// numstate: the address to store the number of reachable states 
// The function returns a two-dimensional array with (* numstate) rows
// the length of each row is size x size; the rows must be distinct
// allStates allocates memory for deststate

char * * allStates(int size, const char * srcstate, int nummove, 
		   int * numstate);

// find one solution from srcstate to the solved state within
// maxmove steps
// size: the lengh of one side, can be 2, 3, 4, 5, or 6
// srcstate: an array of digits or characters, the
//           length of the array is size x size
//           srcstate is unchanged in the function
// maxmove: the maximum number of moves
// nummove: the address to store the actual number of moves
//          * nummove must not exceed maxmove
// moves: the steps, the call is responsible allocating 
//        the memory for moves. This array must have at least
//        maxmove elements

void solve(int size, const char * srcstate, int maxmove, 
	   int * nummove, char * moves);

#endif

