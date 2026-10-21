class Solution {
public:
    int f(vector<int>& nums,int i,vector<int>& dp){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int pick=nums[i]+f(nums,i+2,dp);
        int nonp=f(nums,i+1,dp);
        return dp[i]= max(pick,nonp);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
         if (n == 1) return nums[0];
        vector<int>nums1(nums.begin()+1,nums.end());
        vector<int>nums2(nums.begin(),nums.end()-1);
        return max(f(nums1,0,dp1),f(nums2,0,dp2));
    }
};
