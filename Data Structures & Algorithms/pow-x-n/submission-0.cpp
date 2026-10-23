class Solution {
public:
    double myPow(double x, int n) {
        int po=n;
        double ans=1;
        if(n<0){
            po=po*(-1);
        }
        while(po){
            if(po%2==1){
                po--;
                ans=ans*x;
            }
            else{
                po=po/2;
                x*=x;
            }
        }
        if(n<0)return 1/ans;
        return ans;
    }
};
