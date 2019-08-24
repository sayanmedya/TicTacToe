#include <iostream>

class tictactoe {
private:
    std::string player1, player2;
    char grid[3][3];

public:
    tictactoe();
    void get_player_names();
    std::string player_1();
    std::string player_2();
    void print_grid();
    void input(char);
    bool if_won();
};

tictactoe::tictactoe()
{
    for (int i = 0;i < 3;i++)
        for (int j = 0;j < 3;j++)
            grid[i][j] = '-';
}

void tictactoe::get_player_names()
{
    std::cout << "Enter Player 1 name: ";
    getline(std::cin, player1);
    std::cout << "Enter Player 2 name: ";
    getline(std::cin, player2);
}

std::string tictactoe::player_1()
{
    return player1;
}

std::string tictactoe::player_2()
{
    return player2;
}

void tictactoe::print_grid()
{
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++)
            if (grid[i][j] == 'X')
                std::cout << "\033[1m\033[31mX \033[0m";
            else if (grid[i][j] == 'O')
                std::cout << "\033[1m\033[34mO \033[0m";
            else
                std::cout << grid[i][j] << " ";
        std::cout << "\n";
    }
}

void tictactoe::input(char c)
{
    int x, y;
    std::cin >> x >> y;
    while (grid[x - 1][y - 1] != '-' || x < 1 || x > 3 || y < 1 || y > 3) {
        std::cout << "Wrong input. Try again: ";
        std::cin >> x >> y;
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