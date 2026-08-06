#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;

int n, m;
vector<int> arr;
vector<vector<int>> dp;

int solve(int idx, int k)
{
    if(idx == n)
        return 1;

    if(dp[idx][k] != -1)
        return dp[idx][k];

    ll ans = 0;

    if(arr[idx] != 0)
    {
        if(abs(arr[idx] - k) <= 1)
            ans = solve(idx + 1, arr[idx]);
    }
    else
    {
        for(int val = max(1, k - 1); val <= min(m, k + 1); val++)
        {
            ans = ((ans)%MOD + (solve(idx + 1, val))%MOD) % MOD;
        }
    }

    return dp[idx][k] = ans;
}

int main()
{
    cin >> n >> m;

    arr.resize(n);

    for(int &x : arr)
        cin >> x;

    dp.assign(n, vector<int>(m + 1, -1));

    ll ans = 0;

    if(arr[0] == 0)
    {
        for(int val = 1; val <= m; val++)
            ans = (ans + solve(1, val)) % MOD;
    }
    else
    {
        ans = solve(1, arr[0]);
    }

    cout << ans;
}