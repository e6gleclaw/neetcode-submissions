class Solution {
public:
    void f(vector<int>& cand,int target,vector<vector<int>>&st,vector<int>&temp,int start){
        if(target==0){
            st.push_back(temp);
            return;
        }
        if(start==cand.size()){
            return;
        }
        for(int i=start;i<cand.size();i++){
            if(i>start && cand[i]==cand[i-1]){
                continue;
            }
            if(target-cand[i]>=0){
                temp.push_back(cand[i]);
                f(cand,target-cand[i],st,temp,i+1);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>st;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        f(candidates,target,st,temp,0);
        return st;
    }
};
