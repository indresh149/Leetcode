class Solution {
public:
    int xorOperation(int n, int start) {
        int p =0;
        int i=0;
        int res =0;
        while(i<n)
        {
            
            p = start + (2*i);
            res = res^p;
            //cout<<p<<"A"<<res<<endl;
            i++;
        }
     return res;   
    }
};