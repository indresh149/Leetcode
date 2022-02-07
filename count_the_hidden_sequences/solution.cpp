class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long maxx=0,minn=0,sum=0;
        int n=differences.size();
        for(int i=0;i<n;i++)
        {
            sum+=differences[i];
            minn=min(minn,sum);
            maxx=max(maxx,sum);
        }
        
        long res1=upper-maxx;
        long res2=lower-minn;
        
        return (res1-res2+1)>0 ? res1-res2+1:0;
    }
};