#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
using ll = long long;
vector<ll> dp;

// memoized code
ll solve(int n)
{
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;

    if(dp[n] != -1)
        return dp[n];
    
    ll rolls = 0;

    for(int roll = 1; roll <= 6; roll++)
        rolls = (rolls + solve(n - roll)) % mod;

    return dp[n] = rolls;
}

int main()
{
    int n; 
    cin >> n;
    dp.resize(n+1, -1);
    cout << solve(n);
    return 0;
}

// bottom up code

int main()
{
    int n; 
    cin >> n;

    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++)
        for(int roll = 1; roll <= 6; roll++)
            if(i >= roll)
                dp[i] = (dp[i] + dp[i-roll]) % mod;

    cout << dp[n];
}