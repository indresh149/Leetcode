class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 

{
    sort(piles.begin(),piles.end());
    
    int n=piles.size(),start=1,end=piles[n-1];
    
    while (start<end) 
    {
        int mid = (start + end) / 2, count = 0;
        
        for (int i=0;i<n;i++)
        {
            count+=(piles[i]+mid-1)/mid;
        }

        if (count>h)
            start = mid + 1;
        else
            end = mid;
    }
    
    return start;
}
};