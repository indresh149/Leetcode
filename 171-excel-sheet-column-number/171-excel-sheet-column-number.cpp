class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        int n= columnTitle.size();
        if(n == 1)
        {
            return ((columnTitle[0] - 'A')+1);
        }
        int j=0;
        for(int i=n-1;i>=0;i--)
        {
            ans=(((columnTitle[i]-'A')+1)*pow(26,j))+ans;
            j++;
        }
        return ans;
    }
};