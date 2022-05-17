// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
    {
        // Your code here
        if(low<high){
            int mid = (low+high)/2;
            if(arr[mid] > arr[low] && arr[mid] > arr[high]){
                return minNumber(arr,mid+1,high);
            }
            if(arr[mid] >= arr[low] && arr[mid]<= arr[high]){
                
                
                return arr[low];
            }
              if(arr[low]>arr[mid] and arr[high]>arr[mid]){

            return minNumber(arr,low,mid);
        }
        }
        return min(arr[low],arr[high]);
        
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
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}  // } Driver Code Ends