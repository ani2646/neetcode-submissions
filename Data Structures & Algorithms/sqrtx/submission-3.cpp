class Solution {
public:
    int mySqrt(int x) {
        int i = 0;
        int j = x;

        if(x==1){
            return 1;
        }

        while(i<=j){
            int mid = (i+j)/2;

            if(1LL*mid*mid==x){     // 1LL makes whole expression long long
                return mid;
            }
            else if(1LL*mid*mid>x){
                j = mid-1;
            }
            else{
                i = mid+1;
            }
        }
        return i-1;
    }
};