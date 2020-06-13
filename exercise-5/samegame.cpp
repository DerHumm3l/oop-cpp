#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cctype>
#include <iterator>

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
    int columnPosition;
    int rowPosition;
};

struct gameBoard
{
    vector<vector<tile>> tiles;
    unsigned int numberOfRows;
    unsigned int numberOfColumns;
};

void initTiles(vector<tile> &gameTiles, int &columnIndex)
{
    for (int rowIndex = 0; rowIndex < gameTiles.size(); rowIndex++)
    {
        gameTiles[rowIndex].backgroundColor = color(rand() % (magenta - black) + red);
        gameTiles[rowIndex].rowPosition = rowIndex;
        gameTiles[rowIndex].columnPosition = columnIndex;
    }
}

vector<tile> generateColumn(const int &size, int &columnIndex)
{
    tile gameTile;

    vector<tile> column(size, gameTile);

    initTiles(column, columnIndex);

    return column;
}

void initColumns(gameBoard &board)
{
    for (int columnIndex = 0; columnIndex < board.numberOfColumns; columnIndex++)
    {
        board.tiles.push_back(generateColumn(board.numberOfRows, columnIndex));
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

vector<tile *> getAdjacentTiles(gameBoard &board, const int &columnIndex, const int &rowIndex)
{
    vector<tile *> tiles;

    if (rowIndex != 0)
    {
        tiles.push_back(&board.tiles[columnIndex][rowIndex - 1]);
    }
    if (columnIndex != 0)
    {
        tiles.push_back(&board.tiles[columnIndex - 1][rowIndex]);
    }
    if (rowIndex != board.numberOfRows - 1)
    {
        tiles.push_back(&board.tiles[columnIndex][rowIndex + 1]);
    }
    if (columnIndex != board.numberOfColumns)
    {
        tiles.push_back(&board.tiles[columnIndex + 1][rowIndex]);
    }

    return tiles;
}

vector<tile *> difference(vector<tile *> &v1, vector<tile *> &v2)
{
    vector<tile *> v3;

    set_difference(v1.begin(), v1.end(),
                   v2.begin(), v2.end(),
                   inserter(v3, v3.begin()));

    return v3;
}

vector<tile *> getAdjacentColorTiles(gameBoard &board, const int &columnIndex, const int &rowIndex, const color tileColor, vector<tile *> &colorTiles)
{
    if (checkIndices(board, columnIndex, rowIndex))
    {
        if (board.tiles[columnIndex][rowIndex].backgroundColor == tileColor)
        {
            colorTiles.push_back(&board.tiles[columnIndex][rowIndex]);

            vector<tile *> adjacentTiles = getAdjacentTiles(board, columnIndex, rowIndex);

            vector<tile *> tiles = difference(adjacentTiles, colorTiles);

            for (tile *gameTile : tiles)
            {
                vector<tile *> adjacentColorTiles = getAdjacentColorTiles(board, gameTile->columnPosition, gameTile->rowPosition, tileColor, colorTiles);

                // return intersection(adjacentColorTiles, colorTiles);
                // return adjacentColorTiles & colorTiles Intersection
                // for (tile *colorGameTile : adjacentColorTiles)
                // {
                //     colorTiles.push_back(colorGameTile);
                // }
            }
        }
    }
    return colorTiles;
}

vector<tile *> getAdjacentColorTiles(gameBoard &board, const int &columnIndex, const int &rowIndex, const color tileColor)
{
    vector<tile *> colorTiles;
    return getAdjacentColorTiles(board, columnIndex, rowIndex, tileColor, colorTiles);
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
            int columnIndex = (int)columnIndexChar - (int)'a';
            int rowIndex = stoi(rowIndexNumber);

            int points = changeGameBoard(board, columnIndex, rowIndex - 1);

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

void testSetup(gameBoard &board){
    board.tiles[2][6].backgroundColor = yellow;
    board.tiles[2][7].backgroundColor = yellow;
    board.tiles[2][8].backgroundColor = yellow;
    board.tiles[1][8].backgroundColor = yellow;
    board.tiles[0][8].backgroundColor = yellow;
    board.tiles[0][7].backgroundColor = yellow;
    board.tiles[0][6].backgroundColor = yellow;
    board.tiles[1][6].backgroundColor = yellow;
    board.tiles[3][6].backgroundColor = yellow;
    board.tiles[4][6].backgroundColor = yellow;
    board.tiles[5][6].backgroundColor = yellow;
    board.tiles[5][7].backgroundColor = yellow;
    board.tiles[5][8].backgroundColor = yellow;
    board.tiles[4][8].backgroundColor = yellow;
    board.tiles[3][8].backgroundColor = yellow;
    board.tiles[2][5].backgroundColor = yellow;
    board.tiles[2][4].backgroundColor = yellow;
    board.tiles[1][4].backgroundColor = yellow;
    board.tiles[5][5].backgroundColor = yellow;
    // 18 Yellow

}

int main(int argc, char *argv[])
{
    string input = "c7";
    gameBoard board = generateGameBoard(9, 9);

    testSetup(board);

    printGameBoard(board);

    // cout << endl
    //      << "Input: ";
    // getline(cin, input);

    int result = evaluateInput(input, board);
    int b = 0;

    getchar();

    return 0;
}