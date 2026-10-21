class Solution {
public:
    int maxArea(vector<int>& heights) {
       int n=heights.size();
       int i=0;
       int j=n-1;
       int ans=INT_MIN;
       while(i<j){
            int cap=min(heights[i],heights[j])*(j-i);
            ans=max(ans,cap);
            if(heights[i]>heights[j])j--;
            else{
                i++;
            }
       }
       return ans; 
    }
};
