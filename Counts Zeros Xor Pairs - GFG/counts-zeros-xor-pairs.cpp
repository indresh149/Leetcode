// { Driver Code Starts
// C++ program to find number 
// of pairs in an array such
// that their XOR is 0
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the
// count
long long int calculate(int a[], int n);

// Driver Code
int main()
{

	int t;
	cin>>t;
	while(t--)
	{
	  int n;
	  cin>>n;
	  int arr[n+1];
	  for( int i=0;i<n;i++)
	        cin>>arr[i];
	    cout << calculate(arr, n)<<endl;
        
	}
	return 0;
}

// } Driver Code Ends


long long int calculate(int a[], int n)
{
    // Complete the function
    // 1. Sorting the array
    sort(a, a+n);
    long long cnt, ans = 0;
    
    // 2. creating 2 pointers for sliding window
    int i=0, j=1;
    while(j < n)
    {
        // we are expanding the window whenever
        // we see repeated elements
        while(a[j] == a[i])
            j++;
            
        cnt = j-i; // we calculate no. of repeated elements
        // this is nC2 for every elements
        ans += (cnt * (cnt-1))/2;
        
        // updating the pointers
        i = j;
        j++;
    }
    
    return ans;
}
