/*********************************************************
Date: 17/4/2018
Purpose: Foundations of Programming Assignment 1 Question 1

Name: Jocelyn Mah
*********************************************************/

#include <stdio.h>

void DisplayResults(int Dollar_100_Qty,int HUNDRED_DOLLAR, int Dollar_50_Qty,int FIFTY_DOLLAR, int Dollar_20_Qty,int TWENTY_DOLLAR, int Dollar_10_Qty,int TEN_DOLLAR, int Dollar_5_Qty,int FIVE_DOLLAR, int Dollar_2_Qty,int TWO_DOLLAR, int Dollar_1_Qty,int ONE_DOLLAR, int Coin_50_Qty,int FIFTY_CENT, int Coin_20_Qty,int TWENTY_CENT, int Coin_10_Qty,int TEN_CENT, int Coin_5_Qty,int FIVE_CENT)
{
    printf("\n____________________________________________________________\n");
    printf("   Value: \t\t  Quantity to Give:\n");
    printf(" %d Dollars \t\t\t %d \n",HUNDRED_DOLLAR, Dollar_100_Qty);
    printf("  %d Dollars \t\t\t %d \n",FIFTY_DOLLAR, Dollar_50_Qty);
    printf("  %d Dollars \t\t\t %d \n",TWENTY_DOLLAR, Dollar_20_Qty);
    printf("  %d Dollars \t\t\t %d \n",TEN_DOLLAR, Dollar_10_Qty);
    printf("   %d Dollars \t\t\t %d \n",FIVE_DOLLAR, Dollar_5_Qty);
    printf("   %d Dollars \t\t\t %d \n",TWO_DOLLAR, Dollar_2_Qty);
    printf("   %d Dollars \t\t\t %d \n",ONE_DOLLAR, Dollar_1_Qty);
    printf("\n");
    printf("  %d Cents \t\t\t %d \n",FIFTY_CENT, Coin_50_Qty);
    printf("  %d Cents \t\t\t %d \n",TWENTY_CENT, Coin_20_Qty);
    printf("  %d Cents \t\t\t %d \n",TEN_CENT, Coin_10_Qty);
    printf("   %d Cents \t\t\t %d\n",FIVE_CENT, Coin_5_Qty);
}


int CalcBalance(int QtyGiven, int change, int value)
{
    int balance;
    balance = change - (QtyGiven * value);

    return(balance);
}


int CalcChange(int QtyToGive, int change, int value)
{
    QtyToGive = change / value;

    return(QtyToGive);
}


float ReadChange(float change, int dollar, int cents)
{
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
    }while(cents % 5 != 0);


    return(change);
}


int main()
{
    float change;
    int dollar, cents, Dollar_100_Qty, Dollar_50_Qty, Dollar_20_Qty, Dollar_10_Qty, Dollar_5_Qty, Dollar_2_Qty, Dollar_1_Qty, Coin_50_Qty, Coin_20_Qty, Coin_10_Qty, Coin_5_Qty;
    int balance = 0;
    const int HUNDRED_DOLLAR = 100;
    const int FIFTY_DOLLAR = 50;
    const int TWENTY_DOLLAR = 20;
    const int TEN_DOLLAR = 10;
    const int FIVE_DOLLAR = 5;
    const int TWO_DOLLAR = 2;
    const int ONE_DOLLAR = 1;

    const int FIFTY_CENT = 50;
    const int TWENTY_CENT = 20;
    const int TEN_CENT = 10;
    const int FIVE_CENT  = 5;


    change = (float)ReadChange(change, dollar, cents);
    dollar = (int)change;
    cents = (int) (((change-dollar)*100) + 0.5);

    // Section to Calculate quantity of dollars to give
    Dollar_100_Qty = CalcChange(Dollar_100_Qty, dollar, HUNDRED_DOLLAR);
    dollar = CalcBalance(Dollar_100_Qty, dollar, HUNDRED_DOLLAR);

    Dollar_50_Qty = CalcChange(Dollar_50_Qty, dollar, FIFTY_DOLLAR);
    dollar = CalcBalance(Dollar_50_Qty, dollar, FIFTY_DOLLAR);

    Dollar_20_Qty = CalcChange(Dollar_20_Qty, dollar, TWENTY_DOLLAR);
    dollar = CalcBalance(Dollar_20_Qty, dollar, TWENTY_DOLLAR);

    Dollar_10_Qty = CalcChange(Dollar_10_Qty, dollar, TEN_DOLLAR);
    dollar = CalcBalance(Dollar_10_Qty, dollar, TEN_DOLLAR);

    Dollar_5_Qty = CalcChange(Dollar_5_Qty, dollar, FIVE_DOLLAR);
    dollar = CalcBalance(Dollar_5_Qty, dollar, FIVE_DOLLAR);

    Dollar_2_Qty = CalcChange(Dollar_2_Qty, dollar, TWO_DOLLAR);
    dollar = CalcBalance(Dollar_2_Qty, dollar, TWO_DOLLAR);

    Dollar_1_Qty = CalcChange(ONE_DOLLAR, dollar, ONE_DOLLAR);
    dollar = CalcBalance(ONE_DOLLAR, dollar, ONE_DOLLAR);


    // Section to Calculate quantity of coins to give
    Coin_50_Qty = CalcChange(Coin_50_Qty, cents, FIFTY_CENT);
    cents = CalcBalance(Coin_50_Qty, cents, FIFTY_CENT);

    Coin_20_Qty = CalcChange (Coin_20_Qty, cents, TWENTY_CENT);
    cents = CalcBalance(Coin_20_Qty, cents, TWENTY_CENT);

    Coin_10_Qty = CalcChange (Coin_10_Qty, cents, TEN_CENT);
    cents = CalcBalance(Coin_10_Qty, cents, TEN_CENT);

    Coin_5_Qty = CalcChange (Coin_5_Qty, cents, FIVE_CENT);
    cents = CalcBalance(Coin_5_Qty, cents, FIVE_CENT);

    DisplayResults(Dollar_100_Qty,HUNDRED_DOLLAR, Dollar_50_Qty,FIFTY_DOLLAR, Dollar_20_Qty,TWENTY_DOLLAR, Dollar_10_Qty,TEN_DOLLAR, Dollar_5_Qty,FIVE_DOLLAR, Dollar_2_Qty,TWO_DOLLAR, Dollar_1_Qty,ONE_DOLLAR, Coin_50_Qty,FIFTY_CENT, Coin_20_Qty,TWENTY_CENT, Coin_10_Qty,TEN_CENT, Coin_5_Qty,FIVE_CENT);

    return(0);
}
