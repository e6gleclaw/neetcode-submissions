class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        int n=s.length();
        for(int i=0;i<n;i++){
            if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z') || ((s[i])>='0' && (s[i])<='9')){
                temp+=tolower(s[i]);
            }
        }
        int t=temp.length();
        int i=0;
        int j=t-1;
        while(i<j){
            if(temp[i]!=temp[j])return false;
            i++;
            j--;
        }
        return true;
    }
};
