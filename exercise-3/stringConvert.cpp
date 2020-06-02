#include <string>
#include <iostream>

using namespace std;

bool checkPreNumber(string &s)
{
    return true;
}

int getNumberFromString(string &s)
{
    return 1;
}

bool checkPostNumber(string &s)
{
    return true;
}

int convert(const string &s)
{
    int number;
    bool preNumberSuccess, postNumberSuccess;

    string sCopy = s;

    if (!checkPreNumber(sCopy))
    {
        // Error
    }

    number = getNumberFromString(sCopy);

    if (number == -1)
    {
        // Error
    }

    if (!checkPostNumber(sCopy))
    {
        // Error
    }

    return number;
}

int main(int argc, char *argv[])
{
    string input;

    cout << "Geben Sie eine Zahl ein: ";
    getline(cin, input);

    cout << endl
         << "Die eingegbene Zeichenkette wurde in die Zahl " << convert(input) << " umgewandelt." << endl;

    cout << "Enter zum Beenden.";
    getchar();

    return 0;
}