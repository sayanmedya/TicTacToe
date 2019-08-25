#ifndef TICTACTOE_DEFINITION
#define TICTACTOE_DEFINITION

#include <iostream>
#include "tictactoe.h"
using namespace std;

tictactoe::tictactoe()
{
    for (int i = 0;i < 3;i++)
        for (int j = 0;j < 3;j++)
            grid[i][j] = '-';
}

void tictactoe::print_grid()
{
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++)
            if (grid[i][j] == 'X')
                cout << "\033[1m\033[31mX \033[0m";
            else if (grid[i][j] == 'O')
                cout << "\033[1m\033[34mO \033[0m";
            else
                cout << grid[i][j] << " ";
        cout << "\n";
    }
}

void tictactoe::input(char c)
{
    int x, y;
    cin >> x >> y;
    while (grid[x - 1][y - 1] != '-' || x < 1 || x > 3 || y < 1 || y > 3) {
        cout << "Wrong input. Try again: ";
        cin >> x >> y;
    }
    grid[x - 1][y - 1] = c;
}

bool tictactoe::if_won()
{
    for (int i = 0;i < 3;i++)
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != '-')
            return 1;
    for (int i = 0;i < 3;i++)
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != '-')
            return 1;
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != '-')
        return 1;
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != '-')
        return 1;
    return 0;
}

#endif
