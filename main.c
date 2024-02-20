#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


#define ROW 8
#define COL 8

char* choose_piece(char* board[ROW][COL]){

    char piece;
  	char square;
    int col_number;

	bool isValid = false;

    printf("Enter a string (e.g., pa4 or rb7): ");
    
    if (scanf("%c%c%d", &piece, &square, &col_number) == 3) {
		printf("Letter: %c\n", piece);
		printf("Letter: %c\n", square);
		printf("Number: %d\n", col_number);
    } else {
		printf("Invalid input format.\n");
    } 	
	
	// return coordinate 	
	char* coordinate = malloc(5);
	sprintf(coordinate,  "%c%c%d", piece, square, col_number);


	//clear buffer
	int c;
    while ((c = getchar()) != '\n' && c != EOF);


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
	
void choose_move(char* coordinate){

  //piece to move
	char piece_to_move = coordinate[0];
	char col_to_move = coordinate[1];
 	int row_number_to_move = atoi(&coordinate[2]);
  
  char col_number;
  int row_number;

	bool isValid = false;

  printf("Enter a square to move %s to", coordinate); 
    
  if (scanf("%c%c%d", &col_number, &row_number) == 2) {
		printf("Letter: %c\n", col_number);
		printf("Number: %d\n", row_number);
  } else {
		printf("Invalid input format.\n");
  } 	
  

  if(toLowerCase(piece_to_move) == 'p'){
    //pawn
    //can move 2 squares from start 
    //one square if no peice
    if(square == square_to_move && ){
    }
  }
  if(toLowerCase(piece_to_move) == 'n'){
  
  }
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
	choose_move(coordinate);
		
	}
}
