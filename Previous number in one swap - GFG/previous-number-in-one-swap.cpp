// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string previousNumber(string s){
        // code here 
        int ind1 = -1, ind2 = -1;
        int temp = INT_MIN;
        for(int i = s.length()-2; i >= 0; i--) {
            if(s[i] > s[i+1]){
                ind1 = i;
                break;
            }
        }
        
        if(ind1 == -1) return "-1";
        
        int i = s.length()-1;
        
        while(i > ind1){
            if(s[i] < s[ind1]){
                while(s[i] == s[i-1]){
                    i--;
                }
                ind2 = i;
                break;
            }
            i--;
        }
        
        if(ind2 == -1) return "-1";
        
        swap(s[ind1],s[ind2]);
        
        if(s[0] == '0') return "-1";
        
        return s;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.previousNumber(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends