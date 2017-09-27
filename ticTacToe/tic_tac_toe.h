#pragma once
#include <string>

struct player {
	std::string name = "";
	std::string move = "";
};

class tic_tac_toe
{
public:
	void initialize_names_and_sign(std::string name1, std::string name2, std::string player1_sign, std::string player2_sign);
	void printboard();
	bool validate_move(int);
	void make_move(int);
	bool isGameOver(int);
	std::string winner();
	void changePlayer();
	void setFirstPlayer();
	bool get_isdraw();

	tic_tac_toe();
	~tic_tac_toe();

private:
	bool is_draw = false;
	int count;
	std::string gameboard[9];
	player player1;
	player player2;
	player current_player;

};

