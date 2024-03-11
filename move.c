#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "util.h"

#define ROW 8
#define COL 8

char *choose_piece(char board[ROW][COL]){

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
	
	print_board(board);
		
	printf("%s\n", isValid ? "exists" : "DNE");
	
	return coordinate;
}