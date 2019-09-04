#include "tictactoe.h"
#include <cstdlib>
#include <ctime>
using namespace std;

void sleepcp(int milliseconds)
{
    clock_t time_again;
    time_again = clock() + milliseconds * CLOCKS_PER_SEC/1000;
    while (clock() < time_again)
    {
    }
}

tictactoe::tictactoe()
{
    for (int i = 0;i < 3;i++)
        for (int j = 0;j < 3;j++)
            grid[i][j] = '-';
}

void tictactoe::print_grid()
{
    system("clear");
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++)
            if (grid[i][j] == 'X')
                cout << "\033[1m\033[31m X\033[0m";
            else if (grid[i][j] == 'O')
                cout << "\033[1m\033[34m O\033[0m";
            else
                cout << " " << grid[i][j];
        cout << "\n";
    }
    cout << "\n\n\n\n\n\nz ~ undo\nr ~ redo\nb ~ back\nq ~ quit\033[9A\033[8D";
}

char tictactoe::input(char c)
{
    int p, x, y;
    char in = getch();
    p = in - 48;
    x = 2 - (p - 1) / 3;
    y = (p - 1) % 3;
    while ((grid[x][y] != '-' || p < 1 || p > 9) && in != 'q' && in != 'Q' && in != 'b' && in != 'B') {
        cout << "\033[1AWrong input. Try again: ";
        in = getch();
        p = in - 48;
        x = 2 - (p - 1) / 3;
        y = (p - 1) % 3;
    }
    if (p >= 1 && p <= 9)
        grid[x][y] = c;
    return in;
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

void tictactoe::do_last_move(char c)
{
    for (int i = 0;i < 3;i++)
        for (int j = 0;j < 3;j++)
            if (grid[i][j] == '-') {
                grid[i][j] = c;
                return;
            }
}
