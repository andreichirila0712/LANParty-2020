#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip>

class Player
{
private:
	std::string firstName;
	std::string secondName;
	int points;
public:
	Player();
	Player(std::string, std::string, int);
	friend std::ostream& operator<<(std::ostream&, const Player&);
	Player(const Player&);
	void afisare() const;
	int getPunctaj();
	void crestePunctaj();
};