#include<bits/stdc++.h>
using namespace std;

using ll = long long;

bool isPrime(ll n)
{
    for(ll i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
            return false;
    }

    return true;
}

ll solve(ll n)
{
    if(n == 2)
        return n;

    if(n%2 == 0)
        n++;

    while(!isPrime(n))
        n+=2;

    return n;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        ll n;
        cin >> n;

        cout << solve(n) << endl;
    }
    return 0;
}