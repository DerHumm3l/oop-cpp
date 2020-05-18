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

void normalize(int numerator, int denominator)
{
}

int main(int argc, char *argv[])
{
}