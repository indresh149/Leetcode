// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void prime(int N,vector<int> &v){
        bool p[N+1];
        memset(p,true,sizeof(p));
        for(int i=2;i*i<=N;i++){
            if(p[i] == true){
                for(int j = i*i;j<= N;j+=i){
                    p[j] = false;
                }
            }
        }
        for(int i = 2;i<=N;i++){
            if(p[i])
            {
                v.push_back(i);
            }
        }
    }
    vector<int> primeDivision(int N){
        // code here
        vector<int> res(2,0);
        vector<int> v;
        prime(N,v);
        map<int,int> mp;
        for(auto i:v)
        {
            mp[i]++;
        }
        for(int i=0;i<v.size();i++)
        {
            int d = v[i];
            int diff = N-d;
            if(mp[diff] == 1){
                res[0]=d;
                res[1]=diff;
                break;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}  // } Driver Code Ends