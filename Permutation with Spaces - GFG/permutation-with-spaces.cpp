// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
     void helper(string str,int ind,string output,vector<string> &ans){
       if(ind == str.length()){
           ans.push_back(output);
           return;
       }
       
       char ch = str[ind];
       if(ind < str.length()-1){
           output += ch;
           output += ' ';
           helper(str,ind+1,output,ans);
           output.pop_back();
           helper(str,ind+1,output,ans);
       }
       else{
           output += ch;
           helper(str,ind+1,output,ans);
       }
   }
    vector<string> permutation(string S){
        // Code Here
        vector<string> ans;
       string output;
       helper(S,0,output,ans);
       
       return (ans);
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends