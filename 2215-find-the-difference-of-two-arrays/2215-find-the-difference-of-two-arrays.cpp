class Solution {
public:
    void remove(std::vector<int> &v)
{
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it) {
        end = std::remove(it + 1, end, *it);
    }
 
    v.erase(end, v.end());
}
    
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans;
        vector<int>ans1;
        vector<int>ans2;
        remove(nums1);// remove dubalicte element
        remove(nums2);
        
        for(int i=0;i<nums1.size();i++)
        {
            int a=0;
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                {
                    a++;
                }
            }
            if(a==0)
                ans1.push_back(nums1[i]);

        }
        
         for(int i=0;i<nums2.size();i++)
        {
            int a=0;
            for(int j=0;j<nums1.size();j++)
            {
                if(nums2[i]==nums1[j])
                {
                    a++;
                }
            }
            if(a==0)
                ans2.push_back(nums2[i]);

        }
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
        
    }
};