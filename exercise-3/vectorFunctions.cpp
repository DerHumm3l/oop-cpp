#include <vector>

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

    return maxValue;
}

bool arePositive(const vector<double> &v)
{
    return true;
}

double product(const vector<double> &v1, const vector<double> &v2)
{
    return 1.0;
}

vector<double> product(const vector<double> &v, double f)
{
    return vector<double>{1.0};
}

double norm(const vector<double> &v)
{
    return 1.0;
}

void normalize(const vector<double> &v)
{
}

int main(int argc, char *argv[])
{
    vector<double> v{4.5, 5.5, 1.333, 10, 11.565};
    vector<double> v1;

    double maxValue = max(v);
    double maxValue1 = max(v1);

    int i = 5;
}