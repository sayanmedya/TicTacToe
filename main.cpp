#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tictactoe.h"
#include "easylevel.h"
using namespace std;


void sleepcp(int milliseconds)
{
    clock_t time_again;
    time_again = clock() + milliseconds * CLOCKS_PER_SEC/1000;
    while (clock() < time_again)
    {
    }
}

bool two_players(string player1, string player2, bool first_move)
{
    tictactoe new_game;
    for (int i = first_move;i < 9 + first_move;i++)
        if (i & 1) {
            system("clear||cls");
            new_game.print_grid();
            cout << "Move of " << player2 << " (\033[1m\033[31mX\033[0m): ";
            new_game.input('X');
            if (new_game.if_won()) {
                system("clear||cls");
                new_game.print_grid();
                cout << player2 << " wins \U0001F389\n";
                return 1;
            }
        }
        else {
            system("clear||cls");
            new_game.print_grid();
            cout << "Move of " << player1 << " (\033[1m\033[34mO\033[0m): ";
            new_game.input('O');
            if (new_game.if_won()) {
                system("clear||cls");
                new_game.print_grid();
                cout << player1 << " wins \U0001F389\n";
                return 0;
            }
        }
    system("clear||cls");
    new_game.print_grid();
    cout << "Match tied.\n";
    return (1 - first_move);
}

bool one_player_easy(bool first_move)
{
    easylevel new_game;
    for (int i = first_move;i < 9 + first_move;i++) {
        if (i & 1) {
            system("clear||cls");
            new_game.print_grid();
            cout << "Computer's move (\033[1m\033[31mX\033[0m):\n";
            new_game.make_move();
            sleepcp(750);
            if (new_game.if_won()) {
                system("clear||cls");
                new_game.print_grid();
                cout << "You lost \U00002639\n";
                return 1;
            }
        }
        else {
            system("clear||cls");
            new_game.print_grid();
            cout << "Your move" << " (\033[1m\033[34mO\033[0m): ";
            new_game.input('O');
            if (new_game.if_won()) {
                system("clear||cls");
                new_game.print_grid();
                cout << "You won \U0001F389\n";
                return 0;
            }
        }
    }
    system("clear||cls");
    new_game.print_grid();
    cout << "Match tied.\n";
    return (1 - first_move);
}

int main()
{
    int option;
    do {
        system("clear||cls");
        cout << "1. Two players mode\n2. Play against computer\n3. Exit\nEnter your choice: ";
        cin >> option;
        if (option == 1) {
            cin.ignore();
            system("clear||cls");
            string player1, player2;
            cout << "Enter Player 1 name: ";
            getline(cin, player1);
            cout << "Enter Player 2 name: ";
            getline(cin, player2);
            bool first_move = 0;
            char again = 'y';
            while (again == 'y' || again == 'Y') {
                first_move = two_players(player1, player2, first_move);
                cout << "Play again (Y/n): ";
                cin >> again;
            }
        }
        else if (option == 2) {
            system("clear||cls");
            cout << "1. Easy\n2. Hard\n3. Back\nEnter your choice: ";
            int option2;
            cin >> option2;
            if (option2 == 1) {
                bool first_move = 0;
                char again = 'y';
                while (again == 'y' || again == 'Y') {
                    first_move = one_player_easy(first_move);
                    cout << "Play again (Y/n): ";
                    cin >> again;
                }
            }
        }
    } while (option != 3);
    return 0;
}
