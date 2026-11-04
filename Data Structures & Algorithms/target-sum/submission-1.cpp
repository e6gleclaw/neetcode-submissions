class Solution {
public:

    int f(vector<int>& nums,int target,int i,int curs,vector<vector<int>> &dp,int S){

        if(i==nums.size() && curs==target)return 1;
        if(i==nums.size() && target!=curs)return 0;
        int ind=curs+S;
        if(dp[i][ind]!=-1)return dp[i][ind];
        int add=0;
        add=f(nums,target,i+1,curs+nums[i],dp,S);
        int sub=0;
        sub=f(nums,target,i+1,curs-nums[i],dp,S);

        return dp[i][ind]= add+sub;

    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int S = 0;
        for (int x : nums) {
            S += x;
        }
        if (target > S || target < -S) {
            return 0;
        }
        vector<vector<int>> dp(n+1, vector<int>(2 * S + 1, -1));
        return f(nums,target,0,0,dp,S);
    }
};
