#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class IntegerSet
{
private:
    vector<bool> validations;
    int minimum;
    int maximum;

public:
    IntegerSet(int min, int max);
    ~IntegerSet();
    bool isValid(int value);
    void add(int value);
    void remove(int value);
    bool contains(int value);
    bool isEmpty();
    int getSize();
    vector<int> getElements();
    void print();
};

IntegerSet::IntegerSet(int min, int max) : minimum(min), maximum(max), validations(std::max(max - min, 0), false) {}

IntegerSet::~IntegerSet() {}

bool IntegerSet::isValid(int value)
{
    return value <= maximum && value >= minimum;
}

void IntegerSet::add(int value)
{
    int index = value - minimum;

    validations[index] = true;
}

void IntegerSet::remove(int value)
{
    int index = value - minimum;

    validations[index] = false;
}

bool IntegerSet::contains(int value)
{
    int index = value - minimum;

    return validations[index];
}

bool IntegerSet::isEmpty()
{
    for (auto &&validation : validations)
    {
        if (validation)
        {
            return false;
        }
    }

    return true;
}

int IntegerSet::getSize()
{
    int size = 0;

    for (auto &&validation : validations)
    {
        if (validation)
        {
            size++;
        }
    }

    return size;
}

vector<int> IntegerSet::getElements()
{
    vector<int> integers;

    for (int i = 0; i < validations.size(); i++)
    {
        if (validations[i])
        {
            int value = i + minimum;

            integers.push_back(value);
        }
    }

    return integers;
}

void IntegerSet::print()
{
    vector<int> integers = getElements();

    for (auto &&value : integers)
    {
        cout << value << endl;
    }
}

int main(int argc, char *argv[])
{
    return 0;
}
