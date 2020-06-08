#include <string>
#include <vector>

using namespace std;

vector<string *> createPointerList(vector<string> &list)
{
    vector<string *> pointerList;

    for (string &element : list)
    {
        pointerList.push_back(&element);
    }

    return pointerList;
}

void sort(vector<string *> &list)
{
}

void print(vector<string *> &list)
{
}

int main(int argc, char *argv[])
{
    vector<string> list = {"afds", "adfas", "afgrea", "aasagea"};

    vector<string *>
        pointerList = createPointerList(list);

    sort(pointerList);
    print(pointerList);
}