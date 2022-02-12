#include<bits/stdc++.h>
using namespace std;
// #1
class Solution {
public:
    int rob(vector<int>& nums) {
        int idx = 0;
        vector<int> dp(nums.size()+1,-1);
        return helper1(idx,nums,dp);
    }
private:
    int helper1(int idx, vector<int> &nums,vector<int> &dp) {
        if (nums.size() <= idx) return 0;
        if (dp[idx] != -1) return dp[idx];
        int op1 = nums[idx] + helper1(idx+2,nums,dp);
        int op2 = helper1(idx+1,nums,dp);
        return dp[idx] = max(op1,op2);
    }
    
};
// #2
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0],nums[1]);
        int idx = 0;
        vector<int> dp(nums.size()+1);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for (int i = 2;i < nums.size();i++) {
            int op1 = nums[i] + dp[i - 2];
            int op2 = dp[i - 1];
            dp[i] = max(op1,op2);
        }
        return dp[nums.size() - 1];
    }
};
// #3
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = nums[0];
        int prev2 = max(nums[0],nums[1]);
        for(int i = 2;i < nums.size();i++) {
            int op1 = nums[i] + prev1;
            int op2 = prev2;
            int curr = max(op1,op2);
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
    
};
int main ()
{

  return 0;
}
