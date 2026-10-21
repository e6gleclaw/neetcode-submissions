class Solution {
public:
    void f(vector<int>&nums, vector<vector<int>>&ans,int i,vector<int>temp){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        f(nums,ans,i+1,temp);
        temp.push_back(nums[i]);
        f(nums,ans,i+1,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        f(nums,ans,0,temp);
        return ans;
    }
};
