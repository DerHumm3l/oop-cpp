#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Testcomment

void outputQuadraticEquation(double a, double b, double c)
{
    cout << a << "x^2 + " << b << "x + " << c << " = 0";
}

void solveQuadraticEquation(double a, double b, double c)
{
    if(a == 0){
    cout << "Das ist keine quadratische GLeichung" << endl;
    return 1;
    }

    double p = b / a;
    double q = c / a;

    double radicand = pow(p / 2, 2) - q;

    if (radicand < 0)
    {
        cout << "Keine Ergebnisse fuer: ";
        outputQuadraticEquation(a, b, c);
        cout << endl;
    }
    else if (radicand == 0)
    {
        double x = -(p / 2);

        cout << "Nur ein Ergebnis fuer: ";
        outputQuadraticEquation(a, b, c);
        cout << " mit x = " << x << endl;
    }
    else
    {
        double x1 = -(p / 2) + sqrt(radicand);
        double x2 = -(p / 2) - sqrt(radicand);

        cout << "Zwei Ergebnisse fuer: ";
        outputQuadraticEquation(a, b, c);
        cout << " mit x1 = " << x1 << " und x2 = " << x2 << endl;
    }
}

double getInput(string question)
{
    string input;

    cout << question;
    getline(cin, input);

    return stod(input);
}

int main(int argc, char *argv[])
{
    double a, b, c;
    string inputString;

    cout.precision(2);

    a = getInput("Wert fuer a: ");
    b = getInput("Wert fuer b: ");
    c = getInput("Wert fuer c: ");

    solveQuadraticEquation(a, b, c);

    return 0;
}
