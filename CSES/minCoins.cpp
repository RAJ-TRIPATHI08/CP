#include<bits/stdc++.h>
using namespace std;
int dp[1000001][101];
int solve(vector<int> &c, int idx, int n)
{
    if(idx >= c.size() || n <= 0)
        return (n == 0)? 0 : INT_MAX - 1;

    int res = -1;

    if(dp[n][idx] != -1)    
        return dp[n][idx];

    if(c[idx] > n)
    {
        int notPick = solve(c, idx+1, n);
        dp[n][idx] = res = notPick;
    }
    else
    {
        int pick = 1 + solve(c, idx, n - c[idx]);
        int notPick = solve(c, idx+1, n);
        dp[n][idx] = res = min(pick, notPick);
    }

    return dp[n][idx] = res;
}

int main()
{
    int n;
    cin >> n;

    int x;
    cin >> x;
    vector<int> c(n);
    for(int &a : c)
        cin >> a;
    memset(dp, -1, sizeof(dp));
    int res = solve(c, 0, x);
    res = (res == INT_MAX-1)? -1 : res;
    cout << res;
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (int &i : c)
        cin >> i;

    const int INF = 1e9;
    vector<int> dp(x + 1, INF);

    dp[0] = 0;

    for (int sum = 1; sum <= x; sum++) 
        for (int coin : c) 
            if (coin <= sum)
                dp[sum] = min(dp[sum], dp[sum - coin] + 1);

    cout << (dp[x] == INF ? -1 : dp[x]);
}