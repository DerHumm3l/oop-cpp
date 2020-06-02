#include <string>
#include <iostream>
#include <cmath>

using namespace std;

bool isValidNumber(const string &s)
{
    bool startsWithZero = false;

    for (int i = 0; i < s.length(); i++)
    {
        if (startsWithZero)
        {
            return false;
        }

        if (i == 0 && s[i] == '0')
        {
            startsWithZero = true;
        }
    }

    return true;
}

int asNumber(const char &c)
{
    switch (c)
    {
    case 48:
        return 0;
    case 49:
        return 1;
    case 50:
        return 2;
    case 51:
        return 3;
    case 52:
        return 4;
    case 53:
        return 5;
    case 54:
        return 6;
    case 55:
        return 7;
    case 56:
        return 8;
    case 57:
        return 9;
    default:
        return -1;
    }
}

int stringToNumber(const string &s)
{
    int number = 0;
    int numberOfDigits = s.length();

    for (int i = 0; i < numberOfDigits; i++)
    {
        number += pow(10, numberOfDigits - i - 1) * asNumber(s[i]);
    }

    return number;
}

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
    string number;
    int numberEndIndex = s.length();

    for (int i = 0; i < s.length(); i++)
    {
        if (!(s[i] >= 48 && s[i] <= 57))
        {
            numberEndIndex = i;
        }
    }

    number = s.substr(0, numberEndIndex);
    s.replace(0, numberEndIndex, "");

    if (!isValidNumber(number))
    {
        return -1;
    }

    return stringToNumber(number);
}

bool checkPostNumber(string &s)
{
    if (s.length() == 0)
    {
        return true;
    }

    if (s[0] == ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int convert(const string &s)
{
    int number;
    bool preNumberSuccess, postNumberSuccess;

    string sCopy = s;

    if (!checkPreNumber(sCopy))
    {
        cout << "Falsches Format." << endl;

        return -1;
    }

    number = getNumberFromString(sCopy);

    if (number == -1)
    {
        cout << "Zahl konnte nicht konvertiert werden." << endl;

        return -1;
    }

    if (!checkPostNumber(sCopy))
    {
        cout << "Falsches Format." << endl;

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