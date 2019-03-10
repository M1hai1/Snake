#include "pch.h"
#include "SnakeBody.h"


SnakeBody::SnakeBody(int xSnake,int ySnake,std::string bodyPart)
{
	this->bodyPart = bodyPart;
	this->xSnake = xSnake;
	this->ySnake = ySnake;
}

int SnakeBody::GetSnakeX() {
	return this->xSnake;
}

void SnakeBody::SetSnakePoz(int xSnake,int ySnake) {
	this->ySnake = ySnake;
	this->xSnake = xSnake;
}

std::string  SnakeBody::GetBodyPart() {
	return this->bodyPart;
}

int SnakeBody::GetSnakeY() {
	return this->ySnake;
}

SnakeBody::~SnakeBody()
{
}
