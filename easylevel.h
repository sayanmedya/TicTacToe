#ifndef EASYLEVEL_DECLARATION
#define EASYLEVEL_DECLARATION

#include "tictactoe.h"

class easylevel:public tictactoe {
    protected:
        bool is_winning();
        bool is_losing();
        void random_move();
    public:
        void make_move();
};

#endif