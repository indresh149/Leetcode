class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx=0; //global maxima
        int m=0;  //current sum
        for(int i=0;i<gain.size();i++){
            m=m+gain[i];
            mx=max(mx,m);
        }
        return mx;
    }
};