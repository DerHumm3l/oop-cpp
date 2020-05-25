#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

double calcPi(double precision)
{
    double piSum = 0, lastPiSum = 0;

    for (int n = 0;; n++)
    {
        double numerator = pow(-1, n);
        double denominator = 2 * n + 1;

        piSum += numerator / denominator;

        if (abs(4 * piSum - 4 * lastPiSum) < precision)
        {
            return 4 * piSum;
        }

        lastPiSum = piSum;
    }
}

int main(int argc, char *argv[])
{
    double precision;
    string precisionString;

    cout << "Geben Sie die Praezision fuer die Berechnung von Pi ein: ";
    getline(cin, precisionString);

    precision = stod(precisionString);

    if (precision <= 0)
    {
        cout << "Die Praezision muss groesser 0 sein." << endl;
    }

    double pi = calcPi(precision);

    double difference = M_PI - pi;

    cout << "Bei der Praezision von " << precision << " betraegt die Differenz "
         << "zwischen der Konstante Pi " << M_PI << " und den errechneten Wert "
         << pi << " mithilfe der Leibniz-Reihe " << difference << endl;
}