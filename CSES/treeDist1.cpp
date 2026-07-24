#include<bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<ll>> tree;
vector<ll> dist;

void dfs(ll u, ll par)
{
    for(ll v : tree[u])
    {
        if(v != par)
        {
            dist[v] = dist[u] + 1;
            dfs(v, u);
        }
    }
}

int main()
{
    ll n;
    cin >> n;

    tree.resize(n);

    for(int i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;

        a--;
        b--;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // First DFS from 0
    dist.assign(n, 0);
    dfs(0, -1);

    ll A = 0;

    for(int i = 0; i < n; i++)
    {
        if(dist[i] > dist[A])
        {
            A = i;
        }
    }

    // Second DFS from A
    dist.assign(n, 0);
    dfs(A, -1);

    vector<ll> distA = dist;

    ll B = A;

    for(int i = 0; i < n; i++)
    {
        if(dist[i] > dist[B])
        {
            B = i;
        }
    }

    // Third DFS from B
    dist.assign(n, 0);
    dfs(B, -1);

    vector<ll> distB = dist;

    for(int i = 0; i < n; i++)
    {
        cout << max(distA[i], distB[i]) << " ";
    }

    return 0;
}