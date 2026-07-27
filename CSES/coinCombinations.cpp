#include<bits/stdc++.h>
using namespace std;
int dp[1000001];
int mod = 1e9 + 7;

// memoized code
int numberOfWays(vector<int> &coins, int amt)
{
    if(amt == 0)
        return 1;

    if(amt < 0)
        return 0;

    if(dp[amt] != -1)
        return dp[amt];
    
    int res = 0;

    for(int i = 0; i < coins.size(); i++)
        res = (res + numberOfWays(coins, amt - coins[i]))%mod;

    return dp[amt] = res;
}

int main()
{
    int n;
    cin >> n;
    int x;
    cin >> x;

    vector<int> coins(n);
    for(int &a : coins)
        cin >> a;

    memset(dp, -1, sizeof(dp));

    cout << numberOfWays(coins, x);

    return 0;
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
    sort(coins.begin(), coins.end());
    dp[0] = 1;
    for(int i = 1; i <= x; i++)
        for (int c : coins) 
        {
            if (c > i) break;
            dp[i] += dp[i-c];
            if (dp[i] >= mod) dp[i] -= mod;
        }
    cout << dp[x] << endl;

    return 0;
}