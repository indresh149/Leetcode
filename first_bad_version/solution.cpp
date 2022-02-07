// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int long high=n,low=1,mid;
while(low<=high)
{
mid=(low+high)/2;

        if(isBadVersion(mid)==0)
        {
            low=mid+1;
        }
        else if(isBadVersion(mid)==1)
        {
            if(isBadVersion(mid-1)==0)
                return mid;
			
                
                else
                {
                    high=mid-1;
                }
        }
    }
    return 0;
    }
};