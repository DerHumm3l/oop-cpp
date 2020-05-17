#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void outputQuadraticEquation(double a, double b, double c)
{
    cout << a << "x² + " << b << "x + " << c << " = 0";
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

int main(int argc, char *argv[])
{
    double a = 10;
    double b = 15;
    double c = 2.5;

    cout.precision(2);

    solveQuadraticEquation(a, b, c);
}