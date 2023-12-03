class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
      int t=0;
      int i;
        for(i=0;i<points.size()-1;i++)
        {
            t=t+max(abs(points[i+1][0]-points[i][0]), abs(points[i+1][1]-points[i][1]));
        }
        return t;
        
    }
};