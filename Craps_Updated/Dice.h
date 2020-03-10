/* -----------------------------------------------------------------------------
 *
 * File Name:  Dice.h
 * Description: Dice class that rolls two dice use a rng generator
 * Date: Last modified - 9 March 2020
 *
 ---------------------------------------------------------------------------- */

#ifndef DICE_H
#define DICE_H

#include <time.h>
#include <cstddef>
#include <iostream>
#include <limits>

class Dice
{
  private:

    int dice_total;

    int dice2;

    int dice1;

  public:

    /**
    *   Iniatializes all private members to zero
    **/
    Dice();

    /**
    *   returns a number between 2 and 12
    **/
    int setRoll();

    /**
    *   returns the value of the last thrown dice
    **/
    int getRoll();

    /**
    *   Useless function that prompts the user for an
    *   input in order to generate the random number
    **/
    void Throw();

    /**
    *   N/A
    **/
    ~Dice();
};

#endif
