class Solution {
public:
    void f(vector<int>&nums,vector<vector<int>>&ans,map<int,int>mp,vector<int>&temp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int start=0;start<nums.size();start++){
            if(mp.find(nums[start])==mp.end()){
                temp.push_back(nums[start]);
                mp[nums[start]]++;
                f(nums,ans,mp,temp);
                temp.pop_back();
                mp.erase(nums[start]);
            }
            else{
                continue;
            }
        }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        map<int,int>mp;
        vector<int>temp;
        f(nums,ans,mp,temp);
        return ans;
    }
};
