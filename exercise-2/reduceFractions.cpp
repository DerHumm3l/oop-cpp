#include <iostream>
#include <string>

using namespace std;

int getGreatestCommonDivisor(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return getGreatestCommonDivisor(b, a % b);
}

void reduce(int numerator, int denominator)
{
    int gcd = getGreatestCommonDivisor(numerator, denominator);

    cout << "Der Bruch " << numerator << "/" << denominator
         << " laesst sich auf " << numerator / gcd << "/"
         << denominator / gcd << " kuerzen" << endl;
}

int main(int argc, char *argv[])
{
    string choice, numeratorInput, denominatorInput;
    int numerator, denominator;

    while (true)
    {
        cout << "Waehlen Sie eine Aktion: " << endl
             << "1 - Kuerzen" << endl
             << "2 - Beenden" << endl
             << "Eingabe: ";

        getline(cin, choice);

        switch (choice[0])
        {
        case '1':
            cout << "Geben Sie den Zaehler als ganze Zahl ein: ";
            getline(cin, numeratorInput);
            numerator = stoi(numeratorInput);

            cout << "Geben Sie den Nenner als ganze Zahl ein: ";
            getline(cin, denominatorInput);
            denominator = stoi(denominatorInput);

            reduce(numerator, denominator);
            break;
        case '2':
            return 0;
        default:
            cout << "Falscher Input";
            break;
        }
    }
}