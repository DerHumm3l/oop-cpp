#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void outputQuadraticEquation(double a, double b, double c)
{
    cout << a << "x^2 + " << b << "x + " << c << " = 0";
}

void solveQuadraticEquation(double a, double b, double c)
{
    double p = b / a;
    double q = c / a;

    double radicand = pow(p / 2, 2) - q;

    if (radicand < 0)
    {
        cout << "No Results for: ";
        outputQuadraticEquation(a, b, c);
        cout << endl;
    }
    else if (radicand == 0)
    {
        double x = -(p / 2);

        cout << "Only one result for: ";
        outputQuadraticEquation(a, b, c);
        cout << " with x = " << x << endl;
    }
    else
    {
        double x1 = -(p / 2) + sqrt(radicand);
        double x2 = -(p / 2) - sqrt(radicand);

        cout << "Two Result for: ";
        outputQuadraticEquation(a, b, c);
        cout << " with x1 = " << x1 << " and x2 = " << x2 << endl;
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

    a = getInput("Value for a: ");
    b = getInput("Value for b: ");
    c = getInput("Value for c: ");

    solveQuadraticEquation(a, b, c);

    return 0;
}