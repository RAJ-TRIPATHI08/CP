#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int mod = 1e9+7;
int solve(int i, int j, int n, vector<vector<int>>& grid)
{
    if(i >= n || j >= n)
        return 0;
    if(grid[i][j] == 0)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(i == n-1 && j == n-1)
        return 1;
    
    int right = solve(i, j+1, n, grid);

    int down = solve(i+1, j, n, grid); 

    return dp[i][j] = (right+down)%mod;
}

int noOfWays(vector<vector<int>>& grid)
{
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, grid.size(), grid);
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char c;
            cin >> c;

            if(c == '.')
                grid[i][j] = 1;
            else
                grid[i][j] = 0;
        }
    }

    cout << noOfWays(grid);
}