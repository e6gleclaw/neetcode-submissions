class Solution {
public:
    int bfs(vector<vector<int>>& grid,vector<vector<int>>&vis,int i, int j,int n, int m){
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        int temp=0;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            temp++;
            q.pop();
            if(row+1<n && vis[row+1][col]==-1 && grid[row+1][col]){
                vis[row+1][col]=1;
                q.push({row+1,col});
            }
            if(row-1>=0 && vis[row-1][col]==-1 && grid[row-1][col]){
                vis[row-1][col]=1;
                q.push({row-1,col});
            }
            if(col+1<m && vis[row][col+1]==-1 && grid[row][col+1]){
                vis[row][col+1]=1;
                q.push({row,col+1});
            }
            if(col-1>=0 && vis[row][col-1]==-1 && grid[row][col-1]){
                vis[row][col-1]=1;
                q.push({row,col-1});
            }
        }
        return temp;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       int ans=0;
       vector<vector<int>>vis(n,vector<int>(m,-1));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && vis[i][j]==-1){
               int t= bfs(grid,vis,i,j,n,m);
                ans=max(ans,t);
            }
        }
       }
       return ans;
    }
};
