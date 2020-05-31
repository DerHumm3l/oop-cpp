#include <vector>
#include <iostream>
#include <cmath>
#include <string>

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

double norm(const vector<double> &v)
{
    double radicand = 0;

    for (double elem : v)
    {
        radicand += pow(elem, 2);
    }

    return sqrt(radicand);
}

void normalize(vector<double> &v)
{
    double inverse = 1 / norm(v);

    v = scalarVectorProduct(v, inverse);
}

void printVector(vector<double> v, string vectorName)
{
    cout << vectorName << " - [";

    for (int i = 0; i < v.size(); i++)
    {
        if (i != 0)
        {
            cout << ",";
        }

        cout << " " << v[i];
    }

    cout << " ]" << endl;
}

vector<double> getUserVector(int size, int numberOfVector)
{
    vector<double> v(size);

    for (int i = 0; i < size; i++)
    {
        double value = 0;

        cout << "Geben Sie den Wert des " << i + 1 << ". Elementes fuer Vektor "
             << numberOfVector << " ein: ";
        cin >> value;

        v[i] = value;
    }

    return v;
}

int main(int argc, char *argv[])
{
    int size = 0;

    cout << "Geben Sie die Anzahl der Elemente in den beiden Vektoren ein: ";
    cin >> size;

    vector<double> userVector1 = getUserVector(size, 1);
    vector<double> userVector2 = getUserVector(size, 2);

    cout << endl;
    printVector(userVector1, "vector 1");
    printVector(userVector2, "vector 2");

    cout << endl;
    cout << "Aufruf max(vector 1)..." << endl;
    double maxValue1 = max(userVector1);
    cout << "Aufruf ergibt: " << maxValue1 << endl
         << endl;

    cout << "Aufruf max(vector 2)..." << endl;
    double maxValue2 = max(userVector2);
    cout << "Aufruf ergibt: " << maxValue2 << endl
         << endl;

    cout << endl;
    cout << "Aufruf allPositive(vector 1)..." << endl;
    bool test1 = allPositive(userVector1);
    cout << "Aufruf ergibt: " << test1 << endl
         << endl;

    cout << "Aufruf allPositive(vector 2)..." << endl;
    bool test2 = allPositive(userVector2);
    cout << "Aufruf ergibt: " << test2 << endl
         << endl;

    cout << endl;
    cout << "Aufruf dotProduct(vector 1, vector 2)..." << endl;
    double product = dotProduct(userVector1, userVector2);
    cout << "Aufruf ergibt: " << product << endl
         << endl;

    cout << endl;
    cout << "Aufruf scalarVectorProduct(vector 1, 5)" << endl;
    vector<double> scalarVectorProduct1 = scalarVectorProduct(userVector1, 5);
    cout << "Aufruf ergibt: ";
    printVector(scalarVectorProduct1, "vector 1 * 5");
    cout << endl;

    cout << "Aufruf scalarVectorProduct(vector 2, 5)" << endl;
    vector<double> scalarVectorProduct2 = scalarVectorProduct(userVector2, 5);
    cout << "Aufruf ergibt: ";
    printVector(scalarVectorProduct2, "vector 2 * 5");
    cout << endl;

    cout << endl;
    cout << "Aufruf norm(vector 1)..." << endl;
    double norm1 = norm(userVector1);
    cout << "Aufruf ergibt: " << norm1 << endl
         << endl;

    cout << "Aufruf norm(vector 2)..." << endl;
    double norm2 = norm(userVector2);
    cout << "Aufruf ergibt: " << norm2 << endl
         << endl;

    cout << endl;
    cout << "Aufruf normalize(vector 1)..." << endl;
    normalize(userVector1);
    cout << "Aufruf ergibt: ";
    printVector(userVector1, "vector 1 normalized");
    cout << endl;

    cout << "Aufruf normalize(vector 2)..." << endl;
    normalize(userVector2);
    cout << "Aufruf ergibt: ";
    printVector(userVector2, "vector 2 normalized");
    cout << endl;
}