class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
    pair<int, pair<int, int>>,
    vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>
> pq;
        for(auto ele:points){
            int x=ele[0];
            int y=ele[1];
            int dis=(x*x+y*y);
            pq.push({dis,{x,y}});
        }
        vector<vector<int>>ans;
        while(k--){
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            vector<int>temp={x,y};
            ans.push_back(temp);
        }
        return ans;
    }
};
