class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int lt=0;
        int rt=n-1;
        while(lt<=rt){
            int mid=(lt+rt)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>=nums[lt]){
                if(nums[mid]>target && nums[lt]<=target){
                    rt=mid-1;
                }
                else{
                    lt=mid+1;
                }
            }
            else if(nums[mid]<nums[rt]){
                if(nums[mid]<target && nums[rt]>=target){
                    lt=mid+1;
                }
                else{
                    rt=mid-1;
                }
            }
        }
        return -1;
    }
};
