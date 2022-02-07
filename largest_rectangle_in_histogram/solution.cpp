class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
         stack<int> s;
        int max_area=0;
        int tp;
        int area_with_top;
        int n= heights.size();
        
        int i=0;
        while(i<n)
        {
            if(s.empty() || heights[s.top()]<= heights[i] )
            {
                s.push(i++);
            }
            else
            {
                tp=s.top();
                s.pop();
                area_with_top=heights[tp]*(s.empty() ? i:i-s.top()-1);
                if(max_area<area_with_top)
                {
                    max_area=area_with_top;
                }
            }
        }
        
        while(s.empty()==false)
        {
            tp=s.top();
            s.pop();
            area_with_top=heights[tp]*(s.empty() ? i:i-s.top()-1);
            
            if(max_area<area_with_top)
                {
                    max_area=area_with_top;
                }
        }
        return max_area;
    }
};