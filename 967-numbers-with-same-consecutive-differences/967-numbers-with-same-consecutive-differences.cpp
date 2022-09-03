class Solution {
    void dfs(int num,int N,int k,vector<int>& result){
        if(N == 0){
            result.push_back(num);
            return;
        }
        int last_digit = num%10;
        if(last_digit >= k) dfs(num*10 + last_digit - k, N-1,k,result);
        if(k > 0 && last_digit + k < 10) dfs(num*10 + last_digit + k,N-1,k,result);
    }
public:
    vector<int> numsSameConsecDiff(int N, int k) {
        vector<int> result;
        if(N == 1) result.push_back(0);
        for(int d = 1;d < 10;d++){
            dfs(d,N-1,k,result);
        }
        return result;
    }
};