class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lt=0;
        int n=matrix.size();
        int m=matrix[0].size();
        int rt=(n*m)-1;
        while(lt<=rt){
            int mid=(lt+rt)/2;
            int r=mid/m;
            int col=mid%m;
            if(matrix[r][col]==target){
                return true;
            }
            else if(matrix[r][col]>target){
                rt=mid-1;
            }
            else{
                lt=mid+1;
            }
        }
        return false;
    }
};
