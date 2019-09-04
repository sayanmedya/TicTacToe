#include "hardlevel.h"
using namespace std;

bool hardlevel::check_winning(char ch, int& x, int& y)
{
    for (int i = 0;i < 3;i++)
        for (int j = 0;j < 3;j++)
            if (grid[i][j] == '-' && grid[i][(j + 1) % 3] == ch && grid[i][(j + 2) % 3] == ch) {
                x = i;
                y = j;
                return 1;
            }
    for (int i = 0;i < 3;i++)
        for (int j = 0;j < 3;j++)
            if (grid[j][i] == '-' && grid[(j + 1) % 3][i] == ch && grid[(j + 2) % 3][i] == ch) {
                x = j;
                y = i;
                return 1;
            }
    for (int j = 0;j < 3;j++)
        if (grid[j][j] == '-' && grid[(j + 1) % 3][(j + 1) % 3] == ch && grid[(j + 2) % 3][(j + 2) % 3] == ch) {
            x = j;
            y = j;
            return 1;
        }
    for (int j = 0;j < 3;j++)
        if (grid[j][2 - j] == '-' && grid[(j + 1) % 3][2 - (j + 1) % 3] == ch && grid[(j + 2) % 3][2 - (j + 2) % 3] == ch) {
            x = j;
            y = 2 - j;
            return 1;
        }
    return 0;
}

char hardlevel::another(char ch)
{
    if (ch == 'X')
        return 'O';
    else
        return 'X';
}

int hardlevel::dfs(char ch)
{
    ///***IMPORTANT***///
    // Comments marked with //**V** are for most optimamum strategy
    // they make sure the user has least no of choice for defending or winning the game
    // but they make the game monotonous
    // uncoment them to use those strategy
    int x, y;
    if (check_winning(ch, x, y))
        return 100;// the char being called is winning
    else if (check_winning(another(ch), x, y)) {
        grid[x][y] = ch;
        int ans = -1 * dfs(another(ch));
        grid[x][y] = '-';// make the position back to normal '-'
        return ans;
    }
    else {
        int count_empty = 0, max = INT32_MIN;
        // int count_loss = 0; //**V**
        for (int i = 0;i < 3;i++)
            for (int j = 0;j < 3;j++) {
                if (grid[i][j] == '-') {
                    count_empty++;
                    grid[i][j] = ch;
                    int temp = -1 * dfs(another(ch));
                    // if (temp == -100) //**V**
                    //     count_loss--; //**V**
                    if (temp > max)
                        max = temp;
                    grid[i][j] = '-';
                }
            }
        // if (max != 100 && max != -100) //**V**
        //     max = count_loss; //**V**
        if (count_empty > 0)
            return max;
        else
            return 0;
    }
}

void hardlevel::make_move()
{
    if (is_winning('X'));
    else if (is_winning('O'));
    else {
        // rather than using random moves try to check all possible cases and find the best moves;
        vector <pair <int, pair<int, int>>> list;
        for (int i = 0;i < 3;i++)
            for (int j = 0;j < 3;j++) {
                if (grid[i][j] == '-') {
                    grid[i][j] = 'X';
                    int temp = -1 * dfs(another('X'));
                    list.push_back({temp, {i, j}});
                    grid[i][j] = '-';
                }
            }
        sort(list.begin(), list.end(), greater<>());
        int size = 1;
        for (;size < list.size() && list[size].first == list[0].first;size++);
        srand(time(NULL));
        int in = rand() % size;
        grid[list[in].second.first][list[in].second.second] = 'X';
        push_new_done(list[in].second.first, list[in].second.second);
    }
}