// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// ranges[i][0] is the start of ith range
// ranges[i][1] is the end of ith range

class Solution{
public:
     static bool camp(vector<int> &a,vector<int> &b)
    {
        return a[1] < b[1];
    }

    int check(int ind,vector< vector<int> >& ranges)
    {
        int cnt = ranges[ind][1];
        int count = 1;
        for(int i = ind + 1;i < ranges.size();i++)
        {
            if(ranges[i][0] >= cnt)   
            {
                count++;
                cnt = ranges[i][1];
            }
        }
        // cout << count << endl;
        return count;
    }
    int max_non_overlapping( vector< vector<int> >& ranges )
    {
        // code here
        sort(ranges.begin(),ranges.end(),camp);
        int maxi = INT_MIN;
        maxi = max(maxi,check(0,ranges));
        return maxi;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		vector< vector<int> > v(n,vector<int>(2));
		for(int i=0; i<n; i++)
			cin>> v[i][0] >> v[i][1];
			
        Solution ob;
		cout<< ob.max_non_overlapping(v) << endl;
	}
	return 1;
}

  // } Driver Code Ends