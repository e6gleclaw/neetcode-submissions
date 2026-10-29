class Solution {
public:
    void f(vector<int>& nums,vector<vector<int>>& ans,vector<int>& temp,int ind){
        if(ind==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(temp[i],temp[ind]);
            f(nums,ans,temp,ind+1);
            swap(temp[i],temp[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>>ans;
      vector<int>temp(nums.begin(),nums.end());
      f(nums,ans,temp,0);
      return ans;
    }
};
