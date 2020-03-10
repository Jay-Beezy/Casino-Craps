/* -----------------------------------------------------------------------------
 *
 * File Name:  Executive.cpp
 * Description: Executive class that executes the craps program, using the
 *              Dice and crapsDriver classes.
 * Date: Last modified - 9 March 2020
 *
 ---------------------------------------------------------------------------- */

#include "Executive.h"

void Executive::run()
{
	Dice myDice;
	crapsDriver myCraps;

	std::cout << "Minimum bet is : " << myCraps.getMin() << "\n";
	std::cout << "Maximium bet is : " << myCraps.getMax() << "\n";

	myCraps.setTotal();
	myCraps.setPassBet();
	myDice.Throw();
	std::cout << "You rolled a : " << myDice.setRoll() << "\n";
	if(myDice.getRoll() == 7 || myDice.getRoll() == 11)
	{
		myCraps.comeoutPassPayout();
		std::cout << "Total is currently : " << myCraps.getTotal() << "\n";
		comeoutRoll(myCraps, myDice);
	}
	else if (myDice.getRoll() == 2 || myDice.getRoll() == 3 || myDice.getRoll() == 12)
	{
		myCraps.comeoutPassTakeout();
		std::cout << "Total is currently : " << myCraps.getTotal() << "\n";
		comeoutRoll(myCraps, myDice);
	}
	else
	{
		int tempPoint = 0;
		std::cout << "The established point is : " << myDice.getRoll() << "\n";
		tempPoint = myDice.getRoll();
		myCraps.setPoint(tempPoint);
		userMenu(myCraps, myDice);
	}
}

void Executive::comeoutRoll(crapsDriver origCraps, Dice origDice)
{
	origDice.Throw();
	std::cout << "You rolled a : " << origDice.setRoll() << "\n";
	if(origDice.getRoll() == 7 || origDice.getRoll() == 11)
	{
		origCraps.comeoutPassPayout();
		std::cout << "Total is currently : " << origCraps.getTotal() << "\n";
		comeoutRoll(origCraps, origDice);
	}
	else if (origDice.getRoll() == 2 || origDice.getRoll() == 3 || origDice.getRoll() == 12)
	{
		origCraps.comeoutPassTakeout();
		std::cout << "Total is currently : " << origCraps.getTotal() << "\n";
		comeoutRoll(origCraps, origDice);
	}
	else
	{
		int tempPoint = 0;
		std::cout << "The established point is : " << origDice.getRoll() << "\n";
		tempPoint = origDice.getRoll();
		origCraps.setPoint(tempPoint);
		userMenu(origCraps, origDice);
	}
}

void Executive::userMenu(crapsDriver origCraps, Dice origDice)
{
	int userChoice = 0;
	std::cout << "1.) Set a pass line bet \n";
	std::cout << "2.) Set an odds bet \n";
	std::cout << "3.) Set a field bet \n";
	std::cout << "4.) Set a place bet \n";
	std::cout << "5.) Roll the dice \n";
	std::cout << "Choice : ";
	std::cin >> userChoice;
	while ( std::cin.fail() || userChoice <= 0 || userChoice > 5 )
	{
	   std::cin.clear();
	   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	   std::cout << "Choice: ";
	   std::cin >> userChoice;
	}
	if(userChoice == 1)
	{
		origCraps.setPassBet();
		userMenu(origCraps, origDice);
	}
	else if (userChoice == 2)
	{
		origCraps.setOddsBet(origCraps.getPoint());
		userMenu(origCraps, origDice);
	}
	else if (userChoice == 3)
	{
		origCraps.setFieldBet();
		userMenu(origCraps, origDice);
	}
	else if (userChoice == 4)
	{
		origCraps.setPlaceBet();
		userMenu(origCraps, origDice);
	}
	else if (userChoice == 5)
	{
		char charInput;
		origCraps.receipt();
		std::cout << "Is everything correct? (y/n) : ";
		std::cin >> charInput;
		if (charInput == 'y')
		{
			gameLoop(origCraps, origDice);
		}
		else
		{
			userMenu(origCraps, origDice);
		}
	}
}

void Executive::gameLoop(crapsDriver origCraps, Dice origDice)
{
	origDice.Throw();
	std::cout << "You rolled a : " << origDice.setRoll() << "\n";
	int dice = 0;
	dice = origDice.getRoll();
	char charInput;

	if (dice == 7) //if the user craps out
	{
		origCraps.passTakeout(7);
		origCraps.crapTakeout(7);
		std::cout << "|=|=|=|=|=|=|=|=|=|" << "\n";
		std::cout << "=|=| C R A P S |=|=" << "\n";
		std::cout << "|=|=|=|=|=|=|=|=|=|" << "\n";

		std::cout << "** You lost " << origCraps.getTotalBets() << " **\n";

		origCraps.resetBets(); //reset the data of all previous bets

		std::cout << "Your current total is : " << origCraps.getTotal() <<"\n";
		std::cout << "Your starting total was : " << origCraps.getStartTotal() <<"\n";

		std::cout << "Do you want to continue playing? (y/n) : ";
		std::cin >> charInput;
		if (charInput != 'n')
		{
			origCraps.setPassBet();
			origDice.Throw();
			if(origDice.getRoll() == 7 || origDice.getRoll() == 11)
			{
				origCraps.comeoutPassPayout();
				std::cout << "Total is currently : " << origCraps.getTotal() << "\n";
				comeoutRoll(origCraps, origDice);
			}
			else if (origDice.getRoll() == 2 || origDice.getRoll() == 3 || origDice.getRoll() == 12)
			{
				std::cout << "You rolled a : " << origDice.setRoll() << "\n";
				origCraps.comeoutPassTakeout();
				std::cout << "Total is currently : " << origCraps.getTotal() << "\n";
				comeoutRoll(origCraps, origDice);
			}
			else
			{
				int tempPoint = 0;
				std::cout << "You rolled a : " << origDice.setRoll() << "\n";
				std::cout << "The established point is : " << origDice.getRoll() << "\n";
				tempPoint = origDice.getRoll();
				origCraps.setPoint(tempPoint);
				userMenu(origCraps, origDice);
			}
		}
		std::cout << "Thanks for playing! \n";
	}
	else if (dice == 2)
	{
		origCraps.fieldPayout(2); //field bet is automatically reset
		userMenu(origCraps, origDice);
	}
	else if (dice == 3)
	{
		origCraps.fieldPayout(3);
		userMenu(origCraps, origDice);
	}
	else if (dice == 4)
	{
		origCraps.fieldPayout(4); //pays out the field
		if (dice == origCraps.getPoint()) //Pays out the pass line and odds bet
		{
			origCraps.passPayout(4);
			origCraps.resetBets(); //sets all previous bets to zero
			std::cout << "Your current total is : " << origCraps.getTotal() <<"\n";
			std::cout << "Do you want to continue playing? (y/n) : ";
			std::cin >> charInput;
			if (charInput != 'y')
			{
				std::cout << "Your current total was : " << origCraps.getTotal() << "\n";
				std::cout << "Your starting total was : " << origCraps.getStartTotal() << "\n";
				std::cout << "Goodbye! \n";
			}
			else
			{
				origCraps.setPassBet();
				comeoutRoll(origCraps, origDice);
			}
		}
		else //if the dice ISNT the point
		{
			if(origCraps.getPlaceBet4() > 0) //if there is a place bet
			{
				origCraps.placePayout(4); //pays out the place bets
			}
			userMenu(origCraps, origDice); //continues back to the menu
		}
	}
	else if (dice == 5)
	{
		if (origCraps.getFieldBet() > 0)
		{
			origCraps.fieldTakeout(5);
		}
		if (dice == origCraps.getPoint()) //Pays out the pass
		{
			origCraps.passPayout(5);
			origCraps.resetBets(); //sets all previous bets to zero
			std::cout << "Your current total is : " << origCraps.getTotal() <<"\n";
			std::cout << "Do you want to continue playing? (y/n) : ";
			std::cin >> charInput;
			if (charInput != 'y')
			{
				std::cout << "Your current total was : " << origCraps.getTotal() << "\n";
				std::cout << "Your starting total was : " << origCraps.getStartTotal() << "\n";
				std::cout << "Goodbye! \n";
			}
			else
			{
				origCraps.setPassBet();
				comeoutRoll(origCraps, origDice);
			}
		}
		else //if the dice ISNT the point
		{
			if(origCraps.getPlaceBet5() > 0) //if there is a place bet
			{
				origCraps.placePayout(5); //pays out the place bets
			}
			userMenu(origCraps, origDice); //continues back to the menu
		}
	}
	else if (dice == 6)
	{
		if (origCraps.getFieldBet() > 0)
		{
			origCraps.fieldTakeout(6);
		}
		if (dice == origCraps.getPoint()) //Pays out the pass
		{
			origCraps.passPayout(6);
			origCraps.resetBets(); //sets all previous bets to zero
			std::cout << "Your current total is : " << origCraps.getTotal() <<"\n";
			std::cout << "Do you want to continue playing? (y/n) : ";
			std::cin >> charInput;
			if (charInput != 'y')
			{
				std::cout << "Your current total was : " << origCraps.getTotal() << "\n";
				std::cout << "Your starting total was : " << origCraps.getStartTotal() << "\n";
				std::cout << "Goodbye! \n";
			}
			else
			{
				origCraps.setPassBet();
				comeoutRoll(origCraps, origDice);
			}
		}
		else //if the dice ISNT the point
		{
			if(origCraps.getPlaceBet6() > 0) //if there is a place bet
			{
				origCraps.placePayout(6); //pays out the place bets
			}
			userMenu(origCraps, origDice); //continues back to the menu
		}
	}
	else if (dice == 8)
	{
		if (origCraps.getFieldBet() > 0)
		{
			origCraps.fieldTakeout(8);
		}
		if (dice == origCraps.getPoint()) //Pays out the pass
		{
			origCraps.passPayout(8);
			origCraps.resetBets(); //sets all previous bets to zero
			std::cout << "Your current total is : " << origCraps.getTotal() <<"\n";
			std::cout << "Do you want to continue playing? (y/n) : ";
			std::cin >> charInput;
			if (charInput != 'y')
			{
				std::cout << "Your current total was : " << origCraps.getTotal() << "\n";
				std::cout << "Your starting total was : " << origCraps.getStartTotal() << "\n";
				std::cout << "Goodbye! \n";
			}
			else
			{
				origCraps.setPassBet();
				comeoutRoll(origCraps, origDice);
			}
		}
		else //if the dice ISNT the point
		{
			if(origCraps.getPlaceBet8() > 0) //if there is a place bet
			{
				origCraps.placePayout(8); //pays out the place bets
			}
			userMenu(origCraps, origDice); //continues back to the menu
		}
	}
	else if (dice == 9)
	{
		origCraps.fieldPayout(9);
		if (dice == origCraps.getPoint()) //Pays out the pass
		{
			origCraps.passPayout(9);
			origCraps.resetBets(); //sets all previous bets to zero
			std::cout << "Your current total is : " << origCraps.getTotal() <<"\n";
			std::cout << "Do you want to continue playing? (y/n) : ";
			std::cin >> charInput;
			if (charInput != 'y')
			{
				std::cout << "Your current total was : " << origCraps.getTotal() << "\n";
				std::cout << "Your starting total was : " << origCraps.getStartTotal() << "\n";
				std::cout << "Goodbye! \n";
			}
			else
			{
				origCraps.setPassBet();
				comeoutRoll(origCraps, origDice);
			}
		}
		else //if the dice ISNT the point
		{
			if(origCraps.getPlaceBet9() > 0) //if there is a place bet
			{
				origCraps.placePayout(9); //pays out the place bets
			}
			userMenu(origCraps, origDice); //continues back to the menu
		}
	}
	else if (dice == 10)
	{
		origCraps.fieldPayout(10);
		if (dice == origCraps.getPoint()) //Pays out the pass
		{
			origCraps.passPayout(10);
			origCraps.resetBets(); //sets all previous bets to zero
			std::cout << "Your current total is : " << origCraps.getTotal() <<"\n";
			std::cout << "Do you want to continue playing? (y/n) : ";
			std::cin >> charInput;
			if (charInput != 'y')
			{
				std::cout << "Your current total was : " << origCraps.getTotal() << "\n";
				std::cout << "Your starting total was : " << origCraps.getStartTotal() << "\n";
				std::cout << "Goodbye! \n";
			}
			else
			{
				origCraps.setPassBet();
				comeoutRoll(origCraps, origDice);
			}
		}
		else //if the dice ISNT the point
		{
			if(origCraps.getPlaceBet10() > 0) //if there is a place bet
			{
				origCraps.placePayout(10); //pays out the place bets
			}
			userMenu(origCraps, origDice); //continues back to the menu
		}
	}
	else if (dice == 11)
	{
		origCraps.fieldPayout(11);
		userMenu(origCraps, origDice);
	}
	else if (dice == 12)
	{
		origCraps.fieldPayout(12);
		userMenu(origCraps, origDice);
	}
}

Executive::Executive()
{
	//None
}

Executive::~Executive()
{
	//None
}
