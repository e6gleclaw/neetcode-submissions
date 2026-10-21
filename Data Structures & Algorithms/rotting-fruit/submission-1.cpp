class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        int ans=0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        int dr[4]={1,0,-1,0};
        int dc[4]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int delr=row+dr[k];
                int delc=col+dc[k];
                if(delr>=0 && delc>=0
                    && delr<n && delc<m && grid[delr][delc]==1)
                {
                    q.push({{delr,delc},t+1});
                    grid[delr][delc]=2;
                    ans=max(ans,t+1);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};
