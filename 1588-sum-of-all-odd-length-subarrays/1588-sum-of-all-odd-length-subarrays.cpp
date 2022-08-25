class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        for(int i=0;i<n;i+=2){
            for(int j=0;j<n;j++)
            {
                if(j+i < n)
                {
                    for(int k=0;k<=i;k++){
                        total += arr[(j+k)];
                    }
                }            }
        }
        return total;
    }
};