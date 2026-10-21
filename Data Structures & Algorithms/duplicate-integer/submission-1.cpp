class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>st;
       for(int i=0;i<nums.size();i++){
        st.insert(nums[i]);
       } 
       return (nums.size()!=st.size());
    }
};