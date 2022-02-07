class Solution {
public:
    int tribonacci(int n) {
        vector<int> v(n+1,-1);
        return findvp(n,v);
    }
    int findvp(int n, vector<int>&v){
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        if(v[n] != -1) return v[n];
        v[n] = findvp(n-1,v)+findvp(n-2,v)+findvp(n-3,v);
        return v[n];
    
    }
};