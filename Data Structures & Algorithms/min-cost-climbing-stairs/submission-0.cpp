class Solution {
public:
    int f(vector<int>& cost,int i,vector<int> &dp){
        //base case
        if(i>=cost.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int one =cost[i]+f(cost,i+1,dp);
        int two=cost[i]+f(cost,i+2,dp);
        return dp[i]= min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n =cost.size();
        vector<int>dp(n+1,-1);
        return min(f(cost,0,dp),f(cost,1,dp));
    }
};
