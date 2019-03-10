#include "pch.h"
#include "Board.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<Windows.h>


Board::Board(int width,int height)
{
	this->moveX = 0;
	this->moveY = 0;
	this->width = width;
	this->height = height;
	this->X = this->width / 2;
	this->Y = this->height / 2;
	this->fruitX = width / 3;
	this->fruitY = height / 3;
	this->movingX = true;
	this->movingY = true;
	this->score = 0;
	board = new std::string*[this->height];
	for (int i = 0; i < this->height; i++) {
		board[i] = new std::string[this->width];
	}
	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++) {
			if (i == 0 || j == 0 || i == this->height-1 || j == this->width-1) {
				board[i][j] = " #";

			}else{
				board[i][j] = "  ";

			}
		}
	}
	SnakeBody a(this->X, this->Y, " O");
	this->snake.push_back(a);

}

void Board::ShowBoard() {
	std::vector<SnakeBody>::iterator it;
	int size = this->snake.size();
	int index = 0;
	bool putSpace = true;
	std::string toPrint = "";
	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++) {
			if (index != size) {
				for (it = this->snake.begin(); it != this->snake.end(); ++it) {
					if (it->GetSnakeX() == j && it->GetSnakeY() == i) {
						toPrint.append(it->GetBodyPart());
						putSpace = false;
						index++;
						break;
					}

				}
			}
			if (putSpace == true) {
				toPrint.append(board[i][j]);
			}
			putSpace = true;
		}
		toPrint.append("\n");
	}
	toPrint.append("\nSCORE : ");
	toPrint.append(std::to_string(this->score));
	std::cout << toPrint;

}


void Board::PutSnake() {
	int x, y,prevX,prevY;
	std::vector<SnakeBody>::iterator it = this->snake.begin();
	prevX = it->GetSnakeX();
	prevY = it->GetSnakeY();
	it->SetSnakePoz(this->X + moveX, this->Y + moveY);
	++it;
	for (; it != this->snake.end(); ++it) {
		x = it->GetSnakeX();
		y = it->GetSnakeY();
		it->SetSnakePoz(prevX,prevY);
		prevX = x;
		prevY = y;

	}
}

void Board::AddBodyPart() {
	if (this->board[this->Y][this->X] == " F") {
		SnakeBody a(this->X, this->Y," o");
		this->snake.push_back(a);
		board[this->Y][this->X] = "  ";
		srand(time(0));
		int tmp = rand();
		this->fruitX = (tmp % (width - 2)) + 1;
		tmp = rand();
		this->fruitY = (tmp % (height- 2)) + 1;
		this->score++;
		PutFruit();
	}
}

bool Board::Update() {
	if (GetAsyncKeyState('W') & 0x8000 && this->movingY == true)
	{
		this->moveY = -1;
		this->moveX = 0;
		this->movingY = false;
		this->movingX = true;

	}

	if (GetAsyncKeyState('S') & 0x8000 && this->movingY == true)
	{
		this->moveY = 1;
		this->moveX = 0;
		this->movingY = false;
		this->movingX = true;

	}
	if (GetAsyncKeyState('A') & 0x8000 && this->movingX == true)
	{
		this->moveY = 0;
		this->moveX = -1;
		this->movingY = true;
		this->movingX = false;
	}

	if (GetAsyncKeyState('D') & 0x8000 && this->movingX == true)
	{
		this->moveY = 0;
		this->moveX = 1;
		this->movingY = true;
		this->movingX = false;
	}
	PutSnake();
	AddBodyPart();
	this->X += moveX;
	this->Y += moveY;
	if (ChedkIfBite()) {
		return false;
	}
	if (this->Y == 0 || this->X == 0 || this->X == this->width-1 || this->Y == this->height-1) {
		return false;
	}


	return true;

}

void Board::PutFruit() {
	board[fruitY][fruitX] = " F";
}

bool Board::ChedkIfBite() {
	std::vector<SnakeBody>::iterator it = this->snake.begin();
	++it;
	for (; it != this->snake.end(); ++it) {
		if (this->X == it->GetSnakeX() && this->Y == it->GetSnakeY()) {
			return true;
		}
	}
	return false;
}

Board::~Board()
{
	delete[]board;
}
