#include<bits/stdc++.h>
using namespace std;

int findMissingElement(vector<int>& nums, int n) 
{
    int max = *max_element(begin(nums), end(nums));
    int min = *min_element(begin(nums), end(nums));
    unordered_set<int> seen(nums.begin(), nums.end());

    vector<int> res;

    for(int i = 1; i <= n; i++)
    {
        if(!seen.count(i))
            return i;
    }
    return -1;
}

int main ()
{
    int n;
    cin >> n;

    vector<int> A(n);

    for(int i = 0; i < n-1; i++)
        cin >> A[i];

    cout << findMissingElement(A, n);
}