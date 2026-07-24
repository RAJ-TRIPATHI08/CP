#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);

        for(int &x : a)
            cin >> x;

        bool inv = false;
        vector<int> ans;

        for(int i = n - 1; i >= 0; i--)
            if(a[i] > 0 && 0 ^ inv)
            {
                ans.push_back(i);
                inv ^= 1;
            }

        cout << ans.size() << endl;

        for(int &i : ans)
            cout << i + 1 << " ";
        
        cout << endl;
    }
    return 0;
}