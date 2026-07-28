#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; 
    cin >> n;

    string s = to_string(n);

    int res = 0;
    while(s != "0")
    {
        int mx = -1;
        for(char c : s)
            mx = max(mx, c - '0');
        
        n = stoi(s);
        n = n - mx;
        s = to_string(n);
        res++;
    }

    cout << res << endl;
}