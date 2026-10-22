class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int curs=0;
        for(int i=0;i<nums.size();i++){
            curs+=nums[i];
            ans=max(ans,curs);
            if(curs<0)curs=0;
        }
        return ans;
    }
};
