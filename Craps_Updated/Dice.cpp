/* -----------------------------------------------------------------------------
 *
 * File Name:  Dice.h
 * Description: Dice class that rolls two dice use a rng generator
 * Date: Last modified - 9 March 2020
 *
 ---------------------------------------------------------------------------- */

#include "Dice.h"

Dice::Dice() //iniatializes all member variables to zero
{
	dice1 = 0;
	dice2 = 0;
	dice_total = 0;
}

int Dice::setRoll() //found randomly on the internet
{
	srand( time(NULL) );
	dice1 = rand() % 6 + 1;
	dice2 = rand() % 6 + 1;
	dice_total = dice1 + dice2;
	return(dice_total);
}

int Dice::getRoll() //returns the value of the last thrown dice
{
	return(dice_total);
}

void Dice::Throw() //useless for the most part, prompts the user for a char
{
	char input;
	do
	{
		std::cout << "Press 'f' to roll the dice! \n";
		std::cin >> input;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Press 'F' to roll the dice! \n";
			std::cin >> input;
		}
	}while(input != 'f');
}

Dice::~Dice()
{
	//None
}
