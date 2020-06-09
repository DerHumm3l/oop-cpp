#include <iostream>
#include <vector>

using namespace std;

enum color
{
    black = 40,
    red = 41,
    green = 42,
    yellow = 43,
    blue = 44,
    magenta = 45
}

struct tile
{
    color backgroundColor;
};

struct gameBoard
{
    vector<vector<tile>> tiles;
};

int main(int argc, char *argv[])
{
    gameBoard board;
    board.tiles = new vector<vector<char>>(9, vector<char>);

    cout << "\033[41mHello\033[0m";
    getchar();
}