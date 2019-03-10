#pragma once
#include<string>
class SnakeBody
{
	int xSnake;
	int ySnake;
	std::string bodyPart;
public:
	SnakeBody(int,int,std::string);
	int GetSnakeX();
	int GetSnakeY();
	std::string GetBodyPart();
	void SetSnakePoz(int, int);
	~SnakeBody();
};

