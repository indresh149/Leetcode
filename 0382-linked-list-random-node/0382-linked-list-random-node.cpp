/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
 
 vector<int>nums;
    Solution(ListNode* head) {
       nums=getNum(head);
    }
    
    int getRandom() {
        int idx = rand() % nums.size();
        return nums[idx];

      
    }
    vector<int> getNum(ListNode* h){
      vector<int> v;
       while (h != NULL) {
        v.push_back(h->val);
        h = h->next;
           }
        return v;
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */