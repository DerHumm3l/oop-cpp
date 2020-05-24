#include <iostream>
#include <string>

using namespace std;

void askForNumber(int number)
{
}

void askForNumberIsGreater(int number)
{
}

void askForNumberIsLess(int number)
{
}

void askForNumberBetween(int lowerLimit, int upperLimit)
{
}

int getInput(string question)
{
    string input;

    cout << question;
    getline(cin, input);

    return stoi(input);
}

int main(int argc, char *argv[])
{
}