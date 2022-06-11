// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
        void nullPoints(int n, double magnets[], double getAnswer[])
    {
        // Your code goes here   
        for(int i = 0; i < n - 1; i++){
            double low = magnets[i];
            double high = magnets[i + 1];
            double mid = low;
            while(low < high){
                mid = low + (high - low)/2;
                double left = 0.00;
                double right = 0.00;
                for(int j = 0; j < n; j++){
                    if(j <= i){
                        left += (double)1/(mid - magnets[j]);
                    }
                    else{
                        right += (double)1/(magnets[j] - mid);
                    }
                }
                if(abs(left - right) < 0.000001){
                    break;
                }
                else if(left < right){
                    high = mid;
                }
                else{
                    low = mid;
                }
            }
            getAnswer[i] = mid;
        }
        return;
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
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends