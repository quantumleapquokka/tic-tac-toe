Design Process:
I started by going through the functions of the TicTacToe.cpp file to see what needed to be completed, then skimming through every other cpp file to familiarize myself with the functions and code. I started with board setup and tested if that worked, then moved onto setting a piece clicked and testing that. Basically, after each test, I tested if it was functioning, then I moved onto the checkForWinner and checkForDraw functions so the game was playable with an end.
Extra credit AI: it just randomly generates a move.

ADDED NEGAMAX CODE FOR SECOND ASSIGNMENT:
The negamax algorithm implemented searches all the way to terminal states by converting the current board into a state string, then iterating over all legal moves, uses the negamax function to use recursion to evaluate each possible ending game state, then assigns scores to terminal states, and finally chooses the move with the highest score. the chosen move is passed onto the actual AI's move that is then applied to the actual game board, which then ends its turn afterwards.

Platform: Windows