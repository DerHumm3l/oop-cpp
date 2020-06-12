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

bool checkIndices(const gameBoard &board, const int &columnIndex, const int &rowIndex)
{
    if (columnIndex >= board.numberOfColumns || rowIndex >= board.numberOfRows)
    {
        return false;
    }
    else if (board.tiles[columnIndex][rowIndex].backgroundColor == black)
    {
        return false;
    }
    else
    {
        return true;
    }
}

vector<tile *> getAdjacentColorTiles(gameBoard &board, const int &columnIndex, const int &rowIndex, const color tileColor)
{
    vector<tile *> colorTiles;

    if (checkIndices(board, columnIndex, rowIndex))
    {
        if (board.tiles[columnIndex][rowIndex].backgroundColor == tileColor)
        {
            colorTiles.push_back(&board.tiles[columnIndex][rowIndex]);

            // Get all adjacent tiles

            // intersect adjacent tiles and colorTiles

            // call getAdjacentColorTiles for intersection

            // Adjazente Aufrufe
            // Aufpassen dass nach tiles[columnIndex+1] nicht beim
            // rekursiven aufruf dann wieder tiles[columnIndex-1] aufgerufen wird
            // sonst endlosschleife
        }
        return colorTiles;
    }
    else
    {
        return colorTiles;
    }
}

int changeGameBoard(gameBoard &board, const int &columnIndex, const int &rowIndex)
{
    if (checkIndices(board, columnIndex, rowIndex))
    {
        vector<tile *> adjacentColorTiles = getAdjacentColorTiles(board, columnIndex, rowIndex, board.tiles[columnIndex][rowIndex].backgroundColor);

        // update GameBoard
        // calculate Points
        int points = 10;

        return points;
    }
    else
    {
        return 0;
    }
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

            int points = changeGameBoard(board, columnIndex, rowIndex);

            if (points == 0)
            {
                return -2;
            }
            else
            {
                return 0;
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