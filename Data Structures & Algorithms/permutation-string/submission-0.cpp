class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int>mp;
        int n=s1.length();
        int m=s2.length();
        for(int i=0;i<n;i++){
            mp[s1[i]]++;
        }
        int j=0;
        while(j<m){
            if(mp.find(s2[j])!=mp.end()){
                int i=j;
                int start=j;
                int count=0;
                while(j<m && mp[s2[j]]>0){
                    mp[s2[j]]--;
                    j++;
                    count++;
                }
                if(count==n)return true;
                else{
                    while(i<j){
                        mp[s2[i]]++;
                        i++;
                    }
                    j=start+1;
                }
            }
            else{
                j++;
            }
        }
        return false;
    }
};
