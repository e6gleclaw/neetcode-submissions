class Solution {
public:
    void bfs(vector<vector<char>>& grid,int i,int j,vector<vector<int>> &vis,int &n,int &m){
        queue<pair<int,int>>q;
        vis[i][j]=1;
        q.push({i,j});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(row+1<n && grid[row+1][col]=='1' && vis[row+1][col]==-1){
                q.push({row+1,col});
                vis[row+1][col]=1;
            }
             if(row-1>=0 && grid[row-1][col]=='1' && vis[row-1][col]==-1){
                q.push({row-1,col});
                vis[row-1][col]=1;
            }
            if(col+1<m && grid[row][col+1]=='1' && vis[row][col+1]==-1){
                q.push({row,col+1});
                vis[row][col+1]=1;
            }
             if(col-1>=0 && grid[row][col-1]=='1' && vis[row][col-1]==-1){
                q.push({row,col-1});
                vis[row][col-1]=1;
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==-1){
                    ans++;
                    cout<<i<<" "<<j;
                    bfs(grid,i,j,vis,n,m);
                }
            }
        }
        return ans;
    }
};
