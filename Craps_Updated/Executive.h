/* -----------------------------------------------------------------------------
 *
 * File Name:  Executive.h
 * Description: Executive class that executes the craps program, using the
 *              Dice and crapsDriver classes.
 * Date: Last modified - 9 March 2020
 *
 ---------------------------------------------------------------------------- */

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <fstream>
#include <iostream>
#include <time.h>

#include "Dice.h"
#include "crapsDriver.h"

class Executive
{
  public:

    /**
    *   Creates the starting amount for the program, and sets the first pass line bet
    *   If a 7 or 11 is rolled => Pays out the pass line, and calls comeoutRoll
    *   If a 2, 3, or 12 is rolled => Deducts the pass line, and calls comeoutRoll
    *   If any other number is rolled => A point is established, and userMenu is called
    **/
    void run();

    /**
    *   Continuously calls untill a point is established
    *   If a 7 or 11 is rolled => Pays out the pass line, and calls comeoutRoll
    *   If a 2, 3, or 12 is rolled => Deducts the pass line, and calls comeoutRoll
    *   If any other number is rolled => A point is established, and userMenu is called
    **/
    void comeoutRoll(crapsDriver origCraps, Dice origDice);

    /**
    *   Provides the user with a menu where the user can:
    *    -Set a pass line bet
    *    -Set an odds bet
    *    -Set a field bet
    *    -Set a place bet
    *   When the user is ready to roll the dice, they are shown
    *   the bets they have established on the table, and the
    *   function then calls gameLoop
    **/
    void userMenu(crapsDriver origCraps, Dice origDice);

    /**
    *   If a 7 is rolled => Deducts all bets and calls comeoutRoll
    *   If any other number is rolled, all bets previously made are paid out
    *   Pass line payout:
    *    - 1:1 even money payout
    *   Odds bet payout:
    *    - 4 and 10 payout => 2:1 - 2 for every 1
    *    - 6 and 8 payout => 6:5 - 6 for every 5
    *    - 5 and 9 payout => 3:2 - 9 for every 6
    *   Field bet payout:
    *    - xDouble on the 2
    *    - 1:1 on the 3, 4, 9, 10, or 11
    *    - xTriple on the 12
    *   Place bet payout:
    *    - 4 and 10 payout => 9:5 - 9 for every 5
    *    - 6 and 8 payout => 7:6 - 7 for every 6
    *    - 5 and 9 payout => 7:5 - 7 for every 5
    **/
    void gameLoop(crapsDriver origCraps, Dice origDice);

    /**
    *   N/A
    **/
    Executive();

    /**
    *   N/A
    **/
    ~Executive();
};

#endif
