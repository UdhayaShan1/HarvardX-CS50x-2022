#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int temp = get_int("Cents: ");
    if (temp < 0)
    {
        bool x = false;
        while (x==false)
        {
            temp = get_int("Try a positive number: ");
            if (temp >= 0)
            {
                break;
            }
        }
    }
    return temp;
}

int calculate_quarters(int cents)
{
    int quotient = 0;
    quotient = cents / 25;
    return quotient;
}

int calculate_dimes(int cents)
{
    int quotient1 = 0;
    quotient1 = cents / 10;
    return quotient1;
}

int calculate_nickels(int cents)
{
    int quotient2 = 0;
    quotient2 = cents / 5;
    return quotient2;
}

int calculate_pennies(int cents)
{
    int quotient3 = 0;
    quotient3 = cents / 1;
    return quotient3;
}
