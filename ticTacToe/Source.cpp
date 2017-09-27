#include <iostream>
#include <string>
#include "tic_tac_toe.h"

int main() {
	int counter = 0;
	int index;
	tic_tac_toe newGame;
	newGame.initialize_names_and_sign("Aayush", "Bipul", "X", "O");
	while (!(newGame.isGameOver(counter))) {
		counter++;
		std::cout << counter;
		newGame.changePlayer();
		newGame.printboard();
		do {
			std::cout << "Enter the index in range(0-8): ";
			std::cin >> index;
		} while (!(newGame.validate_move(index)));
		newGame.make_move(index);
	}
	if (newGame.get_isdraw()) {
		std::cout << "This is a draw.";
	}
	else {
		std::cout << "The winner is: " << newGame.winner() << std::endl;
	}

}