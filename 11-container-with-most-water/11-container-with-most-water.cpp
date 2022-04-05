class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxi = 0;
        while(l < r)
        {
            int w = r - l;
            int h = min(height[l],height[r]);
        
        int area = h*w;
        maxi = max(maxi,area);
        if(height[l] < height[r])
        {
            l++;
        }
        else if(height[r] < height[l])
        {
            r--;
        }
        else
        {
            l++;
            r--;
        }
        }
        return maxi;
    }
};