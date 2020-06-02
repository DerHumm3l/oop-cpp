#include <string>
#include <iostream>

using namespace std;

int convert(const string &s)
{
    return stoi(s);
}

int main(int argc, char *argv[])
{
    string input;

    cout << "Geben Sie eine Zahl ein: ";
    getline(cin, input);

    cout << endl
         << "Die eingegbene Zeichenkette wurde in die Zahl " << to_string(convert(input)) << "umgewandelt." << endl;

    return 0;
}