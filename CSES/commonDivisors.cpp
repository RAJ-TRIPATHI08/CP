#include<bits/stdc++.h>
using namespace std;

int maxGCD(vector<int> a)
{
    int mx = *max_element(begin(a), end(a));
    vector<int> freq(mx+1, 0);

    for(int x : a)
        freq[x]++;

    for(int g = mx; g >= 1; g--)
    {
        int cnt = 0;
        for(int mult = g; mult <= mx; mult += g)
        {
            cnt += freq[mult];
            if(cnt >= 2)
                return g;
        }
    }

    return 1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for(int &x : a)
        cin >> x;

    cout << maxGCD(a);
}