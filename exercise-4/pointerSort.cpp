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

void insertionSort(vector<string *> &pointerList)
{
    for (int i = 0; i < pointerList.size(); i++)
    {
        string *elem = pointerList[i];
        int j = i;
        while (j > 0 && *pointerList[j - 1] > *elem)
        {
            pointerList[j] = pointerList[j - 1];
            j--;
        }
        pointerList[j] = elem;
    }
}

void print(vector<string *> &pointerList)
{
}

int main(int argc, char *argv[])
{
    vector<string> list = {"afds", "adfas", "afgrea", "aasagea"};

    vector<string *>
        pointerList = createPointerList(list);

    insertionSort(pointerList);
    print(pointerList);
}