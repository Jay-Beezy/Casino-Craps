/* -----------------------------------------------------------------------------
 *
 * File Name:  crapsDriver.cpp
 * Description: crapsDriver class that gets / sets bets from the user, and
 *              then pays / takes the respective bet based on a dice total.
 * Date: Last modified - 9 March 2020
 *
 ---------------------------------------------------------------------------- */

#include "crapsDriver.h"

crapsDriver::crapsDriver() //initailizes all private member variables to zero
{
  m_minBet = 5;
  m_maxBet = 500;
  m_passBet = 0;
  m_oddsBet = 0;
  m_runningTotal = 0;
  m_startTotal = 0;
  m_point = 0;
  m_placeBet4 = 0;
  m_placeBet5 = 0;
  m_placeBet6 = 0;
  m_placeBet8 = 0;
  m_placeBet9 = 0;
  m_placeBet10 = 0;
  m_fieldBet = 0;
  m_totalBets = 0;
}

int crapsDriver::getMin()
{
  return(m_minBet);
}

int crapsDriver::getMax()
{
  return(m_maxBet);
}

int crapsDriver::getTotal()
{
  return(m_runningTotal);
}

int crapsDriver::getStartTotal()
{
  return(m_startTotal);
}

int crapsDriver::getPass()
{
  return(m_passBet);
}

int crapsDriver::getPoint()
{
  return(m_point);
}

int crapsDriver::getFieldBet()
{
  return(m_fieldBet);
}

int crapsDriver::getOddsBet()
{
  return(m_oddsBet);
}

int crapsDriver::getPlaceBet4()
{
  return(m_placeBet4);
}

int crapsDriver::getPlaceBet5()
{
  return(m_placeBet5);
}

int crapsDriver::getPlaceBet6()
{
  return(m_placeBet6);
}

int crapsDriver::getPlaceBet8()
{
  return(m_placeBet8);
}

int crapsDriver::getPlaceBet9()
{
  return(m_placeBet9);
}

int crapsDriver::getPlaceBet10()
{
  return(m_placeBet10);
}

int crapsDriver::getTotalBets()
{
  m_totalBets = m_passBet + m_oddsBet + m_placeBet4 + m_placeBet5 + m_placeBet6 + m_placeBet8 + m_placeBet9 + m_placeBet10 + m_fieldBet;
  return(m_totalBets);
}

void crapsDriver::setTotal()
{
  int startingAmount = 0;
  std::cout << "Please enter your starting amount : ";
  std::cin >> startingAmount;
  while ( std::cin.fail() || startingAmount < m_minBet)
	{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"Please enter a valid starting amount : ";
    std::cin >> startingAmount;
	}
  m_runningTotal = startingAmount;
  m_startTotal = startingAmount;
}

void crapsDriver::setPassBet()
{
  int passInput = 0;
  std::cout << "Please enter your pass line bet : ";
  std::cin >> passInput;
  while ( std::cin.fail() || passInput < m_minBet || passInput > m_maxBet )
	{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Please enter a valid pass line bet : ";
    std::cin >> passInput;
	}
  m_passBet = passInput;
}

void crapsDriver::setPoint(int point)
{
  m_point = point;
}

void crapsDriver::setFieldBet()
{
  int fieldInput = 0;
  std::cout << "Please enter your field bet : ";
  std::cin >> fieldInput;
  while ( std::cin.fail() || fieldInput < m_minBet || fieldInput > m_maxBet)
	{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"Please enter your field bet : ";
    std::cin >> fieldInput;
	}
  m_fieldBet = fieldInput;
}

void crapsDriver::setOddsBet(int diceTotal)
{
  int oddsInput = 0;

  if (diceTotal == 4 || diceTotal == 10) //Payout is 2:1
  {
    std::cout << "Please input your odds bet : ";
    std::cin >> oddsInput;
    while ((std::cin.fail() || oddsInput < 0 ||  oddsInput < m_minBet || oddsInput > m_maxBet))
  	{
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Please input your odds bet : ";
      std::cin >> oddsInput;
  	}
    m_oddsBet = oddsInput;
  }
  else if (diceTotal == 5 || diceTotal == 9) //Payout is 3:2
  {
    std::cout << "Please make your odds bet in multiples of 2 \n";
    std::cout << "Please input your odds bet : ";
    std::cin >> oddsInput;
    while ((std::cin.fail() || oddsInput < 0 ||  oddsInput < m_minBet || oddsInput > m_maxBet) || oddsInput % 2 != 0)
  	{
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Please make your odds bet in multiples of 2 \n";
      std::cout << "Please input your odds bet : ";
      std::cin >> oddsInput;
  	}
    m_oddsBet = oddsInput;
  }
  else if (diceTotal == 6 || diceTotal == 8) //Payout is 6:5
  {
    std::cout << "Please make your odds bet in multiples of 5 \n";
    std::cout << "Please input your odds bet : ";
    std::cin >> oddsInput;
    while ((std::cin.fail() || oddsInput < 0 ||  oddsInput < m_minBet || oddsInput > m_maxBet) || oddsInput % 5 != 0)
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Please make your odds bet in multiples of 5 \n";
      std::cout << "Please input your odds bet : ";
      std::cin >> oddsInput;
    }
    m_oddsBet = oddsInput;
  }
}

void crapsDriver::setPlaceBet()
{
  int placeLocation = 0;
  int placeInput = 0;
  std::cout << "Please input the number you would like to set your place bet on : ";
  std::cin >> placeLocation;
  while ( std::cin.fail() || placeLocation < 4 || placeLocation > 10 || placeLocation == m_point)
	{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"Please input the number you would like to set your place bet on : ";
    std::cin >> placeLocation;
	}
  if (placeLocation == 4 && placeLocation != m_point)
  {
    std::cout << "Please make your bet in multiples of " << m_minBet << "\n";
    std::cout << "Please input your bet : ";
    std::cin >> placeInput;
    while ((std::cin.fail() || placeInput < 0 ||  placeInput < m_minBet || placeInput > m_maxBet) || placeInput % 5 != 0)
  	{
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Please make your bet in multiples of " << m_minBet << "\n";
      std::cout << "Please input your bet : ";
      std::cin >> placeInput;
  	}
    m_placeBet4 = placeInput;
  }
  else if (placeLocation == 10 && placeLocation != m_point)
  {
    std::cout << "Please make your bet in multiples of 5 \n";
    std::cout << "Please input your bet : ";
    std::cin >> placeInput;
    while ((std::cin.fail() || placeInput < 0 ||  placeInput < m_minBet || placeInput > m_maxBet) || placeInput % 5 != 0)
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Please make your bet in multiples of 5 \n";
      std::cout << "Please input your bet : ";
      std::cin >> placeInput;
    }
    m_placeBet10 = placeInput;
  }
  else if (placeLocation == 5 && placeLocation != m_point)
  {
    std::cout << "Please make your bet in multiples of 5 \n";
    std::cout << "Please input your bet : ";
    std::cin >> placeInput;
    while ((std::cin.fail() || placeInput < 0 ||  placeInput < m_minBet || placeInput > m_maxBet) || placeInput % 5 != 0)
  	{
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Please make your bet in multiples of 5 \n";
      std::cout << "Please input your bet : ";
      std::cin >> placeInput;
  	}
    m_placeBet5 = placeInput;
  }
  else if (placeLocation == 9 && placeLocation != m_point)
  {
    std::cout << "Please make your bet in multiples of 5 \n";
    std::cout << "Please input your bet : ";
    std::cin >> placeInput;
    while ((std::cin.fail() || placeInput < 0 ||  placeInput < m_minBet || placeInput > m_maxBet) || placeInput % 5 != 0)
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Please make your bet in multiples of 5 \n";
      std::cout << "Please input your bet : ";
      std::cin >> placeInput;
    }
    m_placeBet9 = placeInput;
  }
  else if (placeLocation == 6 && placeLocation != m_point)
  {
    std::cout << "Please make your bet in multiples of 6 \n";
    std::cout << "Please input your bet : ";
    std::cin >> placeInput;
    while ((std::cin.fail() || placeInput < 0 ||  placeInput < m_minBet || placeInput > m_maxBet) || placeInput % 6 != 0)
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Please make your bet in multiples of 6 \n";
      std::cout << "Please input your bet : ";
      std::cin >> placeInput;
    }
    m_placeBet6 = placeInput;
  }
  else if (placeLocation == 8 && placeLocation != m_point)
  {
    std::cout << "Please make your bet in multiples of 6 \n";
    std::cout << "Please input your bet : ";
    std::cin >> placeInput;
    while ((std::cin.fail() || placeInput < 0 ||  placeInput < m_minBet || placeInput > m_maxBet) || placeInput % 6 != 0)
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Please make your bet in multiples of 6 \n";
      std::cout << "Please input your bet : ";
      std::cin >> placeInput;
    }
    m_placeBet8 = placeInput;
  }
}

void crapsDriver::fieldPayout(int diceTotal)
{
  if(diceTotal == 2)
  {
    if (m_fieldBet > 0)
    {
      m_runningTotal = m_runningTotal + (m_fieldBet)*2;
      m_fieldBet = 0;
      std::cout << "** Your field bet has been paid out, and reset! **\n";
    }
    else
    {
      m_fieldBet = 0;
    }
  }
  else if(diceTotal == 3)
  {
    if (m_fieldBet > 0)
    {
      m_runningTotal = m_runningTotal + m_fieldBet;
      m_fieldBet = 0;
      std::cout << "** Your field bet has been paid out, and reset! **\n";
    }
    else
    {
      m_fieldBet = 0;
    }
  }
  else if(diceTotal == 4)
  {
    if (m_fieldBet > 0)
    {
      m_runningTotal = m_runningTotal + m_fieldBet;
      m_fieldBet = 0;
      std::cout << "** Your field bet has been paid out, and reset! **\n";
    }
    else
    {
      m_fieldBet = 0;
    }
  }
  else if(diceTotal == 5)
  {
    if (m_fieldBet > 0)
    {
      m_runningTotal = m_runningTotal - m_fieldBet;
      m_fieldBet = 0;
      std::cout << "** Your field bet has been paid out, and reset! **\n";
    }
    else
    {
      m_fieldBet = 0;
    }
  }
  else if(diceTotal == 6)
  {
    if (m_fieldBet > 0)
    {
      m_runningTotal = m_runningTotal - m_fieldBet;
      m_fieldBet = 0;
      std::cout << "** Your field bet has been paid out, and reset! **\n";
    }
    else
    {
      m_runningTotal = m_runningTotal;
      m_fieldBet = 0;
    }
  }
  else if(diceTotal == 8)
  {
    if (m_fieldBet > 0)
    {
      m_runningTotal = m_runningTotal - m_fieldBet;
      m_fieldBet = 0;
      std::cout << "** Your field bet has been paid out, and reset! **\n";
    }
    else
    {
      m_fieldBet = 0;
    }
  }
  else if(diceTotal == 9)
  {
    if (m_fieldBet > 0)
    {
      m_runningTotal = m_runningTotal + m_fieldBet;
      m_fieldBet = 0;
      std::cout << "** Your field bet has been paid out, and reset! **\n";
    }
    else
    {
      m_fieldBet = 0;
    }
  }
  else if(diceTotal == 10)
  {
    if (m_fieldBet > 0)
    {
      m_runningTotal = m_runningTotal + m_fieldBet;
      m_fieldBet = 0;
      std::cout << "** Your field bet has been paid out, and reset! **\n";
    }
    else
    {
      m_fieldBet = 0;
    }
  }
  else if(diceTotal == 11)
  {
    if (m_fieldBet > 0)
    {
      m_runningTotal = m_runningTotal + m_fieldBet;
      m_fieldBet = 0;
      std::cout << "** Your field bet has been paid out, and reset! **\n";
    }
    else
    {
      m_fieldBet = 0;
    }
  }
  else if(diceTotal == 12)
  {
    if (m_fieldBet > 0)
    {
      m_runningTotal = m_runningTotal + (m_fieldBet)*3;
      m_fieldBet = 0;
      std::cout << "** Your field bet has been paid out, and reset! **\n";
    }
    else
    {
      m_fieldBet = 0;
    }
  }
}

void crapsDriver::fieldTakeout(int diceTotal)
{
  if(diceTotal == 5 || diceTotal == 6 || diceTotal == 7 || diceTotal == 8)
  {
    m_runningTotal = m_runningTotal - m_fieldBet;
    m_fieldBet = 0;
    std::cout << "** You have lost your field bet! **\n";
  }
}

void crapsDriver::passPayout(int diceTotal) //payouts pass line AND odds bet
{
  if (m_passBet > 0) //pass line bet pays out even money
  {
    if (diceTotal == 4 || diceTotal == 5 || diceTotal == 6 || diceTotal == 8 || diceTotal == 9 || diceTotal == 10 ) //4 pays outs 2:1
    {
      m_runningTotal = m_runningTotal + m_passBet;
      std::cout << "** You made your point! **\n";
    }
  }
  if (m_oddsBet > 0)
  {
    if(diceTotal == 6 || diceTotal == 8) //payout is 6:5 => oddsBet is a multiple of 5
    {
      m_runningTotal = m_runningTotal + m_oddsBet + (m_oddsBet/5);
      std::cout << "** Your odds bet has been paid out! **\n";
    }
    else if (diceTotal == 5 || diceTotal == 9) //payout is 3:2 => oddsBet is a multiple of 2
    {
      m_runningTotal = m_runningTotal + m_oddsBet + (m_oddsBet/2);
      std::cout << "** Your odds bet has been paid out! **\n";
    }
    else if (diceTotal == 4 || diceTotal == 10) //payout is 2:1 => oddsBet is a multiple of 1
    {
      m_runningTotal = m_runningTotal + m_oddsBet*2;
      std::cout << "** Your odds bet has been paid out! **\n";
    }
  }
}

void crapsDriver::passTakeout(int diceTotal)
{
  if (diceTotal == 7)
  {
    m_runningTotal = m_runningTotal - m_passBet;
    m_runningTotal = m_runningTotal - m_oddsBet;
  }
}

void crapsDriver::placePayout(int diceTotal)
{
  if (diceTotal == 4)
  {
    m_runningTotal = m_runningTotal + (((m_placeBet4)*2)-(m_placeBet4/m_minBet));
    std::cout << "** Your place bet has been paid out! **\n";
  }
  else if (diceTotal == 10)
  {
    m_runningTotal = m_runningTotal + (((m_placeBet10)*2)-(m_placeBet10/m_minBet));
    std::cout << "** Your place bet has been paid out! **\n";
  }
  else if (diceTotal == 5)
  {
    m_runningTotal = m_runningTotal + (((m_placeBet5)*2)-3*(m_placeBet5/m_minBet));
    std::cout << "** Your place bet has been paid out! **\n";
  }
  else if (diceTotal == 9)
  {
    m_runningTotal = m_runningTotal + (((m_placeBet9)*2)-3*(m_placeBet9/m_minBet));
    std::cout << "** Your place bet has been paid out! **\n";
  }
  else if (diceTotal == 6)
  {
    m_runningTotal = m_runningTotal + m_placeBet6 + (m_placeBet6/6);
    std::cout << "** Your place bet has been paid out! **\n";
  }
  else if (diceTotal == 8)
  {
    m_runningTotal = m_runningTotal + m_placeBet8 + (m_placeBet8/6);
    std::cout << "** Your place bet has been paid out! **\n";
  }
}

void crapsDriver::crapTakeout(int diceTotal)
{
  if (diceTotal == 7)
  {
    m_runningTotal = m_runningTotal - m_fieldBet;
    m_runningTotal = m_runningTotal - m_placeBet4;
    m_runningTotal = m_runningTotal - m_placeBet5;
    m_runningTotal = m_runningTotal - m_placeBet6;
    m_runningTotal = m_runningTotal - m_placeBet8;
    m_runningTotal = m_runningTotal - m_placeBet9;
    m_runningTotal = m_runningTotal - m_placeBet10;
  }
}

void crapsDriver::comeoutPassPayout()
{
  std::cout << "** Pass Line Winner! **\n";
  m_runningTotal = m_runningTotal + m_passBet;
}

void crapsDriver::comeoutPassTakeout()
{
  std::cout << "** Pass Line Loser! **\n";
  m_runningTotal = m_runningTotal - m_passBet;
  if(m_runningTotal <= 0)
  {
    std::cout << "You have lost all your money! \n";
  }
  else if (m_runningTotal < m_minBet)
  {
    int temp = 0;
    std::cout << "You do not have enough money for the minimum bet \n";
    std::cout << "How much money would you like to add : ";
    std::cin >> temp;
    while ( std::cin.fail() || temp <= 0)
  	{
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "How much money would you like to add : ";
      std::cin >> temp;
  	}
    m_runningTotal = m_runningTotal + temp;
  }
}

void crapsDriver::resetBets() //sets all previous best to zero
{
  m_passBet = 0;
  m_oddsBet = 0;
  m_point = 0;
  m_placeBet4 = 0;
  m_placeBet5 = 0;
  m_placeBet6 = 0;
  m_placeBet8 = 0;
  m_placeBet9 = 0;
  m_placeBet10 = 0;
}

void crapsDriver::receipt()
{
  std::cout << "========================" << "\n";
  std::cout << "= *** The point is : " << getPoint() << " ***\n";
  std::cout << "= Pass Line Bet : " << getPass() << "\n";
  std::cout << "= Odds Bet : " << getOddsBet() << "\n";
  std::cout << "= Field Bet : " << getFieldBet()<< "\n";
  std::cout << "= Place Bet on the 4 : " << getPlaceBet4() << "\n";
  std::cout << "= Place Bet on the 5 : " << getPlaceBet5() << "\n";
  std::cout << "= Place Bet on the 6 : " << getPlaceBet6() << "\n";
  std::cout << "= Place Bet on the 8 : " << getPlaceBet8() << "\n";
  std::cout << "= Place Bet on the 9 : " << getPlaceBet9() << "\n";
  std::cout << "= Place Bet on the 10 : " << getPlaceBet10() << "\n";
  std::cout << "= Total amount of bets on the table : " << getTotalBets() << "\n";
  std::cout << "= Total (including bets) money : " << getTotal() << "\n";
  std::cout << "========================" << "\n";
}

crapsDriver::~crapsDriver()
{
  //None
}
