#ifndef CHECK_H_INCLUDED
#define CHECK_H_INCLUDED

#define ROW 8
#define COL 8

bool check_for_collision(char board[ROW][COL], char mov_col, int mov_row);
bool check_for_collision_path(char board[ROW][COL], char mov_col, int mov_row, char* coordinate);
bool is_valid_piece(char board[ROW][COL],int row_on_board, int col_on_board, char piece);

#endif