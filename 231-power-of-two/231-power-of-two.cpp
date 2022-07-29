class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;
        while( n!= 1){
            // Checking if n is odd
            if(n & 1){
                return false;
            }
            // Dividing n by 2
            n = n >> 1;
        }
        return true;
    }
};