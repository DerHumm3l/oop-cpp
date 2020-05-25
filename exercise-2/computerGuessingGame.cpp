#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

bool askForNumber(int number)
{
    int inputNumber;
    bool questionSuccessful = false;

    do
    {
        inputNumber = getInput("Ist deine Zahl " + to_string(number) + "? (1 fuer ja, 0 fuer nein)");

        if (inputNumber == 1 || inputNumber == 0)
        {
            questionSuccessful = true;
        }
        else
        {
            cout << "Falsche Eingabe, bitte erenut versuchen." << endl;
        }
    } while (!questionSuccessful);

    return (bool)inputNumber;
}

bool askForNumberIsGreater(int number)
{
}

bool askForNumberIsLess(int number)
{
}

bool askForNumberBetween(int lowerLimit, int upperLimit)
{
}

int getInput(string question)
{
    string input;

    cout << question;
    getline(cin, input);

    return stoi(input);
}

int getRandomNumber(int lowerLimit, int upperLimit)
{
    return rand() % (upperLimit - lowerLimit) + lowerLimit;
}

int main(int argc, char *argv[])
{
    int lowerLimit, upperLimit, guess;

    cout << "Sie muessen sich eine beliebige ganze Zahl ausdenken,"
         << " die der Computer durch Ja- und Nein-Fragen versucht herauszufinden."
         << " Dazu muess der Zahlbereich aber erstmal grob von Ihnen eingeschraenkt werden." << endl;

    lowerLimit = getInput("Geben Sie eine Zahl fuer die untere Grenze ein: ");
    upperLimit = getInput("Geben Sie eine Zahl fuer die obere Grenze ein: ");

    cout << "Ab jetzt versucht der Computer die Zahl zu ermitteln." << endl;

    do
    {
        int upperLimitSubset, lessNumberInSubset, greaterNumberInSubset;
        bool isBetween, isLess, isGreater;

        upperLimitSubset = getRandomNumber(lowerLimit, upperLimit);
        isBetween = askForNumberBetween(lowerLimit, upperLimitSubset);

        if (isBetween)
        {
            upperLimit = upperLimitSubset;
        }

        lessNumberInSubset = getRandomNumber(lowerLimit, upperLimit);
        isLess = askForNumberIsLess(lessNumberInSubset);

        if (isLess)
        {
            upperLimit = lessNumberInSubset - 1;
        }

        greaterNumberInSubset = getRandomNumber(lowerLimit, upperLimit);
        isGreater = askForNumberIsGreater(greaterNumberInSubset);

        if (isGreater)
        {
            lowerLimit = greaterNumberInSubset + 1;
        }
    } while (!askForNumber(getRandomNumber(lowerLimit, upperLimit)));

    return 0;
}