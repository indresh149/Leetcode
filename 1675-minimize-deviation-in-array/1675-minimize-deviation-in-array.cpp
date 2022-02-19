class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int res = INT_MAX, minn= INT_MAX;
        priority_queue<int> p;
        for(auto n:nums)
        {
            n=n%2 ? n*2 : n;
            p.push(n);
            minn = min(minn,n);
        }
        while(p.top()%2 == 0){
            res = min(res,p.top() - minn);
            minn = min(minn,p.top()/2);
            p.push(p.top()/2);
            p.pop();
        }
        return min(res,p.top() - minn);
    }
};