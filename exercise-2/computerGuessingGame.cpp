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
    int lowerLimit, upperLimit, guess;

    cout << "Sie muessen sich eine beliebige ganze Zahl ausdenken,"
         << " die der Computer durch Ja- und Nein-Fragen versucht herauszufinden."
         << " Dazu muess der Zahlbereich aber erstmal grob von Ihnen eingeschraenkt werden." << endl;

    lowerLimit = getInput("Geben Sie eine Zahl fuer die untere Grenze ein: ");
    upperLimit = getInput("Geben Sie eine Zahl fuer die obere Grenze ein: ");
}