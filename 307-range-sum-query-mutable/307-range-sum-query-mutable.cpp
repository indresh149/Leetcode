/*
    The idea here is to build a segment tree. Each node stores the left and right
    endpoint of an interval and the sum of that interval. All of the leaves will store
    elements of the array and each internal node will store sum of leaves under it.
    Creating the tree takes O(n) time. Query and updates are both O(log n).
*/

//Segment tree node
class NumArray {
    private:
    int n;
    vector<int> seg;
    
    int build(const vector<int> &nums, int left, int right, int node){
        int middle;
        int leftSum, rightSum;
        
        //Base case
        if(left ==  right) return seg[node] = nums[left];
        
        middle = (left + right)/2;
        
        //recursively build the Segment tree
        leftSum = build(nums,left,middle,2*node+1);
        rightSum = build(nums,middle+1,right,2*node+2);
        
        //Total stores the sum of all leaves under root
        //i.e. those elements lying between (start, end)
        return seg[node] = leftSum + rightSum;
    }
    
    int sumRange(int left, int right, int ss, int se, int  node){
        int leftSum, rightSum;
        int middle;
        
        //If the range exactly matches the root, we already have the sum
        if(right < ss || left > se) return 0;
        if(left <= ss && se <= right) return seg[node];
        
        middle = (ss + se)/2;
        leftSum = sumRange(left,right,ss,middle,2*node+1);
        rightSum = sumRange(left,right,middle+1,se,2*node+2);
        
        return leftSum + rightSum;
    }
    
    int update(int index,int newValue,int ss, int se, int node){
        int leftSum,rightSum;
        int middle;
        
        //Base case. The actual value will be updated in a leaf.
        //The total is then propogated upwards
        if(index < ss || index > se) return seg[node];
        if(ss == se) return seg[node] = newValue;
        
        middle = (ss+se)/2;
        leftSum = update(index, newValue,ss,middle,2*node+1);
        rightSum = update(index,newValue,middle+1,se,2*node+2);
        
        return seg[node] = leftSum + rightSum;
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4*n);
        build(nums,0,n-1,0);
    }
    
    void update(int index, int val) {
        update(index,val,0,n-1,0);
    }
    
    int sumRange(int left, int right) {
        return sumRange(left, right, 0, n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */