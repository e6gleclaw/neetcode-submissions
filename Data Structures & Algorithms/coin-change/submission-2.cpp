class Solution {
public:
    int f(vector<int>& coins,int amount,int i,vector<vector<int>>&dp){
       //base
        if(i==0){
            if(amount>0){
                if(amount%coins[0]==0)return amount/coins[0]; 
            }
            else if(amount==0)return 0;
            return INT_MAX;
        }
        if(dp[amount][i]!=-1)return dp[amount][i];

        int pick=INT_MAX;
        if(amount-coins[i]>=0){
            int res = f(coins, amount - coins[i], i,dp);
            if (res != INT_MAX) {
                pick = 1 + res;
            }
        }
        int nonp=f(coins,amount,i-1,dp);
        return dp[amount][i]=min(pick,nonp);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(amount+1,vector<int>(n+1,-1));
        int ans=f(coins,amount,n-1,dp);
        if(ans>=INT_MAX)return -1;
        return ans;
    }
};
