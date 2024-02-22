#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdbool.h>


#define ROW 8
#define COL 8

void clearInputBuffer(){
	int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

char* choose_piece(char* board[ROW][COL]){

    char piece = ' ';
  	char square = ' ';
    int col_number = 0;

	bool isValid = false;

    printf("Enter a string (e.g., pa4 or rb7): ");
    
    if (scanf("%c%c%d", &piece, &square, &col_number) == 3) {
		printf("Letter: %c\n", piece);
		printf("Letter: %c\n", square);
		printf("Number: %d\n", col_number);
    } else {
		printf("Invalid input format.\n");
    } 	

	clearInputBuffer();
	
	// return coordinate 	
	char* coordinate = malloc(5);
	sprintf(coordinate,  "%c%c%d", piece, square, col_number);


	//find numeric coordinate on board
	int row_on_board = square - 'a';		
	col_number = abs(col_number - 8);

	printf("col: %d\n", row_on_board);
	printf("num: %d\n", col_number);
	
	printf("\n\n+------------------+\n\n");
	
	for(int i = 0; i < ROW; ++i){
		for(int j = 0; j < COL; ++j){
			if (i == col_number  && j == row_on_board && *board[i][j] == piece){
				printf("%-3s", "X");
				isValid = true;
			} else {
				printf("%-3s", board[i][j]);
			}
		}
		printf("\n");
	}
	
	printf("%s\n", isValid ? "exists" : "DNE");
	
	printf("\n\n+-------------------+\n\n");
	
	return coordinate;

}

void print_board(char* board[ROW][COL]){
	
	printf("\n\n+------------------+\n\n");
	
	for(int i = 0; i < ROW; ++i){
		for(int j = 0; j < COL; ++j){
			printf("%-3s", board[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\n+-------------------+\n\n");
}

bool check_for_collision(char *board[ROW][COL], char mov_col, int mov_row){
	//find numeric coordinate on board
	int col = mov_col - 'a';		
	int row = abs(mov_row - 8);

	//printf("row: %d", row);
	//printf("\ncol: %d", col);

	if(board[row][col] == "") return false;
	
	return true;
}

bool check_for_collision_path(char *board[ROW][COL], char mov_col, int mov_row, char* coordinate){
	//where player moves from
	char curr_col = coordinate[1]; // a, b, c
 	int curr_row = atoi(&coordinate[2]); // 1, 2 ,3

	if (curr_col == mov_col) {
		// linear vertical move
		int curr = curr_row;
		while(curr < mov_row){
			if(!check_for_collision(board, mov_col, curr)) return true;
			curr++;
		}
	} else if(curr_row == mov_row) {
		// linear horizontal move
	} else {
		// diagonal move
	}

	return false;
}

void move_peice(char* board[ROW][COL], char mov_col, int mov_row, char* coordinate){
	//square peice moves from
	char curr_peice = coordinate[0];
	char curr_col = coordinate[1]; // a, b, c
 	int curr_row = atoi(&coordinate[2]); // 1, 2 ,3

	//find numeric coordinate on board
	int row_num = curr_row - 'a';		
	char col_num = abs(curr_col - 8);

	printf("row num: %d\n", row_num);
	printf("col num: %d\n", col_num);

	board[row_num][col_num] == NULL;

	row_num = mov_row - 'a';		
	col_num = abs(mov_col - 8);

	board[row_num][col_num] == &curr_peice;
	
}

bool movePawn(char* board[ROW][COL], char mov_col, int mov_row, char* coordinate){
	
	//square peice moves from
	char curr_col = coordinate[1]; // a, b, c
 	int curr_row = atoi(&coordinate[2]); // 1, 2 ,3

	if(curr_col == mov_col && curr_row == 2){
		//starting position
		int mov_dist = mov_row - curr_row;
		if(mov_dist <= 3){
			if(check_for_collision_path(board, mov_col, mov_row, coordinate)){
				printf("valid move\n");
				//move peice
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

	//if curr_col == 2, then move 1 or 2 spaces is valid

	//printf("\n moving: %c%d", curr_col, curr_row);
	//printf("\n to: %c%d\n", mov_col, mov_row);

	return false;
}
	
void choose_move(char* board[ROW][COL], char* coordinate){

  	//piece to move
	char piece_to_move = coordinate[0];
	char col_to_move = coordinate[1];
 	int row_number_to_move = atoi(&coordinate[2]);
  
  	char col_letter;
  	int row_number;

	bool isValid = false;

	printf("Enter a square to move %s to", coordinate); 
		
	if (scanf("%c%d", &col_letter, &row_number) == 2) {
			printf("Letter: %c\n", col_letter);
			printf("Number: %d\n", row_number);
	} else {
			printf("Invalid input format.\n");
	} 	


	if(tolower(piece_to_move) == 'p'){
		//pawn
		//can move 2 squares from start 
		//one square if no peice
		movePawn(board, col_letter, row_number, coordinate);
	}
	if(piece_to_move == 'n'){
		//move knight
	}

	clearInputBuffer();
	//TODO: check if square is valid to move to
	//TODO: if peice between peice and dest square, the peice cannot move, unless its a knight
	//TODO: check if peice can move in specified direction (knights in L shape, rooks up and down etc..)
}

int main() {
	char* coordinate = malloc(5);
	char *board[ROW][COL] = {
        	{"r", "n", "b", "q", "k", "b", "n", "r"},
        	{"p", "p", "p", "p", "p", "p", "p", "p"},
        	{"", "", "", "", "", "", "", ""},
        	{"", "", "", "", "", "", "", ""},
        	{"", "", "", "", "", "", "", ""},
        	{"", "", "", "", "", "", "", ""},
        	{"P", "P", "P", "P", "P", "P", "P", "P"},
        	{"R", "N", "B", "Q", "K", "B", "N", "R"},
    	};	
	
	bool gameover = false;
	
	print_board(board);

	while(!gameover){
	coordinate = choose_piece(board);		
	choose_move(board, coordinate);
		
	}
}
