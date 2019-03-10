#pragma once
#include <string>
#include "SnakeBody.h"
#include<vector>

class Board
{
private:
	std::vector<SnakeBody>snake;
	int moveX;
	int moveY;
	int X;
	int Y;
	int width;
	int height;
	int fruitX;
	int fruitY;
	bool movingX;
	bool movingY;
	int score;
	std::string **board;
public:
	Board(int,int);
	void ShowBoard();
	void PutSnake();
	bool Update();
	void PutFruit();
	void AddBodyPart();
	bool ChedkIfBite();
	~Board();
};

