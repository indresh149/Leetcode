class Solution {
public:
    int reverse(int x) {
        long rev=0, t=x;
        bool isNeg=0;
        if(t<0) isNeg=1, t=-t;
        while(t) {
            rev=(rev*10)+(t%10);
            if(rev>INT_MAX) return 0;
            t/=10;
        }
        if(isNeg) {
            rev=-rev;
            if(rev<INT_MIN) return 0;
        }
        return rev;
    }
};