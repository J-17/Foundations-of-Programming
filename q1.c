/*********************************************************
Date: 17/4/2018
Purpose: Foundations of programming Assignment 1 Question 1

Author: Jocelyn Mah
*********************************************************/

#include <stdio.h>

void DisplayResults(int Coin_50_Qty,int FIFTY_CENT, int Coin_20_Qty,int TWENTY_CENT, int Coin_10_Qty,int TEN_CENT, int Coin_5_Qty,int FIVE_CENT)
{
    printf("\n____________________________________________________________\n");
    printf(" Value: \t\t  Quantity to Give:\n");
    printf(" %d Cents \t\t\t %d \n",FIFTY_CENT, Coin_50_Qty);
    printf(" %d Cents \t\t\t %d \n",TWENTY_CENT, Coin_20_Qty);
    printf(" %d Cents \t\t\t %d \n",TEN_CENT, Coin_10_Qty);
    printf("  %d Cents \t\t\t %d\n",FIVE_CENT, Coin_5_Qty);
}


int CalcBalance(int QtyOfCoinsToGive, int change, int coin_value)
{
    int balance;
    balance = change - (QtyOfCoinsToGive * coin_value);

    return(balance);
}


int CalcChange(int QtyOfCoinsToGive, int change, int coin_value)
{
    QtyOfCoinsToGive = change / coin_value;

    return(QtyOfCoinsToGive);
}


int ReadChange(int change)
{
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


int main()
{
    int change, Coin_50_Qty, Coin_20_Qty, Coin_10_Qty, Coin_5_Qty;
    int balance = 0;
    const int FIFTY_CENT = 50;
    const int TWENTY_CENT = 20;
    const int TEN_CENT = 10;
    const int FIVE_CENT  = 5;

    change = ReadChange(change);

    Coin_50_Qty = CalcChange(Coin_50_Qty, change, FIFTY_CENT);
    change = CalcBalance(Coin_50_Qty, change, FIFTY_CENT);

    Coin_20_Qty = CalcChange (Coin_20_Qty, change, TWENTY_CENT);
    change = CalcBalance(Coin_20_Qty, change, TWENTY_CENT);

    Coin_10_Qty = CalcChange (Coin_10_Qty, change, TEN_CENT);
    change = CalcBalance(Coin_10_Qty, change, TEN_CENT);

    Coin_5_Qty = CalcChange (Coin_5_Qty, change, FIVE_CENT);
    change = CalcBalance(Coin_5_Qty, change, FIVE_CENT);

    DisplayResults(Coin_50_Qty,FIFTY_CENT, Coin_20_Qty,TWENTY_CENT, Coin_10_Qty,TEN_CENT, Coin_5_Qty,FIVE_CENT);

    return(0);
}
