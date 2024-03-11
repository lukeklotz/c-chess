#include <stdlib.h>
#include <stdio.h>

void print_board(char board[8][8]){
	
	printf("\n\n+------------------+\n\n");
	
	for(int i = 0; i < 8; ++i){
		for(int j = 0; j < 8; ++j){
			printf("%-3c", board[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\n+-------------------+\n\n");
}

void clearInputBuffer(){
	int c;
    while ((c = getchar()) != '\n' && c != EOF);
}