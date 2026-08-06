#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int solve(vector<int>& A, vector<int>& B, int i, int j)
{
    if(i >= A.size() || j >= B.size())
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(A[i] != B[j])
        return dp[i][j] = max(solve(A, B, i, j+1), solve(A, B, i+1, j));
    return dp [i][j] = 1 + solve(A, B, i+1, j+1);
}

int main()
{
    int m, n;

    cin >> n >> m;

    vector<int> A(n), B(m);

    memset(dp, -1, sizeof(dp));
    for(int &a : A)
        cin >> a;

    for(int &a : B)
        cin >> a;
    
    cout << solve(A, B, 0, 0) << endl;
    
    int i = 0,j = 0;
    while(i < n && j < m)
    {
        if(A[i] == B[j])
        {
            cout << A[i] << " ";
            i++;
            j++;
        }
        else
        {
            int resFromA = solve(A, B, i+1, j);
            int resFromB = solve(A, B, i, j+1);

            if(resFromA >= resFromB)
                i++;
            else
                j++;
        }
    }
}