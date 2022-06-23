// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	       int m=1000000007;
    long long total=0;
    long long ob=1;
    long long os=1;
    for(int i=2;i<=N;i++){
        long long nb=os%m;
        long long ns=(ob+os)%m;
        ob=nb;
        os=ns;
    }
    total=(ob+os)%m;
    long long res=(total*total)%m;
    return res;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends