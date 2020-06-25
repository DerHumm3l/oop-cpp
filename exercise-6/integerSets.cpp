#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class IntegerSet
{
private:
    vector<bool> validationList;
    int minimum;
    int maximum;

public:
    IntegerSet(int min, int max);
    ~IntegerSet();
    bool isValid(int i);
    void add(int i);
    void remove(int i);
    bool contains(int i);
    bool isEmpty();
    int getSize();
    vector<int> getElements();
};

IntegerSet::IntegerSet(int min, int max) : minimum(min), maximum(max), validationList(std::max(max - min, 0)) {}

IntegerSet::~IntegerSet()
{
}

int main(int argc, char *argv[])
{
    return 0;
}
