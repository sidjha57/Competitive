#include <vector>  
#include <iostream>     
#include <climits>
#include <queue>

using namespace std;

int minDiceThrowToLastCell(vector<vector<int>>& board, int n) {
vector<int> arr(n * n + 1);
    int k = 1;
    bool flip = false;

    for (int i = n - 1; i >= 0; i--) {
        if (flip) {
            for (int j = n - 1; j >= 0; j--, k++) {
                arr[k] = board[i][j];
            }
        } else {
            for (int j = 0; j < n; j++, k++) {
                arr[k] = board[i][j];
            }
        }                                                                                           
        flip = !flip;
    }

    vector<int> vis (n*n+1, 0);
    queue<pair<int,int>> bfsQueue;

    bfsQueue.push({1,0});
    vis[0] = 1;

    while(!bfsQueue.empty()) {
       auto cur = bfsQueue.front();
       int curPlace = cur.first, dist = cur.second;        
       bfsQueue.pop();

       if (curPlace == n*n) 
            return dist;

       for (int x=1; x<=6; x++) {
           int nextPos = (arr[x+curPlace] == -1) ? (x + curPlace) : arr[x+curPlace];

           if (!vis[nextPos]) {
               bfsQueue.push({nextPos, dist+1});
               vis[nextPos] = 1;
           }
       }
    }
    
    return -1;
}

int main() {
    const int n = 6;

    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}
    };

    vector<vector<int>> board1 = {
        {-1, 1, -1},        
        {-1, -1, 9},
        {-1, 4, -1}
    };

    int result = minDiceThrowToLastCell(board1, 3);

    cout << "Minimum number of dice throws to reach the last cell: " << result << endl;

    return 0;
}


