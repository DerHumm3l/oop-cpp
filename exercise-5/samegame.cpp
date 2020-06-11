#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cctype>

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

void printRowSeparator(const gameBoard &board, bool withHeader = false)
{
    if (withHeader)
    {
        cout << "   ";
        for (int i = 0; i < board.numberOfColumns; i++)
        {
            cout << char(int('a') + i) << " ";
        }

        cout << endl;
    }

    cout << "  ";

    for (int i = 0; i < board.numberOfColumns; i++)
    {
        cout << "+-";
    }

    cout << "+" << endl;
}

void printRow(const gameBoard &board, unsigned int rowIndex)
{
    for (int columnIndex = 0; columnIndex < board.numberOfColumns; columnIndex++)
    {
        cout << "|" << getColor(board.tiles[columnIndex][rowIndex]);
    }

    cout << "|" << endl;
}

void printGameBoard(const gameBoard &board)
{
    printRowSeparator(board, true);

    for (int rowIndex = 0; rowIndex < board.numberOfRows; rowIndex++)
    {
        cout << rowIndex + 1 << " ";

        printRow(board, rowIndex);

        printRowSeparator(board);
    }
}

int changeGameBoard(gameBoard &board, int columnIndex, int rowIndex)
{
    return 0;
}

bool checkIndices(const gameBoard &board, int columnIndex, int rowIndex)
{
    return true;
}

int applyInput(const string &input, gameBoard &board)
{
    if (input.at(0) >= (int)'a' && input.at(0) <= (int)'z')
    {
        char columnIndexChar = input.at(0);
        string rowIndexNumber = input.substr(1);

        if (!rowIndexNumber.empty() && std::find_if(rowIndexNumber.begin(), rowIndexNumber.end(), [](unsigned char c) { return !std::isdigit(c); }) == rowIndexNumber.end())
        {
            int columnIndex = (int)'a' - (int)columnIndexChar;
            int rowIndex = stoi(rowIndexNumber);

            if (checkIndices(board, columnIndex, rowIndex))
            {
                changeGameBoard(board, columnIndex, rowIndex);
                // add Points, etc...

                return 0;
            }
            else
            {
                return -2; // Not appliable
            }
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
}

int evaluateInput(const string &input, gameBoard &board)
{
    if (!input.empty())
    {
        if (input.compare("?") == 0)
        {
            return 1;
        }
        else
        {
            return applyInput(input, board);
        }
    }
    else
    {
        return -1;
    }
}

int main(int argc, char *argv[])
{
    string input;
    gameBoard board = generateGameBoard(9, 9);

    printGameBoard(board);

    cout << endl
         << "Input: ";
    getline(cin, input);

    int result = evaluateInput(input, board);
    int b = 0;

    getchar();

    return 0;
}