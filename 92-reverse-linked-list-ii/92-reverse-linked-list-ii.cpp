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
    ListNode* reverseBetween(ListNode* head, int L, int R) {
         ListNode*dummy=new ListNode(),*prev=dummy,*left=head,*right=head,*forw=head->next;
        dummy->next=head;//we have declared dummy variable and initialize its next to head
		
        int dif=(R-L);//we have stored the difference between R and L
        while(--L){//we are traversing to the left node 
            prev=left;
            left=forw;
            right=forw;
            forw=forw->next;
        }
        
        while(dif--){//after we reach the left node we will start reversing the linked list
            ListNode*temp=forw->next;
            forw->next=right;
            right=forw;
            forw=temp;
        }
        prev->next=right;
        left->next=forw;
        return dummy->next;
    }
};