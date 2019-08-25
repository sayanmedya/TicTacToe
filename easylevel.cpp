#ifndef EASYLEVEL_DEFINITION
#define EASYLEVEL_DEFINITION

#include <iostream>
#include <vector>
#include <ctime>
#include "easylevel.h"
using namespace std;

bool easylevel::is_winning()
{
    for (int i = 0;i < 3;i++)
        for (int j = 0;j < 3;j++)
            if (grid[i][j] == '-' && grid[i][(j + 1) % 3] == 'X' && grid[i][(j + 2) % 3] == 'X') {
                grid[i][j] = 'X';
                return 1;
            }
    for (int i = 0;i < 3;i++)
        for (int j = 0;j < 3;j++)
            if (grid[j][i] == '-' && grid[(j + 1) % 3][i] == 'X' && grid[(j + 2) % 3][i] == 'X') {
                grid[j][i] = 'X';
                return 1;
            }
    for (int j = 0;j < 3;j++)
        if (grid[j][j] == '-' && grid[(j + 1) % 3][(j + 1) % 3] == 'X' && grid[(j + 2) % 3][(j + 2) % 3] == 'X') {
            grid[j][j] = 'X';
            return 1;
        }
    for (int j = 0;j < 3;j++)
        if (grid[j][2 - j] == '-' && grid[(j + 1) % 3][2 - (j + 1) % 3] == 'X' && grid[(j + 2) % 3][2 - (j + 2) % 3] == 'X') {
            grid[j][2 - j] = 'X';
            return 1;
        }
    return 0;
}

bool easylevel::is_losing()
{
    for (int i = 0;i < 3;i++)
        for (int j = 0;j < 3;j++)
            if (grid[i][j] == '-' && grid[i][(j + 1) % 3] == 'O' && grid[i][(j + 2) % 3] == 'O') {
                grid[i][j] = 'X';
                return 1;
            }
    for (int i = 0;i < 3;i++)
        for (int j = 0;j < 3;j++)
            if (grid[j][i] == '-' && grid[(j + 1) % 3][i] == 'O' && grid[(j + 2) % 3][i] == 'O') {
                grid[j][i] = 'X';
                return 1;
            }
    for (int j = 0;j < 3;j++)
        if (grid[j][j] == '-' && grid[(j + 1) % 3][(j + 1) % 3] == 'O' && grid[(j + 2) % 3][(j + 2) % 3] == 'O') {
            grid[j][j] = 'X';
            return 1;
        }
    for (int j = 0;j < 3;j++)
        if (grid[j][2 - j] == '-' && grid[(j + 1) % 3][2 - (j + 1) % 3] == 'O' && grid[(j + 2) % 3][2 - (j + 2) % 3] == 'O') {
            grid[j][2 - j] = 'X';
            return 1;
        }
    return 0;
}

void easylevel::random_move()
{
    vector<pair<int, int>> a;
    for (int i = 0;i < 3;i++)
        for (int j = 0;j < 3;j++)
            if (grid[i][j] == '-')
                a.push_back({i, j});
    srand(time(NULL));
    int r_indx = rand() % a.size();
    grid[a[r_indx].first][a[r_indx].second] = 'X';
}

void easylevel::make_move()
{
    if (!is_winning())
        if(!is_losing())
            random_move();
}

#endif