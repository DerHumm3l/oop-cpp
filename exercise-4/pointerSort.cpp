#include <string>
#include <vector>
#include <iostream>

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
    for (string *elem : pointerList)
    {
        cout << *elem << endl;
    }
}

int main(int argc, char *argv[])
{
    string input;
    vector<string> list;

    do
    {
        cout << "Geben Sie eine beliebige Zeichenkette ein ('.' zum Beenden): ";
        getline(cin, input);

        if (input == ".")
        {
            break;
        }
        else
        {
            list.push_back(input);
        }
    } while (true);

    vector<string *> pointerList = createPointerList(list);

    insertionSort(pointerList);

    cout << endl
         << "Sortierte Liste:" << endl;
    print(pointerList);

    cout << endl
         << "Enter zum beenden";
    getchar();
}