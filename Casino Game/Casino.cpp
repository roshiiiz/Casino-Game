#include <iostream>
#include <string> 
#include <cstdlib> 
#include <ctime>
#include <string>
#include<windows.h>
#include <dos.h>
#include <stdio.h>
using namespace std;



void printLineCenter(string message);
void logoMessage(string message);
void startMessage();
void drawLine(int n, char character);
void printRules();


int getGuess();
void setGuess();
void setAmount();
float getAmount();
void updateAmount(bool win);
void setBet();
bool didPlayerWin();
void start();
void messageAfterTurn(bool win);


float player_amount = 0.0;
float player_bet = 0.0;
int guess_number = -1;

int main()
{

    char choice;

    start();
    setAmount();

    do
    {
        cout << "\n\nYour current balance is Rs " << getAmount() << "\n";

        setBet();

        setGuess();

        const bool result = didPlayerWin();

        updateAmount(result);

        messageAfterTurn(result);


        if (getAmount() == 0.00f)
        {

            cout << "\nYou have no money left to play with, the game ends.";
            break;
        }

        cout << "\n\nDo you want to play again (y/n)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    cout << "\n\n\n";
    drawLine(70, '=');
    cout << "\nThanks for playing. Your balance is Rs " << getAmount() << "\n\n";
    drawLine(70, '=');
    return 0;
}


void drawLine(int n, char character)
{
    for (int i = 0; i < n; i++)
        cout << character;
    cout << "\n";
}
void printRules()
{
    logoMessage("Rules of the game");
    cout << "\n\n\n\n";
    drawLine(80, '-');
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win you will get 10 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n";
    drawLine(80, '-');
    cout << "\n\n\n\t\t\t Press enter to continue.....";
    getchar();
}

void printLineCenter(string message)
{
    int len = 0;
    int pos = 0;

    len = (78 - message.length()) / 2;
    cout << "\t\t\t";
    for (pos = 0; pos < len; pos++)
    {

        cout << " ";
    }

    cout << message;
}


void logoMessage(string message)
{
    system("cls");
    cout << endl;
    cout << endl;
    cout << "\n\t\t\t\t\t\t\t             Casino Game Project C++               ";
    cout << endl;
    cout << endl;
    cout << "\n\t\t\t\t\t\t\t-------------------------------------------------------\n";
    printLineCenter(message);
    cout << "\n\t\t\t\t\t\t\t-------------------------------------------------------";
}

void startMessage()
{
   
    cout << "\n\n\n";
    cout << "\n\t\t\t\t\t                  ------------------------------------------------ ";
    cout << "\n\t\t\t\t\t                 |                                                |";
    cout << "\n\t\t\t\t\t                 |                    WELCOME                     |";
    cout << "\n\t\t\t\t\t                 |                      TO                        |";
    cout << "\n\t\t\t\t\t                 |                THE CASINO GAME                 |";
    cout << "\n\t\t\t\t\t                 |                                                |";
    cout << "\n\t\t\t\t\t                  ------------------------------------------------ ";
    cout << "\n\n\n\t\t\t Press enter to continue.....";
    getchar();
}


void setAmount()
{
    logoMessage("Amount Deposit");
    do
    {
        cout << "\n\nEnter Deposit amount to play game: Rs ";
        cin >> player_amount;
        if (player_amount <= 0.0)

        {
            cout << "\n\nPlease enter valid amount to play the game!";
        }
    } while (player_amount <= 0.0);
}

float getAmount()
{
    return player_amount;
}
int getGuess()
{
    return guess_number;
}

void setGuess()
{
    logoMessage("Enter Guess");
    do
    {
        cout << "\n\nGuess a number between 1 to 10 :";
        cin >> guess_number;
        if (guess_number <= 0 || guess_number > 10)
            cout << "Invalid input! The number should be between 1 to 10\n"
            << "Enter the number again. ";
    } while (guess_number <= 0 || guess_number > 10);
}

void updateAmount(bool win)
{
    if (win == true)
    {
        player_amount = player_amount + (player_bet * 10);
    }
    else if (win == false)
    {
        player_amount = player_amount - player_bet;
    }
}

void setBet()
{
    logoMessage("Place your bet");
    do
    {
        cout << "\n\nEnter money to bet : Rs ";
        cin >> player_bet;

        if (player_bet > player_amount)
        {
            cout << "\n\nYour wallet amount is Rs " << player_amount;
            cout << "\n\nYour betting amount is more than your current balance";
        }

    } while (player_bet > player_amount);
}


bool didPlayerWin()
{

    int dice = rand() % 10 + 1;
    if (dice == getGuess())
        return true;
    else
        return false;
}

void start()
{
    startMessage();

    srand(time(0));
    printRules();
}

void messageAfterTurn(bool win)
{
    if (win == true)
    {
        cout << "\n\nGood luck! You won Rs " << player_bet * 10;
        cout << "\n\nNow updated amount is Rs " << player_amount;
    }
    else
    {
        cout << "\n\nWrong guess! You lost Rs " << player_bet << "\n";
        cout << "\n\nNow updated amount is Rs " << player_amount;
    }
}