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
    int getIndex(int value);
    int getValue(int index);
};

IntegerSet::IntegerSet(int min, int max) : minimum(min), maximum(max), validations(std::max(max - min, 0), false) {}

IntegerSet::~IntegerSet() {}

bool IntegerSet::isValid(int value)
{
    return value <= maximum && value >= minimum;
}

void IntegerSet::add(int value)
{
    validations[getIndex(value)] = true;
}

void IntegerSet::remove(int value)
{
    validations[getIndex(value)] = false;
}

bool IntegerSet::contains(int value)
{
    return validations[getIndex(value)];
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
            integers.push_back(getValue(i));
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

int IntegerSet::getIndex(int value)
{
    return value - minimum;
}

int IntegerSet::getValue(int index)
{
    return index + minimum;
}

int main(int argc, char *argv[])
{
    return 0;
}
