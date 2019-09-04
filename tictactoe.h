#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include "getch.h"

void sleepcp(int milliseconds);

class tictactoe {
protected:
    char grid[3][3];
public:
    tictactoe();
    void print_grid();
    char input(char);
    bool if_won();
    void do_last_move(char c);
};

#endif
