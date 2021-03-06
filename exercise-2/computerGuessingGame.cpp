#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int getInput(string question)
{
    string input;

    cout << question;
    getline(cin, input);

    return stoi(input);
}

bool askUser(string question)
{
    int inputNumber;
    bool questionSuccessful = false;

    do
    {
        inputNumber = getInput(question);

        if (inputNumber == 1 || inputNumber == 0)
        {
            questionSuccessful = true;
        }
        else
        {
            cout << "Falsche Eingabe, bitte erneut versuchen." << endl;
        }
    } while (!questionSuccessful);

    return (bool)inputNumber;
}

bool askForNumber(int number)
{
    return askUser("Ist deine Zahl " + to_string(number) + "? (1 fuer ja, 0 fuer nein): ");
}

bool askForNumberIsGreater(int number)
{
    return askUser("Ist deine Zahl groesser als " + to_string(number) + "?  (1 fuer ja, 0 fuer nein): ");
}

bool askForNumberIsLess(int number)
{
    return askUser("Ist deine Zahl kleiner als " + to_string(number) + "?  (1 fuer ja, 0 fuer nein): ");
}

bool askForNumberBetween(int lowerLimit, int upperLimit)
{
    return askUser("Liegt deine Zahl zwischen " + to_string(lowerLimit) + " und " + to_string(upperLimit) + "? - Inklusive der Grenzen  (1 fuer ja, 0 fuer nein): ");
}

int getRandomNumber(int lowerLimit, int upperLimit)
{
    return rand() % (upperLimit - lowerLimit) + lowerLimit + 1;
}

int main(int argc, char *argv[])
{
    int lowerLimit, upperLimit, guess;
    int questionCounter = 0;

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

        questionCounter++;
        upperLimitSubset = getRandomNumber(lowerLimit, upperLimit);
        isBetween = askForNumberBetween(lowerLimit, upperLimitSubset);

        if (isBetween)
        {
            upperLimit = upperLimitSubset;
        }
        else
        {
            lowerLimit = upperLimitSubset + 1;
        }

        if (lowerLimit == upperLimit)
        {
            questionCounter++;
            if (askForNumber(lowerLimit))
            {
                break;
            }
        }

        questionCounter++;
        lessNumberInSubset = getRandomNumber(lowerLimit, upperLimit);
        isLess = askForNumberIsLess(lessNumberInSubset);

        if (isLess)
        {
            upperLimit = lessNumberInSubset - 1;
        }
        else
        {
            lowerLimit = lessNumberInSubset;
        }

        if (lowerLimit == upperLimit)
        {
            questionCounter++;
            if (askForNumber(lowerLimit))
            {
                break;
            }
        }

        questionCounter++;
        greaterNumberInSubset = getRandomNumber(lowerLimit, upperLimit);
        isGreater = askForNumberIsGreater(greaterNumberInSubset);

        if (isGreater)
        {
            lowerLimit = greaterNumberInSubset + 1;
        }
        else
        {
            upperLimit = greaterNumberInSubset;
        }

        questionCounter++;
    } while (!askForNumber(getRandomNumber(lowerLimit, upperLimit)));

    cout << "Die Zahl " << lowerLimit << " wurde mit "
         << questionCounter << " Fragen vom Computer ermittelt. Enter zum beenden.";

    getchar();

    return 0;
}