class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        int lt=0;
        int rt=n-1;
        int ans=INT_MAX;
        while(lt<=rt){
            int mid=(lt+rt)/2;
            if(nums[mid]>=nums[lt]){
                ans=min(ans,nums[lt]);

                lt=mid+1;
            }
            else if(nums[mid]<=nums[rt]){
                ans=min(ans,nums[mid]);
                rt=mid-1;
            }
        }
        return ans;
    }
};
