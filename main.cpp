#include <iostream>
#include "tictactoe.h"
#include "easylevel.h"
#include "hardlevel.h"
#include "getch.h"
using namespace std;

int two_players(string player1, string player2, int first_move)
{
    tictactoe new_game;
    for (int i = first_move;i < 9 + first_move;i++)
        if (i & 1) {
            new_game.print_grid();
            cout << "Move of " << player2 << " (\033[1m\033[31mX\033[0m): ";
            if (i == 8 + first_move) {
                cout << "\n";
                new_game.do_last_move('X');
                sleepcp(250);
            }
            else {
                char c = new_game.input('X');
                if (c == 'b' || c == 'B')
                    return -1;
            }
            if (new_game.if_won()) {
                new_game.print_grid();
                cout << player2 << " wins \U0001F389\n";
                return 1;
            }
        }
        else {
            new_game.print_grid();
            cout << "Move of " << player1 << " (\033[1m\033[34mO\033[0m): ";
            if (i == 8 + first_move) {
                cout << "\n";
                new_game.do_last_move('O');
                sleepcp(250);
            }
            else {
                char c = new_game.input('O');
                if (c == 'b' || c == 'B')
                    return -1;
            }
            if (new_game.if_won()) {
                new_game.print_grid();
                cout << player1 << " wins \U0001F389\n";
                return 0;
            }
        }
    new_game.print_grid();
    cout << "Match tied.\n";
    return (1 - first_move);
}

template <class T>
int one_player(bool first_move)
{
    T new_game;
    for (int i = first_move;;i++) {
        if (i & 1) {
            new_game.print_grid();
            // cout << i << "\n";
            cout << "Computer's move (\033[1m\033[31mX\033[0m):\n";
            new_game.make_move();
            sleepcp(250);
            if (new_game.if_won()) {
                new_game.print_grid();
                // cout << i << "\n";
                cout << "You lost \U00002639\n\n";
                while (1) {
                    cout << "\033[1APlay again (Y/n): ";
                    char again = getch();
                    if (again == 'y' || again == 'Y')
                        return 1;
                    else if ((again == 'z' || again == 'Z') && new_game.st_done.size() > 1) {// if undoing is possible
                        new_game.undo();
                        new_game.undo();
                        i -= 2;
                        break;
                    }
                    else if (again == 'n' || again == 'N' || again == 'b' || again == 'B')
                        return -1;
                }
            }
        }
        else {
            new_game.print_grid();
            // cout << i << "\n";
            cout << "Your move" << " (\033[1m\033[34mO\033[0m): ";
            if (i == 8 + first_move) {
                cout << "\n";
                new_game.do_last_move('O');
                sleepcp(250);
            }
            else {
                char c = new_game.input('O');
                if (c == 'b' || c == 'B')
                    return -1;
                else if (c == 'z' || c == 'Z') {// if undoing is possible
                    if (new_game.st_done.size() > 1) {
                        new_game.undo();
                        new_game.undo();
                        i -= 3;
                    }
                    else
                        i -= 1;
                }
                else if (c == 'r' || c == 'r') {// if redoing is possible
                    if (new_game.st_undone.size() > 1) {
                        new_game.redo();
                        new_game.redo();
                        i += 1;
                    }
                    else
                        i -= 1;
                }
            }
            if (new_game.if_won()) {
                new_game.print_grid();
                // cout << i << "\n";
                cout << "You won \U0001F389\n\n";
                do {
                    cout << "\033[1APlay again (Y/n): ";
                    char again = getch();
                    if (again == 'y' || again == 'Y')
                        return 0;
                    else if (again == 'n' || again == 'N' || again == 'b' || again == 'B')
                        return -1;
                } while (1);
            }
        }
        if (i == 8 + first_move) {
            new_game.print_grid();
            // cout << i << "\n";
            cout << "Match tied.\n\n";
            while (1) {
                cout << "\033[1APlay again (Y/n): ";
                char again = getch();
                if (again == 'y' || again == 'Y')
                    return 1 - first_move;
                else if (again == 'z' || again == 'Z') {// if undoing is possible
                    if (first_move == 0 && new_game.st_done.size() > 2) {
                        new_game.undo();
                        //new_game.st_undone.clear();
                        new_game.undo();
                        new_game.undo();
                        i -= 3;
                        break;
                    }
                    else if (first_move == 1 && new_game.st_done.size() > 1) {// if undoing is possible
                        new_game.undo();
                        new_game.undo();
                        i -= 2;
                        break;
                    }
                }
                else if (again == 'n' || again == 'N' || again == 'b' || again == 'B')
                    return -1;
            }
        }
    }
}

int main()
{
    char option;
    do {
        system("clear");
        cout << "1 ~ One Player\n2 ~ Two Players\n\n\n\n\n\n\n\nz ~ undo\nr ~ redo\nb ~ back\nq ~ quit\033[10A\033[8DType your choice: ";
        option = getch();
        if (option == '1') {
            char option2;
            do {
                system("clear");
                cout << "1 ~ Easy level\n2 ~ Hard level\n\n\n\n\n\n\n\nz ~ undo\nr ~ redo\nb ~ back\nq ~ quit\033[10A\033[8DType your choice: ";
                option2 = getch();
                if (option2 == '1') {
                    int first_move = 0;
                    while (first_move == 0 || first_move == 1) {
                        first_move = one_player<easylevel> (first_move);
                    }
                }
                else if (option2 == '2') {
                    int first_move = 0;
                    while (first_move == 0 || first_move == 1) {
                        first_move = one_player<hardlevel> (first_move);
                    }
                }
            } while (option2 != 'b' && option2 != 'B');
        }
        else if (option == '2') {
            system("clear");
            string player1, player2;
            cout << "Enter Player 1 name: ";
            getline(cin, player1);
            cout << "Enter Player 2 name: ";
            getline(cin, player2);
            int first_move = 0;
            char again = 'y';
            while (again == 'y' || again == 'Y') {
                first_move = two_players(player1, player2, first_move);
                if (first_move == -1)
                    break;
                cout << "Play again (Y/n): ";
                again = getch();
            }
        }
    } while (1); // option != 'b' && option != 'B' // make back a exit prompt in the main menu
    return 0;
}
