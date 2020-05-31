#include <vector>
#include <iostream>
#include <cmath>

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

vector<double> scalarVectorProduct(const vector<double> &v, double f)
{
    vector<double> scalarVector(v);

    for (double &elem : scalarVector)
    {
        elem *= f;
    }

    return scalarVector;
}

double norm(vector<double> &v)
{
    double radicand = 0;

    for (double elem : v)
    {
        radicand += pow(elem, 2);
    }

    return sqrt(radicand);
}

void normalize(const vector<double> &v)
{
}

int main(int argc, char *argv[])
{
    vector<double> vPositive{4.5, 5.5, 1.333, 10, 11.565};
    vector<double> vNegative{-3.4, -6.77, -4, -12.2, -1.778};
    vector<double> vEmpty;

    double maxValuePositive = max(vPositive);
    double maxValueNegative = max(vNegative);
    double maxValueEmpty = max(vEmpty);

    bool vPositiveTest = allPositive(vPositive);
    bool vNegativeTest = allPositive(vNegative);
    bool vEmptyTest = allPositive(vEmpty);

    double product = dotProduct(vPositive, vNegative);
    double productEmpty1 = dotProduct(vPositive, vEmpty);
    double productEmpty2 = dotProduct(vEmpty, vPositive);

    vector<double> scalarVectorProductPositive = scalarVectorProduct(vPositive, 5);
    vector<double> scalarVectorProductNegative = scalarVectorProduct(vNegative, -5);
    vector<double> scalarVectorProductEmpty = scalarVectorProduct(vEmpty, 5);

    double normPositive = norm(vPositive);
    double normNegative = norm(vNegative);
    double normEmpty = norm(vEmpty);
}