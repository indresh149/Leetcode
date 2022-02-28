// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    double slope(pair<int, int> a, pair<int , int> b){
        if(b.first - a.first == 0) return 1510;
        else
         return (b.second - a.second)/ (double)(b.first - a.first);
    }
    int mostBalloons(int N, pair<int, int> arr[]) {
        // Code here
        int ans =0;
        unordered_map<double,int> cnt;
        for(int i=0;i<N;i++){
            cnt.clear();
            int dup = 1;
            for(int j=i+1;j<N;j++){
                if(arr[i] == arr[j]) 
                dup++;
                
                else
                cnt[slope(arr[i],arr[j])]++;
            }
        ans = max(ans,dup);
        for(auto p: cnt)
         ans = max(ans,p.second + dup);
    }
    return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        pair<int, int> arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> arr[i].second;
        }
        Solution ob;
        cout << ob.mostBalloons(N, arr) << endl;
    }
}  // } Driver Code Ends