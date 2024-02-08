#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


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

	char piece = coordinate[0];
	char square = coordinate[1];
    int col_number = coordinate[2];

	
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
