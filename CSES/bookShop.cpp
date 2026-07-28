#include<bits/stdc++.h>
using namespace std;
int dp[1001][100001];
// memoized code

int maxPages(int idx, int n, int x, vector<pair<int, int>>& books)
{
    if(idx >= n || x <= 0)
        return 0;

    if(dp[idx][x] != -1)
        return dp[idx][x];
        
    int res = 0;

    if(books[idx].first > x)
    {
        int notPick = maxPages(idx+1, n, x, books);
        dp[idx][x] = res = notPick;
    }
    else
    {
        int pick = books[idx].second + maxPages(idx+1, n, x - books[idx].first, books);
        int notPick = maxPages(idx+1, n, x, books);
        dp[idx][x] = res = max(pick, notPick);
    }

    return dp[idx][x] = res;
}

// bottom up code

int main()
{
    int n, x;
    cin >> n >> x;


    vector<pair<int, int>> books(n);    // {price, pages}

    for(int i = 0; i < n; i++)
        cin >> books[i].first;


    for(int i = 0; i < n; i++)
        cin >> books[i].second;

    memset(dp, -1, sizeof(dp));
    cout << maxPages(0, n, x, books);
}


int main() {
    int n, x;
    cin >> n >> x;

    vector<int> price(n), pages(n);

    for (int &p : price) cin >> p;
    for (int &p : pages) cin >> p;

    vector<int> dp(x + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = x; j >= price[i]; j--) {
            dp[j] = max(dp[j], pages[i] + dp[j - price[i]]);
        }
    }

    cout << dp[x];
}