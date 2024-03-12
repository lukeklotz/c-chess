#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "util.h"

#define ROW 8
#define COL 8

bool check_for_collision(char board[ROW][COL], char mov_col, int mov_row){
	//find numeric coordinate on board
	int col = mov_col - 'a';		
	int row = abs(mov_row - 8);

	if (board[row][col] == ' ') {
        return false; // No collision, the square is empty
    }	
	return true;
}

bool check_for_collision_path(char board[ROW][COL], char mov_col, int mov_row, char* coordinate){
	//where player moves from
	char curr_col = coordinate[1]; // a, b, c
 	int curr_row = atoi(&coordinate[2]); // 1, 2 ,3

	if (curr_col == mov_col) {
		// linear vertical move
		int curr = curr_row;

		if(curr > mov_row){
			// moving peice from the black side to the white side
			while(curr >= mov_row){
				if(!check_for_collision(board, mov_col, curr)) return true;
				printf("curr: %d\n", curr);
				curr--;
			}
			
		} else {
			// moving peice from the white side to the black side
			while(curr < mov_row){
				if(!check_for_collision(board, mov_col, curr)) return true;
				curr++;
			}
		}
	} else if(curr_row == mov_row) {
		// linear horizontal move
	} else {
		// diagonal move
	}

	return false;
}