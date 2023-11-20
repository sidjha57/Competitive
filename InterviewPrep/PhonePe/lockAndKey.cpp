#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
#include <string>
#include <map>

using namespace std;

int minMovesToGetAllmask(vector<string> &grid)
{
    int n = grid.size(), m = grid[0].size(), key_count = 0;
    vector<int> start{0, 0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '@')
                start = {i, j};
            if (grid[i][j] >= 'a' && grid[i][j] <= 'f') key_count++;
        }
    }

    vector<vector<int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    queue<pair<vector<int>, int>> bfsQueue;
    bfsQueue.push({{start[0], start[1], 0}, 0});
    map<vector<int>, bool> vis;
    vis[{start[0], start[1], 0}] = true;


    while (!bfsQueue.empty())
    {
        auto node = bfsQueue.front();
        vector<int> cur = node.first;
        int mask = node.second;

        bfsQueue.pop();

        if (__builtin_popcount(mask) == key_count)
            return cur[2];
        

        for (auto &dir : dirs)
        {
            mask = node.second;

            int x = cur[0] + dir[0], y = cur[1] + dir[1];

            if (x >= 0 && x < n && y >= 0 && y < m)
            {
                if (vis.find({x, y, mask}) != vis.end() && grid[x][y] == '#')
                    continue;

                if (grid[x][y] == '.')
                    bfsQueue.push({{x, y, cur[2] + 1}, mask});

                else if (grid[x][y] >= 'A' && grid[x][y] <= 'F'  && (mask >> (tolower(grid[x][y]) - 'a')&1))
                    bfsQueue.push({{x, y, cur[2] + 1}, mask});

                else if (grid[x][y] >= 'a' && grid[x][y] <= 'f')
                {
                    int pos = grid[x][y] - 'a';
                    mask |= (1 << pos);
                    bfsQueue.push({{x, y, cur[2] + 1}, mask});
                }

                vis[{x, y, mask}] = 1;
            } 
            
        }
    }

    return -1;
}


int main () {

//     6
// a@#
// Ab.
// .B#
// ..#
// #..
// ...
    vector<string> grid {
        "a@#",
        "Ab.",
        ".B#",
    };
    cout << minMovesToGetAllmask(grid);
    return 0;
}