#include <string>
#include <iostream>

using namespace std;

bool checkPreNumber(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            s.replace(0, i, "");
            break;
        }
        else if (s[i] == ' ')
        {
            // Do Nothing
        }
        else
        {
            return false;
        }
    }

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
        cout << "Falsches Format" << endl;

        return -1;
    }

    number = getNumberFromString(sCopy);

    if (number == -1)
    {
        // Error

        return -1;
    }

    if (!checkPostNumber(sCopy))
    {
        // Error

        return -1;
    }

    return number;
}

int main(int argc, char *argv[])
{
    string input;
    int number;

    cout << "Geben Sie eine Zahl ein: ";
    getline(cin, input);

    number = convert(input);

    if (number != -1)
    {
        cout << endl
             << "Die eingegbene Zeichenkette wurde in die Zahl " << number << " umgewandelt." << endl;
    }

    cout << "Enter zum Beenden.";
    getchar();

    return 0;
}