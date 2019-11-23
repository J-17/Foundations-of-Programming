/*********************************************************
Date: 16/5/2018
Purpose: Foundation of Programming Assignment 2 Question 1

Name: Jocelyn Mah
*********************************************************/

#include <stdio.h>

const int SIZE = 4;

int ReadChange()
{
    int change;

    do
    {
        printf ("Please enter amount of change (in a range of 5 - 95): ");
        scanf ("%d%*c", &change);

        if ((change > 95) || (change < 5))
        {
            if (change > 95)
            {
                printf("Please enter amount of change to give not EXCEEDING 95\n\n");
            }
            else
            {
                printf("Please enter amount of change to give not LESSER than 5\n\n");
            }

        }
        else
        {
            if (change % 5 != 0)
            {
                printf("Please enter amount of change to give ONLY in multiple 5\n\n");
            }
        }
    }while((change % 5 != 0) || (change>95 || change<5));


    return(change);
}

int CalcChange(int change, int coin_value)
{
    int QtyOfCoinsToGive;

    QtyOfCoinsToGive = change / coin_value;

    return(QtyOfCoinsToGive);
}

int CalcBalance(int QtyOfCoinsToGive, int change, int coin_value)
{
    int balance;

    balance = change - (QtyOfCoinsToGive * coin_value);

    return(balance);
}

void DisplayResults(int Quantity[], int Denominations[])
{
    int i;

    printf("\n____________________________________________________________\n");
    printf(" Value:     Quantity to Give:\n");

    for (i=0; i<SIZE; i++)
    {
        printf(" %2d Cents         %d \n",Denominations[i], Quantity[i]);
    }
}

int main()
{
    const int COINS_DENOMINATIONS[] = {50, 20, 10, 5};    // array to store constant value of Denomination for each coin
    int change, counter;
    int cents[SIZE];                // array to store Coin_50_Qty, Coin_20_Qty, Coin_10_Qty, Coin_5_Qty;
    int balance = 0;

    change = ReadChange();  // FUNCTION to get input from user

    for (counter = 0; counter < SIZE; counter++)
    {
        cents[counter] = CalcChange(change, COINS_DENOMINATIONS[counter]);                // Get quantity of each coin denomination through looping
        change = CalcBalance(cents[counter], change, COINS_DENOMINATIONS[counter]);       // Get balance of change left
    }

    DisplayResults(cents,COINS_DENOMINATIONS);

    return(0);
}
