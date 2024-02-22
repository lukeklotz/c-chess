
	if(tolower(piece_to_move) == 'p'){
		//pawn
		//can move 2 squares from start 
		//one square if no peice
		movePawn(board, col_letter, row_number);
	}
	if(piece_to_move == 'n'){
		//move knight
	}

	clearInputBuffer();