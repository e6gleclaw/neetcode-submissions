class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>mp;
        int n=t.length();
        int m=s.length();
        for(char c:t){
            mp[c]++;
        }
        int lt=0;
        int rt=0;
        int start=0;
        int minl=INT_MAX;
        int cnt=0;
        while(rt<m){
            if(mp.find(s[rt])!=mp.end() && mp[s[rt]]>0){
                cnt++;
                while(cnt==n){
                    if(rt-lt+1<minl){
                        start=lt;
                        minl=rt-lt+1;

                    }
                    mp[s[lt]]++;
                    if(mp[s[lt]]>0)cnt--;
                    lt++;
                }
            }
            mp[s[rt]]--;
            rt++;
        }
        if(minl==INT_MAX)return "";
        string ans=s.substr(start,minl);
        return ans;
    }
};

// if char in map with freq>0 then cnt++ and freq-- .. if cnt is valid then update the minlen and start index.
//while cnt is valid i try to shrink it till valid ie lt++;
