class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<pair<int,int>>dq;
       vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(dq.empty() || dq.back().first>nums[i]){
                dq.push_back({nums[i],i});
            }
            else if(dq.back().first<=nums[i]){
                while(!dq.empty() && nums[i]>dq.back().first){
                    dq.pop_back();
                }
                dq.push_back({nums[i],i});
            }
            while(!dq.empty() && (i+1-dq.front().second)>k){
                dq.pop_front();
            }
            if(i+1>=k){
                ans.push_back(dq.front().first);
            }
        }
        return ans;
    }
};
