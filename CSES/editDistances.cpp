#include<bits/stdc++.h>
using namespace std;

int dp[5001][5001];
int m, n;
int solve(string &s, string &t, int i, int j)
{
    if(i == m)
        return n - j;

    if(j == n)
        return m - i;

    if(dp[i][j] != -1)
        return dp[i][j];

    int res = 0;
    if(s[i] == t[j])
        dp[i][j] = res = solve(s, t, i+1, j+1);

    if(s[i] != t[j])
        dp[i][j] = res = 1 + min({solve(s, t, i+1, j+1), solve(s, t, i+1, j), solve(s, t, i, j+1)});

    return dp[i][j] = res;
}

int main()
{
    string s, t;
    cin >> s >> t;
    memset(dp, -1, sizeof(dp));
    m = s.size();
    n = t.size();
    cout << solve(s, t, 0, 0);
}