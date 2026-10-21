class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>mp;
        int n=nums.size();

        if(n==0)return 0;
        for(int i=0;i<n;i++){
            mp.insert(nums[i]);
        }
        int ans=1;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]+1)==mp.end()){
                int temp=0;
                int ele=nums[i];
                while(mp.find(ele--)!=mp.end()){
                    temp++;
                }
                ans=max(temp,ans);
            }
        }
        return ans;
    }
};
