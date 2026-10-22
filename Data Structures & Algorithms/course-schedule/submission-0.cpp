class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int n=numCourses;
        vector<vector<int>>adj(n,vector<int>());
        for(auto ele:pre){
            adj[ele[0]].push_back(ele[1]);
        }
       vector<int> ind(numCourses, 0);
        for(auto ele:adj){
            for(auto ele1: ele){
                ind[ele1]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto ele:adj[temp]){
                ind[ele]--;
                if(ind[ele]==0)q.push(ele);
            }
        }
        for(int i=0;i<n;i++){
            if(ind[i]!=0)return false;
        }
        return true;
    }
};
