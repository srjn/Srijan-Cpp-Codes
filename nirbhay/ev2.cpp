#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int rec(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        int m = dp.size();
        int n = dp[0].size();

        if (i < 0 or i >= m or j < 0 or j >= n)
            return 0;

        if (i == m - 1 and j == n - 1)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = 0;
        int right = 0;
        int up=0;
        int left=0;

        //up
        if (i - 1 >= 0 and i - 1 < m and j >= 0 and j < n and grid[i-1][j]!=1)
            up = rec( i - 1, j, dp, grid);
        // down
        if (i + 1 >= 0 and i + 1 < m and j >= 0 and j < n and grid[i+1][j]!=1)
            down = rec( i + 1, j, dp, grid);

        //left
        if (i >= 0 and i < m and j + 1 >= 0 and j - 1 < n and grid[i][j-1]!=1)
            left = rec( i, j - 1, dp, grid);

        // right
        if (i >= 0 and i < m and j + 1 >= 0 and j + 1 < n and grid[i][j+1]!=1)
            right = rec( i, j + 1, dp, grid);

        return dp[i][j] = up + left+ down +right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0]==1)
        return 0;

        vector<vector<int>> dp(m, vector<int> (n, -1));

        return rec(0, 0, dp, obstacleGrid);
    }

    int main(){
        vector<vector<int>> v(2);
        v.push_back({0,0});
         v.push_back({0,0});

        cout<<uniquePathsWithObstacles(v);
        cout<<"Srijan";
        return 0;
    }