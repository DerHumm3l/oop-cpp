#include <iostream>
#include <vector>
#include <cstdlib>

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
};

void initTiles(vector<tile> &gameTiles)
{
    for(tile &gameTile : gameTiles){
        gameTile.backgroundColor = color(rand() % (magenta - black) + red);
    }
}

vector<tile> generateColumn(const int &size){
    tile gameTile;

    vector<tile> column(size, gameTile);

    initTiles(column);

    return column;
}

void initColumns(gameBoard &board, const int &rows, const int &columns)
{
    for(int i = 0; i < columns; i++){
        board.tiles.push_back(generateColumn(columns));
    }
}

gameBoard generateGameBoard(int rows, int columns)
{
    gameBoard board;

    initColumns(board, rows, columns);

    return board;
}

void printGameBoard(const gameBoard &board)
{
    cout << "\033[41mHello\033[0m";
}

int main(int argc, char *argv[])
{
    gameBoard board = generateGameBoard(9,9);

    getchar();

    return 0;
}