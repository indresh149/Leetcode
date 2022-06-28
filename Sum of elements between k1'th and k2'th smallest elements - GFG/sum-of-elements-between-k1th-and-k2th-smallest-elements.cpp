// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long a[], long long n, long long k1, long long k2)
    {
        // Your code goes here
        long long ans = 0;
        sort(a,a+n);
        int m =0, q= 0;
        int s=INT_MIN, cnt =0;
        for(int i=0;i<n;i++){
            if(a[i]>s){
                s = a[i];
                cnt++;
            }
            
            if(cnt==k1){
                m = i;
            }
            if(cnt==k2){
                q=i;
                break;
            }
        }
        for(int i=m+1;i<q;i++){
            ans+=a[i];
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends