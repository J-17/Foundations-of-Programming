/*********************************************************
Date: 8/5/2018
Purpose: Foundations of Programming Assignment 2 Question 2

Name: Jocelyn Mah
*********************************************************/

#include <stdio.h>

const int DOLLAR_SIZE = 7;  // declare & assign dollar array size
const int CENTS_SIZE = 4;   // declare & assign cents array size


float ReadChange()
{
    float change;
    int dollar, cents;

    do
    {
        printf ("\n\nPlease enter amount of change in dollars (cents are accepted too): ");
        scanf ("%f*c ", &change);

        dollar = (int)change;
        cents = (int) (((change-dollar)*100) + 0.5);

        if (cents % 5 != 0)
        {
            printf("Please enter amount of cents to give ONLY in multiple 5\n\n");
        }

        if (dollar < 0)
        {
            printf("Please enter amount of dollar to give in positive values \n\n");
        }
    }while((cents % 5 != 0) || dollar < 0);


    return(change);
}

int CalcChange(int change, int value)
{
    int QtyToGive;

    QtyToGive = change / value;

    return(QtyToGive);
}

int CalcBalance(int QtyGiven, int change, int value)
{
    int balance;

    balance = change - (QtyGiven * value);

    return(balance);
}

void DisplayResults(int DollarQuantity[], int DollarDenominations[], int CoinsQuantity[], int CoinsDenominations[])
{
    int i;

    printf("\n____________________________________________________________\n");
    printf("   Value:        Quantity to Give:\n");

    for (i=0; i<DOLLAR_SIZE; i++)
    {
        printf(" %3d Dollars          %d \n",DollarDenominations[i], DollarQuantity[i]);
    }

    printf("\n");

    for (i=0; i<CENTS_SIZE; i++)
    {
        printf(" %3d Cents            %d \n",CoinsDenominations[i], CoinsQuantity[i]);
    }
}

int main()
{
    const int DOLLAR_DENOMINATIONS[] = {100, 50, 20, 10, 5, 2, 1};  // array to store constant value of Denomination for each dollar
    const int COINS_DENOMINATIONS[] = {50, 20, 10, 5};              // array to store constant value of Denomination for each coin
    float change;
    int dollar, cents, cents_counter;
    int dollar_counter = 0;
    int DollarQty[DOLLAR_SIZE], CoinsQty[CENTS_SIZE];               // array to store Dollar_100_Qty, Dollar_50_Qty, Dollar_20_Qty, Dollar_10_Qty, Dollar_5_Qty, Dollar_2_Qty, Dollar_1_Qty, & Coin_50_Qty, Coin_20_Qty, Coin_10_Qty, Coin_5_Qty;
    int balance = 0;

    change = (float)ReadChange();
    dollar = (int)change;
    cents = (int) (((change-dollar)*100) + 0.5);


    for (cents_counter = 0; cents_counter < CENTS_SIZE; cents_counter++)
    {
        while (dollar_counter<DOLLAR_SIZE)
        {
            DollarQty[dollar_counter] = CalcChange(dollar, DOLLAR_DENOMINATIONS[dollar_counter]);           // Get quantity of each dollar denomination through looping
            dollar = CalcBalance(DollarQty[dollar_counter], dollar, DOLLAR_DENOMINATIONS[dollar_counter]);  // Get balance of dollars change left
            dollar_counter++;
        }

        CoinsQty[cents_counter] = CalcChange(cents, COINS_DENOMINATIONS[cents_counter]);                // Get quantity of each coin denomination through looping
        cents = CalcBalance(CoinsQty[cents_counter], cents, COINS_DENOMINATIONS[cents_counter]);        // Get balance of coins change left
    }


    DisplayResults(DollarQty,DOLLAR_DENOMINATIONS, CoinsQty,COINS_DENOMINATIONS);

    return(0);
}
