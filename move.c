#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "util.h"
#include "check.h"

#define ROW 8
#define COL 8

void move_peice(char board[COL][ROW], char mov_col, int mov_row, char* coordinate){
	//square peice moves from
	char curr_peice = coordinate[0];
	char curr_col = coordinate[1]; // a, b, c
 	int curr_row = atoi(&coordinate[2]); // 1, 2 ,3

	//find numeric coordinate on board
	int col_num = curr_col - 'a';		
	int row_num = abs(curr_row - 8);

	board[row_num][col_num] = ' ';

	col_num = mov_col - 'a';		
	row_num = abs(mov_row - 8);

	printf("mov row num: %d\n", row_num);
	printf("mov col num: %d\n", col_num);

	board[row_num][col_num] = curr_peice;
}

bool movePawn(char board[ROW][COL], char mov_col, int mov_row, char* coordinate){
	
	//square peice moves from
	char curr_col = coordinate[1]; // a, b, c
 	int curr_row = atoi(&coordinate[2]); // 1, 2 ,3

	if(curr_col == mov_col && curr_row == 2 || curr_row == 7){
		//starting position
		int mov_dist = abs(mov_row - curr_row);
		if(mov_dist < 3){
			if(check_for_collision_path(board, mov_col, mov_row, coordinate)){
				printf("valid move\n");
				move_peice(board, mov_col, mov_row, coordinate);
				return true;
			} else {
				printf("invalid move");
				return false;
			}
		}
	} else {
		int mov_dist = mov_row - curr_row;
		if(mov_dist == 1){
			printf("Move is %s!\n", check_for_collision_path(board, mov_col, mov_row, coordinate) 
			? "valid" : "invalid");
		}
	}

	return false;
}

void move_knight(char board[ROW][COL], char mov_col, int mov_row, char* coordinate){
	
	//square peice moves from
	char curr_col = coordinate[1]; // a, b, c
 	int curr_row = atoi(&coordinate[2]); // 1, 2 ,3

	printf("col: %c\n", curr_col);
	printf("row: %d\n", curr_row);

	//get valid knight moves

	printf("peice: %c", board[curr_col][curr_row]);
}
	
void choose_move(char board[ROW][COL], char *coordinate){

  	//piece to move
	char piece_to_move = coordinate[0];
	char col_to_move = coordinate[1];
 	int row_number_to_move = atoi(&coordinate[2]);
  
  	char col_letter;
  	int row_number;

	bool isValid = false;

	printf("Enter a square to move %s to", coordinate); 
		
	if (scanf("%c%d", &col_letter, &row_number) == 2) {
			printf("Col: %c\n", col_letter);
			printf("Row: %d\n", row_number);
	} else {
			printf("Invalid input format.\n");
	} 	

	if(tolower(piece_to_move) == 'p'){
		movePawn(board, col_letter, row_number, coordinate);
	}
	if(tolower(piece_to_move) == 'n'){
		//move knight
		move_knight(board, col_letter, row_number, coordinate);
	}
	clearInputBuffer();
}

bool choose_piece(char board[ROW][COL], char* coordinate){

    char piece = ' ';
  	char square = ' ';
    int col_on_board = 0;

	bool isValid = false;

    printf("Enter a string (e.g., pa4 or rb7): ");
    
	while(!isValid){
		if (scanf("%c%c%d", &piece, &square, &col_on_board) == 3) {
			printf("Letter: %c\n", piece);
			printf("Letter: %c\n", square);
			printf("Number: %d\n", col_on_board);
		} else {
			printf("Invalid input format.\n");
		} 	

		clearInputBuffer();
		
		// assign move values to coordinate
		sprintf(coordinate,  "%c%c%d", piece, square, col_on_board);

		//find numeric coordinate on board
		int row_on_board = square - 'a';		
		col_on_board = abs(col_on_board - 8);

		printf("col: %d\n", row_on_board);
		printf("num: %d\n", col_on_board);
		
		print_board(board);

		//check if the selected peice aligns with the coordinate 
		isValid = is_valid_piece(board, row_on_board, col_on_board, piece);
			
		printf("%s\n", isValid ? "exists" : "DNE");
	}

	return true;
}

