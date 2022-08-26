class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int x=pow(10,9);
        map<int,vector<int>> mp;
        
        for(int i=1;i<=x;i=i*2){
            int k=i;
            vector<int> v(10,0);
            while(k){
                int r=k%10;
                v[r]++;
                k=k/10;
            }
            mp[i]=v;
        }
        
        vector<int> countOfDigitsInN(10,0);
        
        while(n){
            int r=n%10;
            countOfDigitsInN[r]++;
            n=n/10;
        }
        
        for(int i=1;i<=x;i=i*2){
            
            vector<int> t=mp[i];
            bool flag=0;
            for(int j=0;j<=9;j++){
                if(t[j]!=countOfDigitsInN[j]){
                    flag=1;
                }
            }
            if(flag==0){
                return 1;
            }
        }
        
        return 0;
    }
};