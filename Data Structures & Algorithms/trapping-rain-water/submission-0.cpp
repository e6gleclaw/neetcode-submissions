class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>suff(n,0);
        vector<int>pref(n,0);
        suff[0]=0;
        int suffm=height[0];
        pref[n-1]=0;
        int prefm=height[n-1];
        for(int i=1;i<n;i++){
            suff[i]=suffm;
            suffm=max(height[i],suffm);
            pref[n-i-1]=prefm;
            prefm=max(prefm,height[n-i-1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(pref[i]>height[i] && suff[i]>height[i]){
                ans+=(min(pref[i],suff[i])-height[i]);
            }
        }
        return ans;
    }
};
