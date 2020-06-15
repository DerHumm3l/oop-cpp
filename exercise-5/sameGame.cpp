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
    unsigned int points;
    unsigned int turns;
};

void initTiles(vector<tile> &gameTiles, int &columnIndex, bool empty = false)
{
    for (int rowIndex = 0; rowIndex < gameTiles.size(); rowIndex++)
    {
        gameTiles[rowIndex].backgroundColor = empty ? color::black : color(rand() % (magenta - color::black) + red);
        gameTiles[rowIndex].rowPosition = rowIndex;
        gameTiles[rowIndex].columnPosition = columnIndex;
    }
}

vector<tile> generateColumn(const int &rowCount, int &columnIndex, bool empty = false)
{
    tile gameTile;

    vector<tile> column(rowCount, gameTile);

    initTiles(column, columnIndex, empty);

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
    else if (board.tiles[columnIndex][rowIndex].backgroundColor == color::black)
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

bool tileIsInGroup(gameBoard &board, const int &columnIndex, const int &rowIndex)
{
    // implementTileCheck

    return true;
}

int removeAdjacentColorTiles(gameBoard &board, const int &columnIndex, const int &rowIndex)
{
    if (!checkIndices(board, columnIndex, rowIndex))
    {
        return -2;
    }
    else if (!tileIsInGroup(board, columnIndex, rowIndex))
    {
        return -3;
    }
    else
    {
        return removeAdjacentColorTiles(board, columnIndex, rowIndex, board.tiles[columnIndex][rowIndex].backgroundColor);
    }
}

int removeAdjacentColorTiles(gameBoard &board, const int &columnIndex, const int &rowIndex, const color tileColor)
{
    if (board.tiles[columnIndex][rowIndex].backgroundColor == tileColor)
    {
        board.tiles[columnIndex][rowIndex].backgroundColor = color::black;

        vector<tile *> adjacentTiles = getAdjacentTiles(board, columnIndex, rowIndex);

        int colorTileCount = 0;

        for (tile *gameTile : adjacentTiles)
        {
            colorTileCount += removeAdjacentColorTiles(board, gameTile->columnPosition, gameTile->rowPosition, tileColor);
        }

        return colorTileCount + 1;
    }

    return 0;
}

bool compareTiles(tile tile1, tile tile2)
{
    if (tile1.backgroundColor == color::black || tile2.backgroundColor == color::black)
    {
        return tile1.backgroundColor < tile2.backgroundColor;
    }
    else
    {
        return false;
    }
}

void fixIndices(vector<tile> &column, int &columnIndex)
{
    for (int rowIndex = 0; rowIndex < column.size(); rowIndex++)
    {
        column[rowIndex].rowPosition = rowIndex;
        column[rowIndex].columnPosition = columnIndex;
    }
}

void sortColumn(vector<tile> &column, int &columIndex)
{
    sort(column.begin(), column.end(), compareTiles);

    fixIndices(column, columIndex);
}

void removeEmptyColumns(gameBoard &board)
{
    for (int columnIndex = 0; columnIndex < board.tiles.size(); columnIndex++)
    {
        bool emptryColumn = true;

        for (tile gameTile : board.tiles[columnIndex])
        {
            if (gameTile.backgroundColor != color::black)
            {
                emptryColumn = false;
                break;
            }
        }

        if (emptryColumn)
        {
            board.tiles.erase(board.tiles.begin() + columnIndex);
        }
    }
}

void addMissingColumns(gameBoard &board)
{
    for (int columnCount = board.tiles.size(); columnCount < board.numberOfColumns; columnCount++)
    {
        int columnIndex = columnCount - 1;
        board.tiles.push_back(generateColumn(board.numberOfRows, columnIndex, true));
    }
}

void sortGameBoard(gameBoard &board)
{
    removeEmptyColumns(board);

    for (int columnIndex = 0; columnIndex < board.tiles.size(); columnIndex++)
    {
        sortColumn(board.tiles[columnIndex], columnIndex);
    }

    addMissingColumns(board);
}

int changeGameBoard(gameBoard &board, const int &columnIndex, const int &rowIndex)
{
    if (checkIndices(board, columnIndex, rowIndex))
    {
        int colorTileCount = removeAdjacentColorTiles(board, columnIndex, rowIndex);

        sortGameBoard(board);

        return colorTileCount * (colorTileCount - 1);
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

            if (points == -2)
            {
                // Turn off grid
                return -2;
            }
            else if (points == -3)
            {
                // Tile not in group
                return -3;
            }
            else
            {
                board.points += points;
                board.turns++;

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

void testSetup(gameBoard &board)
{
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

    printGameBoard(board);

    // Test if turns are available

    getchar();

    return 0;
}