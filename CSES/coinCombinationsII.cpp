#include<bits/stdc++.h>
using namespace std;
int dp[1000001];
int mod = 1e9 + 7;
int dp[101][1000001];


// memoized code
int solve(vector<int> &coins, int idx, int sum)
{
    if (sum == 0)
        return 1;

    if (idx == coins.size())
        return 0;

    if (dp[idx][sum] != -1)
        return dp[idx][sum];

    long long ans = solve(coins, idx + 1, sum);

    if (coins[idx] <= sum)
        ans += solve(coins, idx, sum - coins[idx]);

    return dp[idx][sum] = ans % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int &c : coins)
        cin >> c;

    memset(dp, -1, sizeof(dp));

    cout << solve(coins, 0, x);
}

// bottom up code

int main()
{
    int n;
    cin >> n;
    int x;
    cin >> x;

    vector<int> coins(n);
    for(int &a : coins)
        cin >> a;

    memset(dp, 0, sizeof(dp));
    // sort(coins.begin(), coins.end());
    dp[0] = 1;
    for (int c : coins)
        for (int i = c; i <= x; i++)
            dp[i] = (dp[i] + dp[i-c]) % mod;
    
    cout << dp[x] << endl;

    return 0;
}