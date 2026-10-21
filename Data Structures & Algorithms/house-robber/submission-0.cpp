class Solution {
public:
    int f(vector<int>& nums,int i,vector<int>& dp){
        //base
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int pick=nums[i]+f(nums,i+2,dp);
        int nonp=f(nums,i+1,dp);
        return dp[i]= max(pick,nonp);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return f(nums,0,dp);
    }
};
