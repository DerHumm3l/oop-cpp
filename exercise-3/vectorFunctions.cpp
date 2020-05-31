#include <vector>
#include <iostream>

using namespace std;

double max(const vector<double> &v)
{
    double maxValue;

    if (v.size() > 0)
    {
        maxValue = v[0];

        for (double elem : v)
        {
            if (elem > maxValue)
            {
                maxValue = elem;
            }
        }
    }
    else
    {
        cout << "Vektor besitzt keine Elemente" << endl;
    }

    return maxValue;
}

bool allPositive(const vector<double> &v)
{
    bool allPositive = true;

    for (double elem : v)
    {
        if (elem < 0)
        {
            allPositive = false;
            break;
        }
    }

    return allPositive;
}

double dotProduct(const vector<double> &v1, const vector<double> &v2)
{
    double product;

    if (v1.size() == v2.size())
    {
        product = 0;

        for (int i = 0; i < v1.size(); i++)
        {
            product += v1[i] * v2[i];
        }
    }
    else
    {
        cout << "Ungleiche Vektorraeume" << endl;
    }

    return product;
}

vector<double> product(const vector<double> &v, double f)
{
    return vector<double>{1.0};
}

double norm(vector<double> &v)
{
    return 1.0;
}

void normalize(const vector<double> &v)
{
}

int main(int argc, char *argv[])
{
    vector<double> vPositive{4.5, 5.5, 1.333, 10, 11.565};
    vector<double> vNegative{-3.4, -6.77, -4, -12.2, -1.778};
    vector<double> vEmpty;

    double maxValue1 = max(vPositive);
    double maxValue2 = max(vNegative);
    double maxValueEmpty = max(vEmpty);

    bool vPositiveTest = allPositive(vPositive);
    bool vNegativeTest = allPositive(vNegative);
    bool vEmptyTest = allPositive(vEmpty);

    double product = dotProduct(vPositive, vNegative);
    double productEmpty1 = dotProduct(vPositive, vEmpty);
    double productEmpty2 = dotProduct(vEmpty, vPositive);
}