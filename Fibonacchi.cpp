#include<bits/stdc++.h>
using namespace std;
int fib(int n,vector<int> &dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fib(n - 1,dp) + fib(n - 2,dp);
}
int fib_tab(int n) {
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2;i <= n;i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int fib_best(int n) {
    int prev = 0;
    int prev2 = 1;
    for (int i = 2;i <= n;i++) {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
int main ()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    int ans = fib(n,dp);
    cout << ans;
  return 0;
}
