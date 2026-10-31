class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> mp;

        int ans = 0;
        int i = 0, j = 0;
        int n = s.length();
        int mlen = 0;

        while(j < n) {
            mp[s[j]]++;
            mlen = max(mlen, mp[s[j]]);

            if((j-i+1)-mlen > k) {
                mp[s[i]]--;
                i++;
            }

            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};