// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> permute(vector<vector<int>> &arr, int n);


int main() {
    
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> arr(n);
        
        for(int i=0;i<n;i++)
        {
            int a, b;
            cin>> a>> b;
            arr[i].push_back(a);
            arr[i].push_back(b);
        }
        
        vector<int> ans;
        ans = permute(arr, n);
        for(int i=0;i<n;i++)
            cout << ans[i] << "\n";
        
    }
    
	return 0;
}// } Driver Code Ends

bool cmp(const vector<int>& v1, const vector<int>& v2)
{
    if(v1[0] == v2[0]) return v1[1] < v2[1];
    return v1[0] < v2[0];
}
vector<int> permute(vector<vector<int>> &arr, int n)
{
    
    // Complete the function
    vector<int> res;
    for(int i=0;i<arr.size();i++)
    {
        arr[i][0] += arr[i][1];
        arr[i][1] = i+1;
        
    }
    sort(arr.begin(),arr.end(),cmp);
    
    for(auto vec: arr)
    {
        res.push_back(vec[1]);
    }
    return res;
    
}