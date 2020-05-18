#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int getInput(string question)
{
    string input;

    cout << question;
    getline(cin, input);

    return stoi(input);
}

int main(int argc, char *argv[])
{
    int maximum, number, guess;

    maximum = getInput("Geben Sie eine ganze Zahl groesser 1 ein: ");

    if (maximum <= 0)
    {
        cout << "Die eingegebene Zahl ist nicht groesser 0" << endl;

        return 1;
    }

    number = rand() % (maximum + 1);

    cout << "\n"
         << "Es wurde eine Zahl von 0 bis " << maximum << " ausgewuerfelt" << endl;

    do
    {
        guess = getInput("Raten Sie welche ganze Zahl ausgewueferlt wurde: ");

        if (guess > number)
        {
            cout << "Zu hoch. Die ausgewuerfelte Zahl ist niedriger";
        }
        else if (guess < number)
        {
            cout << "Zu Niedrig. Die ausgewuerfelte Zahl ist hoeher";
        }

    } while (guess != number);

    cout << "Sehr gut. Sie haben die richtige Zahl erraten. Die Zahl ist " << number << endl;

    return 0;
}