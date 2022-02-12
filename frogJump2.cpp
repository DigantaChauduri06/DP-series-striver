#include<bits/stdc++.h>
using namespace std;

int helper(vector<int> &arr,int idx,int k,vector<int> &dp) {
  if (idx == 0) return 0;
  if (dp[idx] != -1) return dp[idx];
  int mini = INT_MAX;
  int ways = INT_MAX;
  for (int i = 1;i <=k;i++) {
    if (idx > i - 1)
      ways = abs(arr[idx] - arr[idx - i]) + helper(arr, idx - i,k,dp);
    mini = min(ways,mini);
  }
  return dp[idx] = mini;
}

int getFrogJump(vector<int> &arr,int n, int k) {
  int idx = n - 1;
  vector<int> dp(n,-1);
  return helper(arr,idx,k,dp); 
}


int main ()
{
    int N,K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0;i < N;i++) {
        cin >> arr[i];
    }
  cout << getFrogJump(arr,N,K);
  return 0;
}
