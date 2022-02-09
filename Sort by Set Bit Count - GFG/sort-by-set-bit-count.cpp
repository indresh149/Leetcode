// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    static int countBits(int a)
    {
        int count = 0;
        while(a)
        {
            if(a & 1)
               count+=1;
          a= a>>1;
        }
        return count;
    }
        void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        vector<vector<int>> count(32);
        int setbitcount = 0;
        for(int i=0;i<n;i++)
        {
            setbitcount = countBits(arr[i]);
            count[setbitcount].push_back(arr[i]);
        }
        int j=0;
        for(int i=31;i>=0;i--)
        {
            vector<int> v1 = count[i];
            for(int i=0;i<v1.size();i++)
            {
                arr[j++] = v1[i];
            }
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends