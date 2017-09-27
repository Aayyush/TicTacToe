#include "tic_tac_toe.h"
#include <string>
#include <iostream>



tic_tac_toe::tic_tac_toe()
{
	for (int x = 0; x <= 8; x++) {
		gameboard[x] = std::to_string(x);
	}
}

void tic_tac_toe::initialize_names_and_sign(std::string name1 = "player1", std::string name2 = "player2", std::string sign1 = "O", std::string sign2 = "X") {
	player1.name = name1;
	player1.move = sign1;
	player2.name = name2;
	player2.move = sign2;
	setFirstPlayer();
}

bool tic_tac_toe::validate_move(int numb) {
	if (numb >= 0 && numb <= 8 && gameboard[numb] == std::to_string(numb)) {
		return true;
	}
	else {
		return false;
	}
}

void tic_tac_toe::make_move(int numb) {
	if (validate_move(numb)) {
		gameboard[numb] = current_player.move;
	}
}

bool tic_tac_toe::isGameOver(int counter) {
	if ((gameboard[0] == gameboard[1] && gameboard[0] == gameboard[2]) ||
		(gameboard[3] == gameboard[4] && gameboard[4] == gameboard[5]) ||
		(gameboard[6] == gameboard[7] && gameboard[7] == gameboard[8]) ||
		(gameboard[0] == gameboard[3] && gameboard[3] == gameboard[6]) ||
		(gameboard[1] == gameboard[4] && gameboard[4] == gameboard[7]) ||
		(gameboard[2] == gameboard[5] && gameboard[5] == gameboard[8]) ||
		(gameboard[0] == gameboard[4] && gameboard[4] == gameboard[8]) ||
		(gameboard[2] == gameboard[4] && gameboard[4] == gameboard[6])) {
		return true;
	}
	else if (counter == 9) {
		is_draw = true;
		return true;
	}
	else {
		return false;
	}

}

void tic_tac_toe::printboard() {
	for (int x = 0; x < 9; x++) {
		if (x % 3 == 0) {
			std::cout << std::endl;
		}
		std::cout << " | " << gameboard[x] << " | ";
	}
	std::cout << std::endl;
	std::cout << "Turn for:  " << current_player.name << " using move: " << current_player.move << std::endl;
}

void tic_tac_toe::changePlayer() {
	if (current_player.name == player1.name) {
		current_player = player2;
	}
	else {
		current_player = player1;
	}
}

void tic_tac_toe::setFirstPlayer() {
	int random_number = rand() % 2;
	if (random_number == 1) current_player = player1;
	else current_player = player2;
}

std::string tic_tac_toe::winner() {
	return current_player.name;
}

bool tic_tac_toe::get_isdraw() {
	return is_draw;
}
tic_tac_toe::~tic_tac_toe()
{
}
