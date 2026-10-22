class Solution {
public:
    int f(int n,int m,int i, int j,vector<vector<int>> &dp){
        if(i==n-1 && j==m-2 || (i==n-2 && j==m-1))return 1;
        if(i<0 || j<0 || i>n || j>m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        int down=f(n,m,i+1,j,dp);
        int right=f(n,m,i,j+1,dp);
        return dp[i][j]= down+right;
    }
    int uniquePaths(int m, int n) {
        if(m==1 && n==1)return 1;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return f(m,n,0,0,dp);
    }
};
