class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    while(j<k && nums[j+1]==nums[j])j++;
                    while(j<k && nums[k-1]==nums[k])k--;
                    j++;k--;
                }
                else if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }
                else{
                    j++;
                }
            }
            while(i+1<n && nums[i]==nums[i+1])i++;
        }
        return ans;
    }
};
