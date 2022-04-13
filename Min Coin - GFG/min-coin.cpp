// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	    int table[amount+1];
	    table[0] = 0;
	    for(int i = 1; i<= amount;i++)
	    {
	        table[i] = INT_MAX;
	    }
	    
	    for(int i = 1; i<= amount; i++)
	    {
	        for(int j=0; j<nums.size() ;j++)
	        {
	            if(nums[j] <= i)
	            {
	                int sub_res = table[i - nums[j]];
	                if(sub_res != INT_MAX && sub_res + 1 < table[i])
	                {
	                    table[i] = sub_res + 1;
	                }
	            }
	        }
	    }
	    if(table[amount] == INT_MAX)
	    {
	        return -1;
	    }
	    return  table[amount];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends