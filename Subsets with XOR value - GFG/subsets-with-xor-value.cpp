// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
public:
int count = 0;
    void helper(vector<int> &arr,int N, int key, vector<int> &temp, int currXor) {
        if(N == 0) {
            if(temp.size() == 0) return;
            if(currXor == key) count++;
            return;
        }
        temp.push_back(arr[N-1]);
        helper(arr, N-1, key, temp, currXor ^ arr[N-1]);
        temp.pop_back();
       helper(arr, N-1, key, temp, currXor);
    }
    
    int subsetXOR(vector<int> arr, int N, int K) {
        // code here
        vector<int> temp;
        helper(arr, N, K, temp, 0);
        return count;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}  // } Driver Code Ends