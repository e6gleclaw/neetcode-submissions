class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        int n=numCourses;
        vector<vector<int>>adj(n,vector<int>());
        for(auto ele:pre){
            adj[ele[1]].push_back(ele[0]);
        }
       vector<int> ind(numCourses, 0);
        for(auto ele:adj){
            for(auto ele1: ele){
                ind[ele1]++;
            }
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int temp=q.front();
            ans.push_back(temp);
            count++;
            q.pop();
            for(auto ele:adj[temp]){
                ind[ele]--;
                if(ind[ele]==0)q.push(ele);
            }
        }
        if(count==numCourses){
            return ans;
        }
        return {};
    }
};
