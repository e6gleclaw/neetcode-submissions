class Solution {
public:

    int f(int amount,vector<int>& coins,int i,vector<vector<int>> &dp){
        if(amount==0)return 1;
        if(i>=coins.size())return 0;
        if(dp[i][amount]!=-1)return dp[i][amount];
        int pick=0;
        if(amount>=coins[i]){
            pick=f(amount-coins[i],coins,i,dp);
        }
       int nonp= f(amount,coins,i+1,dp);
       return dp[i][amount]=pick+nonp;

    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return f(amount,coins,0,dp);
    }
};
