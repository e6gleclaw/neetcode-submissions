class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int arrl[n];
        int arrr[n];
        arrl[0]=1;
        for(int i=1;i<n;i++){
            arrl[i]=arrl[i-1]*nums[i-1];
        }
        arrr[n-1]=1;
        for(int i=n-2;i>=0;i--){
            arrr[i]=nums[i+1]*arrr[i+1];
        }
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            ans[i]=arrl[i]*arrr[i];
        }
        return ans;
    }
};
