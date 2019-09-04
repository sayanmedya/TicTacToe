#ifndef EASYLEVEL_H
#define EASYLEVEL_H

#include <iostream>
#include <vector>
#include <ctime>
#include "tictactoe.h"
#define pii pair<int, int>
using namespace std;

class easylevel:public tictactoe {
    public:
        bool is_winning(char ch);
        void random_move();
        vector <pii> st_done;
        vector <pair<pii, char>>st_undone;
        easylevel();
        void undo();
        void redo();
        void push_new_done(int x, int y);
        void make_move();
        char input(char);
        void do_last_move(char c);
};

#endif
