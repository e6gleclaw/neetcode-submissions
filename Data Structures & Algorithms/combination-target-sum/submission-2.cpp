class Solution {
public:
    void f(vector<int>&nums,vector<vector<int>>&ans,int target,int i,vector<int>&temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i==nums.size()){
            return;
        }
        f(nums,ans,target,i+1,temp);
        if(target-nums[i]>=0){
            temp.push_back(nums[i]);
            f(nums,ans,target-nums[i],i,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(nums,ans,target,0,temp);
        return ans;
    }
};
