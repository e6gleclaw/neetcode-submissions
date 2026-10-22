class Solution {
public:
    int f(string t1,string t2,int i,int j,int n, int m,vector<vector<int>>&dp){
        //base
       if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int take=0;
        if(t1[i]==t2[j]){
            take=1+f(t1,t2,i-1,j-1,n,m,dp);
        }
        int one=f(t1,t2,i-1,j,n,m,dp);
        int two=f(t1,t2,i,j-1,n,m,dp);
        return dp[i][j]=max(take,max(one,two));
    }


    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(text1,text2,n-1,m-1,n,m,dp);
    }
};
