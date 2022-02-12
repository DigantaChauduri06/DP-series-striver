#include<bits/stdc++.h>
using namespace std;

int helper(int idx,vector<int> &heights,vector<int> &dp) {
    if (idx == 0) return 0;
    if (dp[idx] != -1) return dp[idx];
    int oneStep = abs(heights[idx] - heights[idx - 1]) + helper(idx - 1, heights,dp);
    int twoStep = INT_MAX;
    if (idx > 1) {
        twoStep = abs(heights[idx] - heights[idx - 2]) + helper(idx - 2, heights,dp);
    }
    return dp[idx] = min(oneStep,twoStep);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    int idx = n - 1;
    vector<int> dp(n , -1);
    return helper(idx,heights,dp);
}
/*----------------------------------------------------------------------------------------------*/
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n);
    dp[0] = 0;
    for (int i = 1;i < n;i++) {
        int oneStep = dp[i - 1] + abs(heights[i - 1] - heights[i]);
        int twoStep = INT_MAX;
        if (i > 1)
         twoStep = dp[i - 2] + abs(heights[i - 2] - heights[i]);
        dp[i] = min(oneStep, twoStep);
    } 
    return dp[n - 1];
}
/* ---------------------------------------------------------------------------------------------------------- */
// https://leetcode.com/problems/min-cost-climbing-stairs/
int frogJump(int n, vector<int> &heights)
{
    int prev1 = 0;
    int prev2 = 0;
    for (int i = 1;i < n;i++) {
        int oneStep = prev1 + abs(heights[i - 1] - heights[i]);
        int twoStep = INT_MAX;
        if (i > 1)
         twoStep = prev2 + abs(heights[i - 2] - heights[i]);
        int curr = min(oneStep, twoStep);
        prev2 = prev1;
        prev1 = curr;
    } 
    return prev1;
}

int main ()
{
    int N,K;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0;i < N;i++) {
        cin >> arr[i];
    }
  cout << frogJump(N,arr);

  return 0;
}
