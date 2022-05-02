#include "Player.hpp"

Player::Player()
{
	points = 0;
	firstName = "";
	secondName = "";
}

Player::Player(std::string firstName, std::string secondName, int points)
{
	this->firstName = firstName;
	this->secondName = secondName;
	this->points = points;
}

std::ostream& operator<<(std::ostream& os, const Player& data)
{
	os << data.firstName << " " << data.secondName << " " << data.points << std::endl;
	return os;
}

Player::Player(const Player& data)
{
	this->firstName = data.firstName;
	this->secondName = data.secondName;
	this->points = data.points;
}

void Player::afisare() const
{
	std::cout << firstName << " " << secondName << " " << points << std::endl;
}

int Player::getPunctaj()
{
	return points;
}

void Player::crestePunctaj()
{
	this->points = this->points + 1;
}