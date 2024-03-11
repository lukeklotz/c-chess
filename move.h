#ifndef MOVE_H_INCLUDED
#define MOVE_FUNCS_H_INCLUDED

#define ROW 8
#define COL 8

void move_peice(char board[COL][ROW], char mov_col, int mov_row, char* coordinate);
bool movePawn(char board[ROW][COL], char mov_col, int mov_row, char* coordinate);
void choose_move(char board[ROW][COL], char *coordinate);
char *choose_piece(char board[ROW][COL]);

#endif