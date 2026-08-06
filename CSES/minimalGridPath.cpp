/*
memoized code
#include<bits/stdc++.h>
using namespace std;
string dp[3001][3001];
bool vis[3001][3001];
int n;

string solve(int i, int j, vector<string>& g) 
{
    if (i >= n || j >= n)
        return "["; 

    if (i == n - 1 && j == n - 1)
        return string(1, g[i][j]);

    if (vis[i][j])
        return dp[i][j];

    vis[i][j] = true;

    string down = solve(i + 1, j, g);
    string right = solve(i, j + 1, g);

    return dp[i][j] = g[i][j] + min(down, right);
}

int main()
{
    cin >> n;

    vector<string> g(n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];

    memset(vis, false, sizeof(vis));

    cout << solve(0, 0, g);
}
*/

