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
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int max = *max_element(begin(a), end(a));
        int min = *min_element(begin(a), end(a));

        cout << (max - min + 1)/2 << endl;
    }
}