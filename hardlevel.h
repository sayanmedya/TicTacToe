#ifndef HARDLEVEL_H
#define HARDLEVEL_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "easylevel.h"

class hardlevel:public easylevel {
    protected:
        char another(char ch);
        int dfs(char ch);
        bool check_winning(char ch, int& x, int& y);
    public:
        void make_move();
};

#endif