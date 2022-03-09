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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL or head->next == NULL)
        {
            return head;
        }
        ListNode* temp = head;
        ListNode* prev = new ListNode(-2);
        ListNode* head1 = prev;
        prev->next = head;
        int find = head->val;
        while(temp != NULL)
        {
            if(temp != NULL and temp->next != NULL and temp->val == temp->next->val){
                while(temp != NULL and temp->next != NULL and temp->val == temp->next->val){
                    temp = temp->next;
                }
                prev->next = temp->next;
                temp = prev->next;
            }
            else{
                prev = prev->next;
                temp = temp->next;
                
            }
        }
        return head1->next;
        }
    
};