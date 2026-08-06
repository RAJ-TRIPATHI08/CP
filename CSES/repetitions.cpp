#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.size();
    int res = 1, len = 1;
    for(int i = 1; i < n; i++)
    {
        if(s[i] == s[i-1])
            len++;
        else 
        {
            res = max(len, res);
            len = 1;
        }
    }
    cout << max(res,len);
}