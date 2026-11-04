class Solution {
public:
// 3 opeation just 
    int f(string w1,string w2,int i,int j,vector<vector<int>> &dp){

        //base
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1)return dp[i][j];

        int a=INT_MAX;
        if(w1[i]==w2[j]){
            return f(w1,w2,i-1,j-1,dp);
        }
        return dp[i][j]=(1+min({f(w1,w2,i-1,j,dp),f(w1,w2,i,j-1,dp),f(w1,w2,i-1,j-1,dp)}));
    }

    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(word1,word2,n-1,m-1,dp);
    }
};
