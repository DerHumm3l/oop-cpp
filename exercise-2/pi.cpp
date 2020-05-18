#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

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
    double precision = 0.0000001;

    double pi = calcPi(precision);

    double difference = M_PI - pi;

    cout << difference << endl;
}