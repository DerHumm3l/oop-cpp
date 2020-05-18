#include <iostream>

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
}