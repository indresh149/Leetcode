class Solution {
public:
    int minimumSum(int num) {
        vector<int> v;
        while(num != 0)
        {
            int digit = num%10;
            v.push_back(digit);
            num=num/10;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i];
        }
        
        int res1= (v[2]+v[3])%10;
        int rem=(v[2]+v[3]);
        int res2=0;
        if(rem > 9)
        {
             res2=(v[0]+v[1]+1)*10;
        }
        else
        {
             res2=(v[0]+v[1])*10;
        }
        //int res2=(v[0]+v[1])*10;
        return res1+res2;
    }
};