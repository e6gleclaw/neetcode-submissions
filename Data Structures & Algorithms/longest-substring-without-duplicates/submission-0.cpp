class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int i=0;
        int j=0;
        int n=s.length();
        int ans=0;
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                i=max(i,mp[s[j]]+1);
            }
            mp[s[j]]=j;
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
