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
    ListNode* swapNodes(ListNode* head, int k) {
        k = k-1;
        ListNode* firstN = head;
        while(k > 0)
        {
            firstN = firstN->next;
            k--;
        }
        ListNode* f = firstN;
        ListNode* secondN = head;
        while(f->next != NULL)
        {
            secondN = secondN->next;
            f = f->next;
            
        }
        swap(firstN->val,secondN->val);
        return head;
    }
};