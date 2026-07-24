#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        
        vector<int> a(n), b(n);

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for(int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        for(int i = 0; i < n; i++)
        {
            int x = min(a[i], b[i]);
            int y = max(a[i], b[i]);
            
            a[i] = x;
            b[i] = y;
        }

        ll max = *max_element(begin(a), end(a));

        for(int x : b)
            max += x;
        
        cout << max << endl;
    }
    return 0;
}