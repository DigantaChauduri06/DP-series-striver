#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int countDistinctWayToClimbStair(long long n)
{
    //  Write your code here.
    if (n == 0 || n == 1) return 1;
    ll op1 = countDistinctWayToClimbStair(n - 2);
    ll op2 = countDistinctWayToClimbStair(n - 1);
    return op1 + op2;
}
int countDistinctWayToClimbStair(long long n,vector<int> &dp)
{
    //  Write your code here.
    if (n == 0 || n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    ll op1 = countDistinctWayToClimbStair(n - 2);
    ll op2 = countDistinctWayToClimbStair(n - 1);
    return dp[n] = op1 + op2;
}
int countDistinctWayToClimbStair(long long n)
{
    vector<int> dp(n + 1,0);
    dp[0] = dp[1] = 1;
    for (int i = 2;i <= n;i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int countDistinctWayToClimbStair(long long n)
{
    int p1 = 1,p2 = 1;
    for (int i = 2;i <= n;i++) {
        int curr = p1 + p2;
        p2 = p1;
        p1 = curr;
    }
    return p1;
}


int main ()
{

  return 0;
}
