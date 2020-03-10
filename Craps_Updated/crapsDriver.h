/* -----------------------------------------------------------------------------
 *
 * File Name:  crapsDriver.h
 * Description: crapsDriver class that gets / sets bets from the user, and
 *              then pays / takes the respective bet based on a dice total.
 * Date: Last modified - 9 March 2020
 *
 ---------------------------------------------------------------------------- */

#ifndef CRAPSDRIVER_H
#define CRAPSDRIVER_H

#include <iostream>
#include <limits>

class crapsDriver
{
  private:
    int m_minBet;

    int m_maxBet;

    int m_runningTotal;

    int m_startTotal;

    int m_passBet;

    int m_point;

    int m_fieldBet;

    int m_oddsBet;

    int m_placeBet4;

    int m_placeBet5;

    int m_placeBet6;

    int m_placeBet8;

    int m_placeBet9;

    int m_placeBet10;

    int m_totalBets;

  public:

    /**
    *   Iniatializes all private members to zero
    *   Initializes the minimum and maximum bets allowed
    **/
    crapsDriver();

    /**
    *   Returns the minimum bet allowance
    **/
    int getMin();

    /**
    *   Returns the maximum bet allowance
    **/
    int getMax();

    /**
    *   Returns the running total
    **/
    int getTotal();

    /**
    *   Returns the starting total
    **/
    int getStartTotal();

    /**
    *   Returns the pass line bet
    **/
    int getPass();

    /**
    *   Returns the currently established point
    **/
    int getPoint();

    /**
    *   Returns the field bet
    **/
    int getFieldBet();

    /**
    *   Returns the odds bet
    **/
    int getOddsBet();

    /**
    *   Returns the place bet for number 4
    **/
    int getPlaceBet4();

    /**
    *   Returns the place bet for number 5
    **/
    int getPlaceBet5();

    /**
    *   Returns the place bet for number 6
    **/
    int getPlaceBet6();

    /**
    *   Returns the place bet for number 8
    **/
    int getPlaceBet8();

    /**
    *   Returns the place bet for number 9
    **/
    int getPlaceBet9();

    /**
    *   Returns the place bet for number 10
    **/
    int getPlaceBet10();

    /**
    *   Returns the amount of all bets currently placed
    **/
    int getTotalBets();

    /**
    *   Sets the initial total
    **/
    void setTotal();

    /**
    *   Sets a pass line bet
    **/
    void setPassBet();

    /**
    *   Sets the point on a comeout roll
    **/
    void setPoint(int point);

    /**
    *   Sets a field bet
    **/
    void setFieldBet();

    /**
    *   Sets an odds bet behind your pass line bet
    **/
    void setOddsBet(int diceTotal);

    /**
    *   Sets a place bet for either 4, 5, 6, 8, 9, or 10
    **/
    void setPlaceBet();

    /**
    *   Normal payout for the 3, 4, 9, 10, or 11
    *   x2 payout for the 2
    *   x3 payout for the 12
    **/
    void fieldPayout(int diceTotal);

    /**
    *   Deducts field bet on 5, 6, 7, or 8
    **/
    void fieldTakeout(int diceTotal);

    /**
    *   Pass line payout:
    *    - 1:1 even money payout
    *   Odds bet payout:
    *    - 4 and 10 payout => 2:1 - 2 for every 1
    *    - 6 and 8 payout => 6:5 - 6 for every 5
    *    - 5 and 9 payout => 3:2 - 9 for every 6
    **/
    void passPayout(int diceTotal);

    /**
    *   Deducts pass line bet
    *   Deducts odds bet
    **/
    void passTakeout(int diceTotal);

    /**
    *   Pays if there is a placebet on either 4, 5, 6, 8, 9, or 10
    *   For the 4 and the 10 - Needs to be multiples of 5
    *     True odds are 2:1
    *     => Payout is 9:5
    *   For the 5 and the 9 - Needs to be multiples of 5
    *     True odds are 3:2
    *     => Payout is 7:5
    *   For the 6 and the 8 - Needs to be multiples of 6
    *     True odds are 6:5
    *     => Payout is 7:6
    **/
    void placePayout(int diceTotal);

    /**
    *   Deducts field bet
    *   Deducts all place bets
    **/
    void crapTakeout(int diceTotal);

    /**
    *   Pays the pass line on a comeout roll if a 7 or an 11 are rolled
    **/
    void comeoutPassPayout();

    /**
    *   Deducts the pass line on a comeout roll if a 2, 3 or 12 are rolled
    **/
    void comeoutPassTakeout();

    /**
    *   Sets all bets to zero
    **/
    void resetBets();

    /**
    *   Outputs every bet, the total amount of all bets, and the current total amount
    **/
    void receipt();

    /**
    *   N/A
    **/
    ~crapsDriver();

};

#endif
