#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

enum color
{
    black = 40,
    red = 41,
    green = 42,
    yellow = 43,
    blue = 44,
    magenta = 45
};

struct tile
{
    color backgroundColor;
};

struct gameBoard
{
    vector<vector<tile>> tiles;
    unsigned int numberOfRows;
    unsigned int numberOfColumns;
};

void initTiles(vector<tile> &gameTiles)
{
    for (tile &gameTile : gameTiles)
    {
        gameTile.backgroundColor = color(rand() % (magenta - black) + red);
    }
}

vector<tile> generateColumn(const int &size)
{
    tile gameTile;

    vector<tile> column(size, gameTile);

    initTiles(column);

    return column;
}

void initColumns(gameBoard &board)
{
    for (int i = 0; i < board.numberOfColumns; i++)
    {
        board.tiles.push_back(generateColumn(board.numberOfRows));
        // board.tiles.push_back(generateColumn(columns));
    }
}

gameBoard generateGameBoard(int rows, int columns)
{
    gameBoard board;
    board.numberOfRows = rows;
    board.numberOfColumns = columns;

    initColumns(board);

    return board;
}

string getColor(tile gameTile)
{
    return "\033[" + to_string(gameTile.backgroundColor) + "m \033[0m";
}

void printRowSeparator(const gameBoard &board)
{
    for (int i = 0; i < board.numberOfColumns; i++)
    {
        cout << "+-";
    }

    cout << "+" << endl;
}

void printRow(const gameBoard &board, unsigned int rowIndex)
{
    for (int j = 0; j < board.numberOfColumns; j++)
    {
        cout << "|" << getColor(board.tiles[j][rowIndex]);
    }

    cout << "|" << endl;
}

void printGameBoard(const gameBoard &board)
{
    printRowSeparator(board);

    for (int i = 0; i < board.numberOfRows; i++)
    {
        printRow(board, i);

        printRowSeparator(board);
    }
}

int main(int argc, char *argv[])
{
    gameBoard board = generateGameBoard(15, 20);

    printGameBoard(board);

    getchar();

    cout << "test 2" << endl;
    cout << "\033[41mHello\033[0m";

    getchar();

    return 0;
}