#ifndef TICTACTOE_DECLARATION
#define TICTACTOE_DECLARATION

class tictactoe {
protected:
    char grid[3][3];

public:
    tictactoe();
    void print_grid();
    void input(char);
    bool if_won();
};

#endif