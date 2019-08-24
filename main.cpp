#include <iostream>
#include "tictactoe.cpp"
using namespace std;

int main()
{
    tictactoe myGame;
    myGame.get_player_names();
    for (int i = 0;i < 9;i++)
        if (i & 1) {
            system("clear || cls");
            myGame.print_grid();
            cout << "Move of " << myGame.player_2() << " (\033[1m\033[31mX\033[0m): ";
            myGame.input('X');
            if (myGame.if_won()) {
                system("clear || cls");
                myGame.print_grid();
                cout << myGame.player_2() << " wins.\n";
                return 0;
            }
        }
        else {
            system("clear || cls");
            myGame.print_grid();
            cout << "Move of " << myGame.player_1() << " (\033[1m\033[34mO\033[0m): ";
            myGame.input('O');
            if (myGame.if_won()) {
                system("clear || cls");
                myGame.print_grid();
                cout << myGame.player_1() << " wins.\n";
                return 0;
            }
        }
    system("clear || cls");
    myGame.print_grid();
    cout << "Match tied.\n";
    return 0;
}
